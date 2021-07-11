// Demon Version
// By scitbb
#include "pmgame.h"
#include "pmrank.h"
#include "pmminit.h"
#include "graphics.h"
#include "global.h"
#include "mpinclude.h"
#include "pmanima.h"
#include <stdlib.h>
#include <time.h>
int durstepply = 0;
int durstepght = 0;
static ID *formerposition[4];
bool ifpause = 0;
bool ifgminit = 0;
stateofgame GmSts; //Game Settings and States
double tmpsts;
int energy = 0;
ID *ghststart;
int ghstrenewcnt[4];

void gmstinit() //��ͼ���س�ʼ��
{
	if (GmSts.map != NULL)
		free(GmSts.map);
	printf("��ͼ���س�ʼ��\n");
	if (GmSts.lvl == 0)
		GmSts.lvl = 1;
	GmSts.plyrd = Dir_down;
	GmSts.Lens = Length;
	GmSts.score = 0;
	GmSts.ifghst[0] = 0;
	GmSts.ifghst[1] = 0;
	GmSts.ifghst[2] = 0;
	GmSts.ifghst[3] = 0;
	GmSts.map = (int *)calloc(GmSts.Lens * GmSts.Lens, sizeof(int));
	int i, j, k, *workp = GmSts.map;
	for (i = 0; i < GmSts.Lens; i++)
		for (j = 0; j < GmSts.Lens; j++)
		{
			*(workp + i * Length + j) = Map[i][j];
			if (Map[i][j] == Mp_start)
				GmSts.player = SpLocateVer(i, j);
			if (Map[i][j] == Mp_Ghst)
				for (k = 0; k < 4; k++)
					GmSts.ghst[k] = SpLocateVer(i, j);
		}
	if (GmSts.player == NULL)
		GmSts.player = verhead;
	if (GmSts.ghst[0] == NULL)
		for (i = 0; i < 4; i++)
			GmSts.ghst[i] = (verhead + noofver - 1);
	ghststart = GmSts.ghst[0];
	//���Ӷ���
	SpShortPath(GmSts.player);
	for (i = 0; i < noofver; i++)
		if (spdis[i] != MAXDIST) // �ܵ��������λ�ö����϶���
		{
			*(workp + (verhead + i)->x * Length + (verhead + i)->y) = Mp_pea;
		}
	printf("Pea Added Done\n");
	SpDjReinit();
}

void gameinit()
{
	Length = Inivation("S");
	SpReinit();
	SpCreateGraph();
	gmstinit();
	printf("Gameinit Done\n");
}

void drawmap()
{
	SetPointSize(30);
	if (button(GenUIID(4), winwidth - winwidth * 2 / 5 - 0.2, 0.2, winwidth * 1 / 5, GetFontHeight() * 2, ifpause ? "Resume" : "Pause"))
	{
		ifpause = !ifpause;
	}
	if (button(GenUIID(4), winwidth - winwidth * 1 / 5 - 0.2, 0.2, winwidth * 1 / 5, GetFontHeight() * 2, "Back"))
	{
		ifgminit = 0;
		free(GmSts.map);
		launchselecter = MENU_GAME;
	}
	SetPointSize(13);
	drawlvl(winwidth * 3 / 12 - winwidth / 5, winheight - 1.5, winwidth / 5, GetFontHeight() * 1.5);
	drawscore();
	dmapname();
}

