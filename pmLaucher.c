/********************************************
 *                Pac Man                   *
 *   A SQs Project established in 2021/4/29 *
 ********************************************/
/*
 * File: pmLauncher
 * The launcher of the "Pac Man" Program.
 */
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include "global.h"
#include "pmanima.h"
#include "pmdirrt.h"
#include "pmeditor.h"
#include "pmgame.h"
#include "pmhelp.h"
#include "pmminit.h"
#include "pmrank.h"
#include "pmrun.h"
#include "pmsp.h"
//TODO:AI
//TODO:秒退解决
//TODO:等级排行榜设计
// 用户的字符事件响应函数
void CharEventProcess(char ch)
{
	uiGetChar(ch); // GUI字符输入
}
// 用户的键盘事件响应函数
void KeyboardEventProcess(int key, int event)
{
	uiGetKeyboard(key, event); // GUI获取键盘
	if (mapifkey(key, event))
	{
		ifmecc = 1;
		mpedictrl = key;
	}
	if (runifkey(key, event))
	{
		ifmecc = 1;
		runmvctrl = key;
	}
}
// 用户的鼠标事件响应函数
void MouseEventProcess(int x, int y, int button, int event)
{
	uiGetMouse(x, y, button, event); //GUI获取鼠标
	if (launchselecter == MENU_ANIM && event == BUTTON_DOWN)
	{
		launchselecter = MENU_MAIN;
	}
	mouse_x = ScaleXInches(x);
	mouse_y = ScaleXInches(y);
}

void displaunch() //主界面
{
	DisplayClear();
	drawpmMenu();
	DrawEditName();
}

void drawpmMenu() //主界面菜单
{
	SetPenColor("Purple2");
	drawBox(0, 0, winwidth, winheight, 1, "", 's', "Black");
	DrawMenuBackG();
	DrawMenuLable();
	SetPointSize(30);
	if (button(GenUIID(0), winwidth / 5, winheight / 2 - GetFontHeight(), winwidth * 1 / 5, GetFontHeight() * 2, "Start Game"))
	{
		testflag++;
		if (testflag == 1)
		{
			launchselecter = MENU_HELP;
			return;
		}
		Length = Inivation("s");
		launchselecter = MENU_GAME;
	}
	if (button(GenUIID(1), winwidth * 3 / 5, winheight / 2 - GetFontHeight(), winwidth * 1 / 5, GetFontHeight() * 2, "Top 10"))
	{
		launchselecter = MENU_RANK;
	}
	if (button(GenUIID(3), winwidth / 5, winheight / 4, winwidth * 1 / 5, GetFontHeight() * 2, "Help"))
	{
		launchselecter = MENU_HELP;
	}
	if (button(GenUIID(2), winwidth * 3 / 5, winheight / 4, winwidth * 1 / 5, GetFontHeight() * 2, "Exit"))
	{
		exit(0);
	}
	SetPointSize(13);
}

void dispgame() //游戏界面
{
	DrawGamePreview();
	SetPointSize(30);
	if (button(GenUIID(4), winwidth * 0.6, winheight * 0.12, winwidth * 1 / 5, GetFontHeight() * 2, "Back"))
	{
		launchselecter = MENU_ANIM;
	}
	if (button(GenUIID(4), winwidth * 0.6, winheight * 0.22, winwidth * 1 / 5, GetFontHeight() * 2, "Start !"))
	{ //*进入游戏
		printf(" Times: %d \n", testflag);
		energy = 0;
		gameinit();
		launchselecter = MENU_GMAP;
		if (GmSts.skin == Skin_hulk2)
			alittlegg = 1;
	}
	if (button(GenUIID(2), winwidth * 0.6, winheight * 0.32, winwidth * 1 / 5, GetFontHeight() * 2, "Map Editor"))
	{
		launchselecter = 3;
	}
	SetPointSize(13);
}

void disprank() // 排行榜界面
{
	DisplayClear();
	DrawMenuBackG();
	SetPenColor("Black");
	GetRank();
	PrintRank();
	SetPointSize(30);
	if (button(GenUIID(4), winwidth - winwidth * 1 / 5 - 0.2, 0.2, winwidth * 1 / 5, GetFontHeight() * 2, "Back"))
	{
		ifrankgotten = 0;
		launchselecter = MENU_ANIM;
	}
	SetPointSize(13);
}

