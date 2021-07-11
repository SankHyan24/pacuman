// By scitbb
#include "pmhelp.h"
#include "global.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
double speed = 0;
double sum = 0;
int page = 1;
int pagenum = 11;

void ForScreen(int win)
{
	SetPenColor("Red");
	//startTimer(Time_Anima, 50);
	sum += speed;
	SetPenColor("S_white");
	drawRectangle(0, 0, winwidth, winheight, 1);
	SetPenColor("S_blue");
	drawRectangle(winwidth / 10.0, winheight / 10.0, winwidth * 4.0 / 5, winheight * 4.0 / 5, 1);
	SetPenColor("S_green");
	SetPointSize(50);
	drawBox(winwidth * 3.0 / 10.0, winheight - sum, winwidth * 4.0 / 10.0, winheight / 5.0, 1, win ? "Congratulations!" : "YOU  LOSE !", 'c', "White");
	SetPointSize(25);
	SetPenColor("White");
	if (winheight - sum <= winheight / 2.0)
	{
		//cancelTimer(Time_Anima);
		speed = 0;
		sum = winheight / 2.0;
	}
	setButtonColors("S_pink", "S_blue", "S_pink", "S_blue", 1);
	{
		if (button((14), winwidth * 7 / 20.0, winheight * 3.0 / 20.0, winwidth * 6 / 20.0, winwidth / 10.0, "Another attempt"))
		{
			sum = 0;
			Length = Inivation("S");
			launchselecter = MENU_GAME;
		}
	}
	setButtonColors("Blue", "Blue", "Red", "Red", 0);
	DrawBlinky(winwidth * 3 / 20.0, winheight * 3.0 / 20.0, 2.0, Dir_right);
	DrawPinky(winwidth * 5 / 20.0, winheight * 3.0 / 20.0, 2.0, Dir_right);
	DrawInky(winwidth * 17 / 20.0, winheight * 3.0 / 20.0, 2.0, Dir_left);
	DrawClyde(winwidth * 15 / 20.0, winheight * 3.0 / 20.0, 2.0, Dir_left);
	SetPointSize(13);
}

void ListHelp()
{
	char *title[] = {"д��ǰ��", "����˵��", "��Ϸ����", "Ӣ�ۼ��", "Ӣ�ۼ��", "Ӣ�ۼ��", "�����߼�", "��ͼ�༭", "�÷�����", "BUG����", "��Ŀ����"};
	SetPenColor("Purple1");
	drawRectangle(winwidth / 10.0, winheight / 10.0, winwidth * 4.0 / 5, winheight * 4.0 / 5, 1);
	SetPenColor("White");
	SetPointSize(40);
	MovePen(winwidth * 12.0 / 30.0, winheight * 4 / 5.0);
	DrawTextString(title[(page - 1) % pagenum]);
	MovePen(winwidth / 10.0, winheight * 7.7 / 10.0);
	DrawLine(winwidth * 4.0 / 5, 0);
	switch (page % pagenum)
	{
	case 1:
		DrawHelp1();
		break;
	case 2:
		DrawHelp2();
		break;
	case 3:
		DrawHelp3();
		break;
	case 4:
		DrawHelp4();
		break;
	case 5:
		DrawHelp5();
		break;
	case 6:
		DrawHelp6();
		break;
	case 7:
		DrawHelp7();
		break;
	case 8:
		DrawHelp8();
		break;
	case 9:
		DrawHelp9();
		break;
	case 10:
		DrawHelp10();
		break;
	case 0:
		DrawHelp11();
		break;
	}
	SetPointSize(24);
	setButtonColors("Purple2", "White", "Pink", "White", 1);
	if (button(GenUIID(15), winwidth * 15 / 20.0, winheight * 8.0 / 10.0, winwidth * 1.3 / 10.0, 1.0, "��һҳ"))
		page++;
	if (button(GenUIID(15), winwidth * 5 / 20.0 - winwidth * 1.3 / 10.0, winheight * 8.0 / 10.0, winwidth * 1.3 / 10.0, 1.0, "��һҳ"))
		if (page == 0)
			page = pagenum - 1;
		else
			page--;
	setButtonColors("Blue", "Blue", "Red", "Red", 0);
}