static void drawmvghst(double cx, double cy, double size, int type, double dx, double dy, bool mv)
{
	void (*drawgst)(double, double, double, Dir);
	switch (type)
	{
	case tg_Blinky:
		drawgst = DrawBlinky;
		break;
	case tg_Pinky:
		drawgst = DrawPinky;
		break;
	case tg_Inky:
		drawgst = DrawInky;
		break;
	case tg_Clyde:
		drawgst = DrawClyde;
		break;
	default:
		break;
	}
	if (mv != 1)
		switch (GmSts.ghstd[type])
		{
		case Dir_up:
			drawgst(cx, cy - (1 - tmpsts) * dy, size, GmSts.ghstd[type]);
			break;
		case Dir_down:
			drawgst(cx, cy + (1 - tmpsts) * dy, size, GmSts.ghstd[type]);
			break;
		case Dir_left:
			drawgst(cx + (1 - tmpsts) * dx, cy, size, GmSts.ghstd[type]);
			break;
		case Dir_right:
			drawgst(cx - (1 - tmpsts) * dy, cy, size, GmSts.ghstd[type]);
			break;

		default:
			break;
		}
	else
		switch (GmSts.ghstd[type])
		{
		case Dir_up:
			drawgst(cx, cy, size, GmSts.ghstd[type]);
			break;
		case Dir_down:
			drawgst(cx, cy, size, GmSts.ghstd[type]);
			break;
		case Dir_left:
			drawgst(cx, cy, size, GmSts.ghstd[type]);
			break;
		case Dir_right:
			drawgst(cx, cy, size, GmSts.ghstd[type]);
			break;

		default:
			break;
		}
}

void loadsrc()
{
	// ����
	double startx = winwidth / 12, starty = winheight / 12;
	double dx = winwidth * 10 / (12 * Length), dy = winheight * 10 / (12 * Length);
	SetPenColor("GREEN");
	int cnti, cntj;
	double ridofcoin = dx;
	if (dx > dy)
		ridofcoin = dy;
	for (cnti = 0; cnti < Length; cnti++)
		for (cntj = 0; cntj < Length; cntj++)
		{
			if (*(GmSts.map + cnti * Length + cntj) != 1)
				SetPenColor("Black");
			else
				SetPenColor("ZJUblue");
			drawBox(startx + cntj * dx, starty + cnti * dy, dx, dy, 1, "", 's', "White");
			if (*(GmSts.map + cnti * Length + cntj) == Mp_pea)
				DrawCoin(startx + cntj * dx + dx / 2, starty + cnti * dy + dy / 2, ridofcoin / 5);
		}
	//
	double tmstep;
	//�Զ���
	int eaterx, eatery;
	eatery = GmSts.player->x;
	eaterx = GmSts.player->y;
	tmstep = (durstepply * 3.2) / (GmSts.plyvelo * 1.0);
	tmpsts = tmstep;
	DrawEater(startx + eaterx * dx + dx / 2, starty + eatery * dy + dy / 2, ridofcoin * 2 / 5, GmSts.plyrd, "Black", GmSts.skin);
	//��
	int ghstno = 0, ghstx, ghsty;
	for (ghstno = 0; ghstno < 4; ghstno++)
	{
		if (!GmSts.ifghst[ghstno])
			continue;
		ghsty = GmSts.ghst[ghstno]->x;
		ghstx = GmSts.ghst[ghstno]->y;
		drawmvghst(startx + ghstx * dx + dx / 2, starty + ghsty * dy + dy / 2, ridofcoin, ghstno, dx, dy, (formerposition[ghstno]->x == GmSts.ghst[ghstno]->x && formerposition[ghstno]->y == GmSts.ghst[ghstno]->y));
	}
	SetPenColor("Purple2");
	drawBox(0, 0, winwidth / 12, winheight, 1, "", '1', "Black");
	drawBox(0, 0, winwidth, winheight / 12, 1, "", 's', "Black");
	drawBox(winwidth * 11 / 12, 0, winwidth / 12, winheight, 1, "", 's', "Black");
	drawBox(0, winheight * 11 / 12, winwidth, winheight / 12, 1, "", 's', "Black");
	if (GmSts.skin != Skin_plain)
		drawEnerbar();
	drawGstBar();
}

void drawscore() // ���ƻ�����
{
	char scorestring[10];
	sprintf(scorestring, "Score: %d/%d", GmSts.score, GmSts.scoregoal);
	SetPointSize(30);
	SetPenColor("Black");
	drawBox(winwidth * 9 / 12, winheight - 1.5, winwidth * 1 / 5, GetFontHeight() * 1.5, 0, "", 's', "Black");
	SetPenColor("Forscore"); //�Ƿ���
	drawBox(winwidth * 9 / 12, winheight - 1.5, winwidth * 1 / 5, GetFontHeight() * 1.5, 1, scorestring, 's', "Black");
}