void dispeditor() //地图编辑器界面
{
	mapedinit();
	mapprint();
	mapchose();
	SetPointSize(30);
	if (button(GenUIID(4), winwidth - winwidth * 1 / 5 - 0.2, 0.2, winwidth * 1 / 5, GetFontHeight() * 2, "Back"))
	{
		mapwrite();
		Length = Inivation("S");
		launchselecter = MENU_GAME;
	}
	SetPointSize(13);
}

void disphelp() //帮助界面
{
	SetPenColor("Purple3");
	drawBox(0, 0, winwidth, winheight, 1, "", 's', "Black");
	ListHelp();
	SetPointSize(30);
	if (button(GenUIID(4), winwidth - winwidth * 1 / 5 - 0.2, 0.2, winwidth * 1 / 5, GetFontHeight() * 2, "Back"))
	{
		launchselecter = MENU_ANIM;
	}
	SetPointSize(13);
}

void disptest() //*测试界面的入口。一般不调用
{
	double w = winwidth, h = winheight;
	int i, j;
	char outtest[20];
	SetPenColor("ZJUred");
	SetPointSize(15);
	DrawAnima();
}

void display() //展示入口
{
	setButtonColors("Purple3", "Purple1", "Purple1", "Purple3", 1);
	DisplayClear();
	switch (launchselecter)
	{
	case MENU_MAIN:
		displaunch();
		break;
	case MENU_GAME:
		dispgame();
		break;
	case MENU_RANK:
		disprank();
		break;
	case MENU_EDIT:
		dispeditor();
		break;
	case MENU_HELP:
		disphelp();
		break;
	case MENU_GMAP:
		disppacman();
		break;
	case MENU_ANIM:
		DrawAnima();
		break;
	case MENU_WORL:
		ForScreen(winorlost);
		break;
	case MENU_TEST:
		disptest();
		break;
	default:
		break;
	}
}

void timedisp(int timeid) // Time Controller
{
	switch (timeid)
	{
	case Time_Anima: //动画控制
		if (animatimer <= 2400)
			animatimer++;
		else
			animatimer = 0;
		if (launchselecter == MENU_ANIM && animatimer > 200)
			launchselecter = 0;
		if (launchselecter == MENU_WORL)
			speed += winheight / 3000.0;
		display();
		break;
	case Time_Loop:
		if (launchselecter == MENU_GMAP)
		{
			if (!ifpause) // 魔鬼复活
			{
				int cni = 0;
				for (cni = 0; cni < 4; cni++)
					if (GmSts.ifghst[cni] == 0)
						if (ghstrenewcnt[cni] <= 6)
							ghstrenewcnt[cni]++;
						else
						{
							GmSts.ifghst[cni] = 1;
							GmSts.ghst[cni] = ghststart;
							ghstrenewcnt[cni] = 0;
						}
			}

			if (GmSts.skin != Skin_hulk2)
				timlopflag = 1;
			timghstflag = 1;
		}
		break;
	case Time_Ghst:
		if (launchselecter == MENU_GMAP)
		{
			if (GmSts.skin == Skin_hulk2)
				timlopflag = 1;
		}
		break;
		break;
	case Time_Newbee:
		if (launchselecter == MENU_GMAP)
			newbeeflag = 1;
		break;
	case Time_Step:
		if (launchselecter == MENU_GMAP)
			if (ifpause == 0)
			{
				if (durstepply < GmSts.plyvelo)
					durstepply += 10;
				else
					durstepply = 0;
				if (durstepght < GmSts.ghtvelo / 10)
					durstepght++;
				else
					durstepght = 0;
			}
		break;
	// case Time_Result:
	// 	speed += winheight / 1000.0;
	// 	break;
	// case Time_Tester:
	// {
	// 	printf(" Times: %d \n", testflag);
	// 	energy = 0;
	// 	gameinit();
	// }
	default:
		break;
	}
}

void InitWindow() //窗口初始化
{
	SetWindowSize(25, 20);
	InitGraphics();
	// SetFont("Consolas");
	SetWindowTitle("Pac Man 吃豆人");
	winwidth = GetWindowWidth();
	winheight = GetWindowHeight();
	launchselecter = MENU_ANIM;
}