void DrawHelp1()
{
	char *content_1[] = {"������ǵ�һ���棬һ��Ҫ��������ܿ���Ŷ����Ȼ����", "�����Ѿ������ˣ�������½�BACK��ť���Ϳ��˳��������档"};
	char *content_2[] = {"������˵������������������PAC MAN�ɣ����"};
	char *content_3[] = {"����������Ϸ�������档�����㴦��help�����ڣ�������", "����Կ�������Ϸ���������淽������ϸ˵����������������", "�ֱ��Ӧ'��ʼ'��'���а�'��'�˳�'�����⣬��������������Ϸ�", "���ı������޸�������֡�ȡ�����������ְɣ�"};
	MovePen(winwidth * 4 / 20.0, winheight / 10.0 + winheight * 4 / 8.0);
	SetPointSize(20);
	DrawTextString(content_1[0]);
	MovePen(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 3.5 / 8.0);
	DrawTextString(content_1[1]);
	MovePen(winwidth * 4 / 20.0, winheight / 10.0 + winheight * 3.0 / 8.0);
	DrawTextString(content_2[0]);
	MovePen(winwidth * 4 / 20.0, winheight / 10.0 + winheight * 2.5 / 8.0);
	DrawTextString(content_3[0]);
	MovePen(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 2.0 / 8.0);
	DrawTextString(content_3[1]);
	MovePen(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 1.5 / 8.0);
	DrawTextString(content_3[2]);
	MovePen(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 1.0 / 8.0);
	DrawTextString(content_3[3]);
}

void DrawHelp2()
{
	char *content_1[] = {"�����ʼ��ť������Ϸ������Ե��'change'��ťѡ��", "�Լ��Ľ�ɫ;�����Ϸ���Ϸ���'select map'ѡ��ؿ����Ρ�"};
	char *content_2[] = {"��Ϸ�Ĳ�������Ϊ��ͨ�������������Ҽ��ı��ƶ�����", "���������ص��ܹ����ռ���ҡ�ע�⣬�ĸ�С���ǲ����ģ�", "����������ǳԵ�������Ҳ���ڲ��ú󸴻"};
	char *content_3[] = {"�˽�����Щ��������Ϣ�������ǽ���������������ɣ�"};
	SetPointSize(20);
	MovePen(winwidth * 4 / 20.0, winheight / 10.0 + winheight * 4 / 8.0);
	DrawTextString(content_1[0]);
	MovePen(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 3.5 / 8.0);
	DrawTextString(content_1[1]);
	MovePen(winwidth * 4 / 20.0, winheight / 10.0 + winheight * 3.0 / 8.0);
	DrawTextString(content_2[0]);
	MovePen(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 2.5 / 8.0);
	DrawTextString(content_2[1]);
	MovePen(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 2.0 / 8.0);
	DrawTextString(content_2[2]);
	MovePen(winwidth * 4 / 20.0, winheight / 10.0 + winheight * 1.5 / 8.0);
	DrawTextString(content_3[0]);
	DrawBlinky(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_right);
	DrawPinky(winwidth * 7 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_left);
	DrawInky(winwidth * 13 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_right);
	DrawClyde(winwidth * 17 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_left);
}

void DrawHelp3()
{
	char *content_1[] = {"�ܾúܾ���ǰ����������ʿ������һ�����صĳǱ�������", "ֻ֪���Ǳ���������ʤ���ı��أ�ȴ��֪�������Ǳ�����ĵ�", "������ֻ�ε���С��������ڳǱ������룬������Щ�������", "ʿ���������������ֻ���ռ����㹻�Ľ�Ҳ��ܽ�������", "�����������ӳ����졣"};
	char *content_2[] = {"�꣡�����ˣ�"};
	SetPointSize(20);
	MovePen(winwidth * 4 / 20.0, winheight / 10.0 + winheight * 4 / 8.0);
	DrawTextString(content_1[0]);
	MovePen(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 3.5 / 8.0);
	DrawTextString(content_1[1]);
	MovePen(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 3.0 / 8.0);
	DrawTextString(content_1[2]);
	MovePen(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 2.5 / 8.0);
	DrawTextString(content_1[3]);
	MovePen(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 2.0 / 8.0);
	DrawTextString(content_1[4]);
	MovePen(winwidth * 4 / 20.0, winheight / 10.0 + winheight * 1.5 / 8.0);
	DrawTextString(content_2[0]);
	DrawBlinky(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_right);
	DrawPinky(winwidth * 7 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_left);
	DrawInky(winwidth * 13 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_right);
	DrawClyde(winwidth * 17 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_left);
}