void drawEnerbar()
{
	SetPenColor("Purple3");
	drawRectangle(winwidth / 48, winheight * 1 / 12, winwidth / 24, winheight / 2, 1);
	SetPenColor("Purple2");
	drawRectangle(winwidth / 48 + 0.1, winheight * 1 / 12 + 0.1, winwidth / 24 - 0.2, winheight / 2 - 0.2, 1);
	int i, maxofener = ((GmSts.skin == Skin_flash) ? 15 : 20);
	double dy = winheight / (2 * maxofener), ystart = winheight / 12;
	SetPenColor("Purple3");
	int colorctrl;
	char rainbowcolor[6];
	for (i = 0; i < energy; i++)
	{
		colorctrl = 14 * i / maxofener + 1;
		sprintf(rainbowcolor, "c%d", (colorctrl <= 14) ? colorctrl : 14);
		SetPenColor(rainbowcolor);
		drawRectangle(winwidth / 48 + 0.2, ystart + dy * i + 0.2, winwidth / 24 - 0.4, dy - 0.2, 1);
	}
	SetPenColor("Red");
	if (energy == maxofener && BlinkCtrlor(25, 0.8))
		for (i = 0; i < energy; i++)
		{
			drawRectangle(winwidth / 48 + 0.2, ystart + dy * i + 0.2, winwidth / 24 - 0.4, dy - 0.2, 1);
		}
}

static void drawGstBar()
{
	char tmp[5];
	double dy = winheight / 15, ystart = winheight * 7 / 12;
	if (GmSts.ifghst[0])
		DrawBlinky(winwidth / 24, ystart + dy / 2, winwidth / 40, Dir_right);
	else
	{
		DrawECircle(winwidth / 24, ystart + dy / 2, winwidth / 40, winwidth / 40, "ZJUred", 1);
		MovePen(winwidth / 24 - 0.1, ystart + dy / 2 - 0.1);
		sprintf(tmp, "%d", 7 - ghstrenewcnt[0]);
		SetPenColor("Purple1");
		SetPointSize(30);
		DrawTextString(tmp);
	}
	if (GmSts.ifghst[1])
		DrawPinky(winwidth / 24, ystart + dy * 3 / 2, winwidth / 40, Dir_right);
	else
	{
		DrawECircle(winwidth / 24, ystart + dy * 3 / 2, winwidth / 40, winwidth / 40, "Pink", 1);
		sprintf(tmp, "%d", 7 - ghstrenewcnt[1]);
		MovePen(winwidth / 24 - 0.1, ystart + dy * 3 / 2 - 0.1);
		SetPenColor("Purple1");
		SetPointSize(30);
		DrawTextString(tmp);
	}
	if (GmSts.ifghst[2])
		DrawInky(winwidth / 24, ystart + dy * 5 / 2, winwidth / 40, Dir_right);
	else
	{
		DrawECircle(winwidth / 24, ystart + dy * 5 / 2, winwidth / 40, winwidth / 40, "Azure", 1);
		sprintf(tmp, "%d", 7 - ghstrenewcnt[2]);
		MovePen(winwidth / 24 - 0.1, ystart + dy * 5 / 2 - 0.1);
		SetPointSize(30);
		SetPenColor("Purple1");
		DrawTextString(tmp);
	}
	if (GmSts.ifghst[3])
		DrawClyde(winwidth / 24, ystart + dy * 7 / 2, winwidth / 40, Dir_right);
	else
	{
		DrawECircle(winwidth / 24, ystart + dy * 7 / 2, winwidth / 40, winwidth / 40, "Orange", 1);
		sprintf(tmp, "%d", 7 - ghstrenewcnt[3]);
		MovePen(winwidth / 24 - 0.1, ystart + dy * 7 / 2 - 0.1);
		SetPenColor("Purple1");
		SetPointSize(30);
		DrawTextString(tmp);
	}
	//
	SetPenColor("Purple3");
	drawRectangle(winwidth / 48 + winwidth * 11 / 12, winheight * 1 / 12, winwidth / 24, winheight / 1.5, 1);
	SetPenColor("Purple2");
	drawRectangle(winwidth / 48 + 0.1 + winwidth * 11 / 12, winheight * 1 / 12 + 0.1, winwidth / 24 - 0.2, winheight / 1.5 - 0.2, 1);
	int i, maxofener = GmSts.scoregoal, colorctrl;
	char rainbowcolor[6];
	double dyy = winheight / (1.5 * GmSts.scoregoal), yystart = winheight / 12;
	SetPenColor("Purple3");
	for (i = 0; i < GmSts.score; i++)
	{
		colorctrl = 14 - 14 * i / GmSts.scoregoal;
		sprintf(rainbowcolor, "c%d", colorctrl);
		SetPenColor(rainbowcolor);
		drawRectangle(winwidth * 45 / 48 + 0.2, yystart + dyy * i, winwidth / 24 - 0.4, dyy - 0.1, 1);
	}
	DrawEater(winwidth * 23 / 24, yystart + dyy * GmSts.score, winwidth / 48, Dir_up, "Purple2", GmSts.skin);
}