void InitMyColor() //颜色初始化
{
	DefineColor("StdBg", 255.0 / 256, 0.0 / 256, 255.0 / 256);	// Standard Background
	DefineColor("Coin1", 247.0 / 256, 211.0 / 256, 88.0 / 256); // Side color of the coin
	DefineColor("Coin2", 247.0 / 256, 254.0 / 256, 46.0 / 256); // Front color of the coin
	DefineColor("Pink", 255.0 / 256, 192.0 / 256, 203.0 / 256); // Pinky
	DefineColor("Azure", 88.0 / 256, 250.0 / 256, 244.0 / 256); // Inky
	DefineColor("ZJUblue", 0.0 / 256, 63.0 / 256, 136.0 / 256); // Qiu Shi Blue
	DefineColor("ZJUred", 176.0 / 256, 31.0 / 256, 36.0 / 256); // Chuang Xin Red
	DefineColor("Pac", 255.0 / 256, 213.0 / 256, 107.0 / 256);
	DefineColor("Purple", 144.0 / 256, 127.0 / 256, 164.0 / 256);
	DefineColor("Forscore", 255.0 / 256, 251.0 / 256, 223.0 / 256);
	DefineColor("Brown", 160.0 / 256, 147.0 / 256, 125.0 / 256);
	DefineColor("Darker", 134.0 / 256, 64.0 / 256, 0.0 / 256);
	DefineColor("Purple1", 68.0 / 256, 10.0 / 256, 103.0 / 256);
	DefineColor("Purple2", 147.0 / 256, 50.0 / 256, 158.0 / 256);
	DefineColor("Purple3", 180.0 / 256, 174.0 / 256, 232.0 / 256);
	DefineColor("Purple4", 190.0 / 256, 129.0 / 256, 247.0 / 256);
	DefineColor("S_blue", 50.0 / 256, 82.0 / 256, 136.0 / 256);
	DefineColor("S_white", 244.0 / 256, 238.0 / 256, 232.0 / 256);
	DefineColor("S_pink", 245.0 / 256, 206.0 / 256, 190.0 / 256);
	DefineColor("S_green", 17.0 / 256, 78.0 / 256, 96.0 / 256);
	DefineColor("Green1", 8.0 / 256, 138.0 / 256, 75.0 / 256);
	DefineColor("Meat", 255.0 / 256, 218.0 / 256, 185.0 / 256);
	DefineColor("c1", 223.0 / 256, 1.0 / 256, 1.0 / 256);
	DefineColor("c2", 223.0 / 256, 58.0 / 256, 1.0 / 256);
	DefineColor("c3", 223.0 / 256, 116.0 / 256, 1.0 / 256);
	DefineColor("c4", 219.0 / 256, 169.0 / 256, 1.0 / 256);
	DefineColor("c5", 215.0 / 256, 223.0 / 256, 1.0 / 256);
	DefineColor("c6", 165.0 / 256, 223.0 / 256, 0.0 / 256);
	DefineColor("c7", 116.0 / 256, 223.0 / 256, 0.0 / 256);
	DefineColor("c8", 58.0 / 256, 223.0 / 256, 0.0 / 256);
	DefineColor("c9", 1.0 / 256, 223.0 / 256, 1.0 / 256);
	DefineColor("c10", 1.0 / 256, 223.0 / 256, 116.0 / 256);
	DefineColor("c11", 1.0 / 256, 223.0 / 256, 215.0 / 256);
	DefineColor("c12", 1.0 / 256, 169.0 / 256, 219.0 / 256);
	DefineColor("c13", 1.0 / 256, 116.0 / 256, 223.0 / 256);
	DefineColor("c14", 1.0 / 256, 58.0 / 256, 223.0 / 256);
}

void ConsoleTest() //测试专用：开启检测控制台
{
	InitConsole();
}

void Main() //主函数，程序的入口
{
	InitWindow();
	InitMyColor();
	////test ENTRANCE
	//*测试专用入口，更改下面内容进行测试
	// ConsoleTest();
	GmSts.skin = Skin_plain;
	// startTimer(Time_Tester, 5000);
	// launchselecter = MENU_RANK;
	//test End
	srand(clock());
	GmSts.plyvelo = 500;
	GmSts.ghtvelo = 500;
	registerTimerEvent(timedisp);
	startTimer(Time_Anima, 40);
	startTimer(Time_Ghst, 250);
	startTimer(Time_Loop, 500);
	startTimer(Time_Step, 10);
	registerCharEvent(CharEventProcess);		 // 字符
	registerKeyboardEvent(KeyboardEventProcess); // 键盘
	registerMouseEvent(MouseEventProcess);		 // 鼠标
}