void DrawHelp4()
{
	char *content_1[] = {"Paku��һ����ͨ�ˡ���û", "��ʲô�س������ӲҪ˵��ʲ", "ô�Ļ����Ǿ��������������㡣", "��ˣ�����Ϸ����ֻ��Ҫ�Թ�", "2/3�Ľ�ҾͿ���˳�������ˡ�"};
	char *content_2[] = {"���ͣ����������ǳɹ���"};
	DrawEater(winwidth * 3.0 / 10.0, winheight * 5.0 / 10, 2.5, Dir_right, "Purple1", 0);
	SetPointSize(20);
	SetPenColor("White");
	MovePen(winwidth / 2.0 + winwidth / 18.0, winheight / 10.0 + winheight * 4 / 8.0);
	DrawTextString(content_1[0]);
	MovePen(winwidth / 2.0, winheight / 10.0 + winheight * 3.5 / 8.0);
	DrawTextString(content_1[1]);
	MovePen(winwidth / 2.0, winheight / 10.0 + winheight * 3.0 / 8.0);
	DrawTextString(content_1[2]);
	MovePen(winwidth / 2.0, winheight / 10.0 + winheight * 2.5 / 8.0);
	DrawTextString(content_1[3]);
	MovePen(winwidth / 2.0, winheight / 10.0 + winheight * 2.0 / 8.0);
	DrawTextString(content_1[4]);
	MovePen(winwidth * 7.0 / 20.0, winheight / 10.0 + winheight * 1.0 / 8.0);
	DrawTextString(content_2[0]);
}

void DrawHelp5()
{
	DrawEater(winwidth * 3.0 / 10.0, winheight * 5.0 / 10, 2.5, Dir_right, "Purple1", 1);
	char *content_1[] = {"��³˹���ɲ�ʿ����������", "��������ѧ�ң���һ�������б�", "�Լ��������٤��ը���ķ�����", "�������䣬���������䣬����", "ÿ�����������������ٵ�ʱ��", "�ͻ�����Ϊ�ƿ˵���ɫ���"};
	char *content_2[] = {"��Ϸ�е�����дݻ�һ�е�Ǳ�ܣ���Ҫ�ռ���һ�����", "��(�������������������֮����԰����ո���������̾��ˡ�", "��ʱ��ħ������Ϊ�������"};
	SetPointSize(20);
	SetPenColor("White");
	MovePen(winwidth / 2.0 + winwidth / 18.0, winheight / 10.0 + winheight * 5.0 / 8.0);
	DrawTextString(content_1[0]);
	MovePen(winwidth / 2.0, winheight / 10.0 + winheight * 4.5 / 8.0);
	DrawTextString(content_1[1]);
	MovePen(winwidth / 2.0, winheight / 10.0 + winheight * 4.0 / 8.0);
	DrawTextString(content_1[2]);
	MovePen(winwidth / 2.0, winheight / 10.0 + winheight * 3.5 / 8.0);
	DrawTextString(content_1[3]);
	MovePen(winwidth / 2.0, winheight / 10.0 + winheight * 3.0 / 8.0);
	DrawTextString(content_1[4]);
	MovePen(winwidth / 2.0, winheight / 10.0 + winheight * 2.5 / 8.0);
	DrawTextString(content_1[5]);
	MovePen(winwidth * 4.0 / 20.0, winheight / 10.0 + winheight * 1.5 / 8.0);
	DrawTextString(content_2[0]);
	MovePen(winwidth * 3.0 / 20.0, winheight / 10.0 + winheight * 1.0 / 8.0);
	DrawTextString(content_2[1]);
	MovePen(winwidth * 3.0 / 20.0, winheight / 10.0 + winheight * 0.5 / 8.0);
	DrawTextString(content_2[2]);
}