void drawlvl(double x, double y, double w, double h) // ���Ƶȼ���
{
	SetPointSize(30);
	char scorestring[10];
	sprintf(scorestring, "Your Level: %d", GmSts.lvl);
	SetPenColor("Forscore"); //�Ƿ���
	drawBox(x, y, w, GetFontHeight() * 1.5, 1, scorestring, 's', "Black");
}

void dmapname() // ���Ƶ�ͼ������
{
	char namer[40], *wkp;
	wkp = namer;
	switch (GmSts.lvl)
	{
	case 0:
	case 1:
		wkp = "Big Riddle";
		break;
	case 2:
		wkp = "Small House";
		break;
	case 3:
		wkp = "Ziggrate";
		break;
	case 4:
		wkp = "Counter Strike";
		break;
	case 5:
		wkp = "Web & Net";
		break;
	case 6:
		wkp = "Web & Net 2.0";
		break;
	case 7:
		wkp = "Last War";
		break;
	default:
		break;
	}
	wkp = mapnames[GmSts.lvl - 1];
	SetPenColor("Purple1");
	SetPointSize(30);
	drawBox(winwidth * 3 / 12, winheight * 11 / 12, winwidth * 6 / 12, winheight / 12, 1, wkp, 's', "Azure");
	SetPointSize(13);
}

void disppacman() // ��Ϸ���е�������
{
	if (formerposition[0] == NULL || timghstflag)
	{
		int i;
		for (i = 0; i < 4; i++)
		{
			formerposition[i] = GmSts.ghst[i];
		}
	}
	if (!ifpause) // ��ͣ�Ļ������ƶ�����
	{
		Changedir(); // ���ĳԶ��˵ķ���
		MoveMan();	 //���ĳԶ���λ��
		int i;
		if (timghstflag)
		{
			if (GmSts.skin == Skin_hulk2)
			{
				MoveGst(0, MvRun);
				MoveGst(1, MvRun);
				MoveGst(2, MvRun);
				MoveGst(3, MvRun);
			}
			else
			{
				if (GmSts.skin == Skin_hulk1 || GmSts.skin == Skin_hulk2)
					MoveGst(0, rand() % 10 ? MvChase : MvWonder);
				else
					MoveGst(0, rand() % 10 <= 7 ? MvChase : MvWonder);
				MoveGst(1, MvAmbush);
				MoveGst(2, rand() % 10 <= 7 ? MvChase : MvWonder);
				MoveGst(3, Mvpret);
			}
			timghstflag = 0;
		}
		Lost_Win(); // �ж��Ƿ�ʤ��������
	}
	loadsrc(); // ���ص�ͼԪ��
	drawmap(); // ���Ƶ�ͼ
}