void DrawHelp6()
{
	DrawEater(winwidth * 3.0 / 10.0, winheight * 5.0 / 10, 2.5, Dir_right, "Purple1", 3);
	char *content_1[] = {"��£�Neo��������Ϊ����˹", "������ɭ��Thomas A. Anderson����", "��Ϊ�ڿ͵۹�ĸ��Matrix�еľ���", "����Ϊ�˴ٳ��˻���������֮��", "�ĺ�ƽ����ĸ���������"};
	char *content_2[] = {"��Ϸ�е������˲���ƶ�����������Ҫ���ռ���һ�����", "�����������������������֮����԰����ո����˲���ƶ���ǰ", "�����ʮ��λ�ã���ʱ��ħ��Ҳ�޷������㡣"};
	SetPointSize(20);
	SetPenColor("White");
	MovePen(winwidth / 2.0 + winwidth / 18.0, winheight / 10.0 + winheight * 4.5 / 8.0);
	DrawTextString(content_1[0]);
	MovePen(winwidth / 2.0, winheight / 10.0 + winheight * 4.0 / 8.0);
	DrawTextString(content_1[1]);
	MovePen(winwidth / 2.0, winheight / 10.0 + winheight * 3.5 / 8.0);
	DrawTextString(content_1[2]);
	MovePen(winwidth / 2.0, winheight / 10.0 + winheight * 3.0 / 8.0);
	DrawTextString(content_1[3]);
	MovePen(winwidth / 2.0, winheight / 10.0 + winheight * 2.5 / 8.0);
	DrawTextString(content_1[4]);
	MovePen(winwidth * 4.0 / 20.0, winheight / 10.0 + winheight * 1.5 / 8.0);
	DrawTextString(content_2[0]);
	MovePen(winwidth * 3.0 / 20.0, winheight / 10.0 + winheight * 1.0 / 8.0);
	DrawTextString(content_2[1]);
	MovePen(winwidth * 3.0 / 20.0, winheight / 10.0 + winheight * 0.5 / 8.0);
	DrawTextString(content_2[2]);
}

void DrawHelp7()
{
	char *content_1 = {"��ɫ�������겻ɢ����һֱ׷���㣬����Ҳ��Ҫ��Ϣ"};
	char *content_2 = {"��ɫ�����ƶ�ˣ�ʱ�������ʱ��׷��"};
	char *content_3 = {"��ɫ�������ܹ��ݣ������Զʱ׷��������Ͻ�ʱ����Զ��"};
	char *content_4 = {"��ɫ������߽������˲����ң��Ҳ�����"};
	SetPenColor("Purple2");
	drawRectangle(winwidth / 10.0, winheight / 10.0 + winheight / 6.0, winwidth * 4.0 / 5, winheight / 6.0, 1);
	drawRectangle(winwidth / 10.0, winheight / 10.0 + winheight * 2 / 6.0 + winheight / 6.0, winwidth * 4.0 / 5, winheight / 7.0, 1);
	DrawBlinky(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 3 / 6.0 + winheight / 12.0, 1.0, Dir_right);
	DrawInky(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 2 / 6.0 + winheight / 12.0, 1.0, Dir_right);
	DrawClyde(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 1 / 6.0 + winheight / 12.0, 1.0, Dir_right);
	DrawPinky(winwidth * 3 / 20.0, winheight / 10.0 + winheight / 12.0, 1.0, Dir_right);
	SetPenColor("White");
	SetPointSize(20);
	MovePen(winwidth * 2.0 / 10.0, winheight / 10.0 + winheight * 3 / 6.0 + winheight / 15.0);
	DrawTextString(content_1);
	MovePen(winwidth * 2.0 / 10.0, winheight / 10.0 + winheight * 2 / 6.0 + winheight / 15.0);
	DrawTextString(content_2);
	MovePen(winwidth * 2.0 / 10.0, winheight / 10.0 + winheight * 1 / 6.0 + winheight / 15.0);
	DrawTextString(content_3);
	MovePen(winwidth * 2.0 / 10.0, winheight / 10.0 + winheight / 15.0);
	DrawTextString(content_4);
}

void DrawHelp8()
{
	char *content_1[] = {"��������һ����ͼ�༭��������Ϸ���棬����Կ���'MAP", " EDITOR',�����������Ƶĵ�ͼ�༭����Ϊ������һ�ø���", "����Ϸ���飬���ǰѵ�ͼ�Ĵ���Ȩ������ң��ڵ�ͼ�༭����", "�����ҿ���ɫ�飬QǽW·E�Զ���R�������е���Ϣ���ᱣ����", "7��PMM�ļ��С�"};
	MovePen(winwidth * 4 / 20.0, winheight / 10.0 + winheight * 4 / 8.0);
	SetPointSize(20);
	DrawTextString(content_1[0]);
	MovePen(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 3.5 / 8.0);
	DrawTextString(content_1[1]);
	MovePen(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 3.0 / 8.0);
	DrawTextString(content_1[2]);
	MovePen(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 2.5 / 8.0);
	DrawTextString(content_1[3]);
	MovePen(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 2.0 / 8.0);
	DrawTextString(content_1[4]);
	DrawBlinky(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_right);
	DrawPinky(winwidth * 7 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_left);
	DrawInky(winwidth * 13 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_right);
	DrawClyde(winwidth * 17 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_left);
}

void DrawHelp9()
{
	char *content_1[] = {"���������ǽ������а�ϵͳ��������ߵ�ǰʮ�����Խ���", "���а���ҵ���Ϸ��Ϣ���¼��rank.dat�ļ��У�һ�������", "�벻Ҫ�޸�����ļ����Ա��������Ϣ�Ķ�ʧ��"};
	MovePen(winwidth * 4 / 20.0, winheight / 10.0 + winheight * 4 / 8.0);
	SetPointSize(20);
	DrawTextString(content_1[0]);
	MovePen(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 3.5 / 8.0);
	DrawTextString(content_1[1]);
	MovePen(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 3.0 / 8.0);
	DrawTextString(content_1[2]);
	DrawBlinky(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_right);
	DrawPinky(winwidth * 7 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_left);
	DrawInky(winwidth * 13 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_right);
	DrawClyde(winwidth * 17 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_left);
}

void DrawHelp10()
{
	char *content_1[] = {"������Ϸ������ԭ�򣬲����ڴ����ݼ��ع����޷����", "��ȫ�������Ҫ���õ���Ϸ���飬�ٿ�һ�ֵĻ���������������"};
	MovePen(winwidth * 4 / 20.0, winheight / 10.0 + winheight * 4 / 8.0);
	SetPointSize(20);
	DrawTextString(content_1[0]);
	MovePen(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 3.5 / 8.0);
	DrawTextString(content_1[1]);
	DrawBlinky(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_right);
	DrawPinky(winwidth * 7 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_left);
	DrawInky(winwidth * 13 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_right);
	DrawClyde(winwidth * 17 / 20.0, winheight / 10.0 + winheight * 1 / 19.0, 2.0, Dir_left);
}

void DrawHelp11()
{
	char *content_1[] = {"��л��һֱ�����������", "�����ĵ�ϣ������ϲ����������", "��Ϸ����������ͼ�ο�򵥣���", "���������ޣ�������д�����֡�", "������и��õĽ��飬Ҳ��ӭ��", "�������������������ۡ�"};
	MovePen(winwidth * 3.0 / 20.0, winheight * 6.0 / 10.0);
	StartFilledRegion(1);
	DrawHeart();
	EndFilledRegion();
	SetPointSize(20);
	SetPenColor("White");
	MovePen(winwidth / 2.0 + winwidth / 18.0, winheight / 10.0 + winheight * 4.5 / 8.0);
	DrawTextString(content_1[0]);
	MovePen(winwidth / 2.0, winheight / 10.0 + winheight * 4.0 / 8.0);
	DrawTextString(content_1[1]);
	MovePen(winwidth / 2.0, winheight / 10.0 + winheight * 3.5 / 8.0);
	DrawTextString(content_1[2]);
	MovePen(winwidth / 2.0, winheight / 10.0 + winheight * 3.0 / 8.0);
	DrawTextString(content_1[3]);
	MovePen(winwidth / 2.0, winheight / 10.0 + winheight * 2.5 / 8.0);
	DrawTextString(content_1[4]);
	MovePen(winwidth / 2.0, winheight / 10.0 + winheight * 2.0 / 8.0);
	DrawTextString(content_1[5]);
	MovePen(winwidth * 7.0 / 20.0, winheight / 10.0 + winheight * 1.0 / 8.0);
	DrawTextString("�ٴθ�л����Ķ���");
	setButtonColors("S_pink", "S_blue", "S_pink", "S_blue", 1);
	if (button((14), winwidth * 14 / 20.0, winheight * 2.8 / 20.0, winwidth * 3 / 20.0, winwidth / 18.0, "������Ϸ"))
	{
		sum = 0;
		Length = Inivation("S");
		launchselecter = MENU_GAME;
	}
}

void DrawHeart()
{
	SetPointSize(20);
	SetPenColor("ZJUred");
	MovePen(winwidth * 3 / 20.0, winheight * 6.0 / 10.0);
	DrawLine(winwidth * 1.50 / 20.0, winheight * 1.0 / 10.0);
	DrawLine(winwidth * 1.5 / 20.0, -winheight * 1.0 / 10.0);
	DrawLine(winwidth * 1.5 / 20.0, winheight * 1.0 / 10.0);
	DrawLine(winwidth * 1.5 / 20.0, -winheight * 1.0 / 10.0);
	DrawLine(-winwidth * 3.0 / 20.0, -winheight * 2.0 / 10.0);
	DrawLine(-winwidth * 3.0 / 20.0, winheight * 2.0 / 10.0);
}
