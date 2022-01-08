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
	char *title[] = {"写在前面","基本说明","游戏背景","英雄简介","英雄简介","英雄简介","幽灵逻辑","地图编辑","得分排行","BUG问题","项目结语"}; 
	SetPenColor("Purple1");
	drawRectangle(winwidth / 10.0, winheight / 10.0, winwidth * 4.0 / 5, winheight * 4.0 / 5, 1);
	SetPenColor("White");
	SetPointSize(40);
	MovePen(winwidth * 12.0 / 30.0, winheight * 4 / 5.0);
	DrawTextString(title[(page-1)%pagenum]);
	MovePen(winwidth /10.0,winheight * 7.7/ 10.0);
	DrawLine(winwidth * 4.0 /5,0);
	switch (page%pagenum) {
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
	if (button(GenUIID(15), winwidth * 15 / 20.0, winheight * 8.0 / 10.0, winwidth * 1.3 / 10.0, 1.0, "下一页"))
		page++;
	if (button(GenUIID(15), winwidth * 5 / 20.0 - winwidth * 1.3 / 10.0, winheight * 8.0 / 10.0, winwidth * 1.3 / 10.0, 1.0, "上一页"))
		if (page == 0)
			page = pagenum - 1;
		else
			page--;
	setButtonColors("Blue", "Blue", "Red", "Red", 0); 
}

void DrawHelp1()
{
	char *content_1[]={"如果你是第一次玩，一定要把这个介绍看完哦！当然，如","果你已经看过了，点击右下角BACK按钮，就可退出帮助界面。"};
	char *content_2[]={"话不多说，快来跟着引导来玩PAC MAN吧，吼吼！"}; 
	char *content_3[]={"先来介绍游戏的主界面。现在你处在help界面内，在这里","你可以看到与游戏背景和游玩方法的详细说明；其它的三个按","分别对应'开始'、'排行榜'和'退出'。此外，你可以在主界面上方","的文本框内修改你的名字。取个好听的名字吧！"};
	MovePen(winwidth * 4 / 20.0, winheight / 10.0 + winheight * 4 / 8.0);
	SetPointSize(20); 
	DrawTextString(content_1[0]);
	MovePen(winwidth * 3 / 20.0,winheight / 10.0 + winheight * 3.5 / 8.0);
	DrawTextString(content_1[1]);
	MovePen(winwidth * 4 /20.0,winheight /10.0 +winheight *3.0 /8.0);  
	DrawTextString(content_2[0]);
	MovePen(winwidth * 4 /20.0,winheight /10.0+winheight *2.5/8.0);
	DrawTextString(content_3[0]);
	MovePen(winwidth * 3 /20.0,winheight /10.0 +winheight *2.0/8.0);
	DrawTextString(content_3[1]);
	MovePen(winwidth * 3 /20.0,winheight /10.0 +winheight *1.5/8.0);
	DrawTextString(content_3[2]);
	MovePen(winwidth * 3 /20.0,winheight /10.0 +winheight *1.0/8.0);
	DrawTextString(content_3[3]);
} 

void DrawHelp2()
{
	char *content_1[]={"点击开始按钮进入游戏后，你可以点击'change'按钮选择","自己的角色;点击游戏右上方的'select map'选择关卡地形。"};
	char *content_2[]={"游戏的操作方法为：通过键盘上下左右键改变移动方向，","利用自身特点躲避怪物收集金币。注意，四个小怪是不死的，","即便你把它们吃掉，它们也会在不久后复活。"};
	char *content_3[]={"了解完这些基础的信息后，让我们进入这个奇妙的世界吧！"};
	SetPointSize(20);
	MovePen(winwidth * 4 / 20.0, winheight / 10.0 + winheight * 4 / 8.0);
	DrawTextString(content_1[0]);
	MovePen(winwidth * 3 / 20.0,winheight / 10.0 + winheight * 3.5 / 8.0);
	DrawTextString(content_1[1]);
	MovePen(winwidth * 4 /20.0,winheight /10.0 +winheight *3.0 /8.0);  
	DrawTextString(content_2[0]);
	MovePen(winwidth * 3 /20.0,winheight /10.0+winheight *2.5/8.0);
	DrawTextString(content_2[1]);
	MovePen(winwidth * 3 /20.0,winheight /10.0 +winheight *2.0/8.0);
	DrawTextString(content_2[2]);
	MovePen(winwidth * 4 /20.0,winheight /10.0 +winheight *1.5/8.0);
	DrawTextString(content_3[0]);
	DrawBlinky(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 1 / 19.0 , 2.0, Dir_right);
	DrawPinky(winwidth * 7 / 20.0, winheight / 10.0 + winheight * 1 / 19.0 , 2.0, Dir_left);
	DrawInky(winwidth * 13 / 20.0, winheight / 10.0 + winheight * 1 / 19.0 , 2.0, Dir_right);
	DrawClyde(winwidth * 17 / 20.0, winheight / 10.0 + winheight * 1 /19.0 , 2.0, Dir_left);
}

void DrawHelp3()
{
	char *content_1[]={"很久很久以前，有三个勇士来到了一座神秘的城堡，他们","只知道城堡里有数不胜数的宝藏，却不知道这里是被诅咒的地","方。四只游荡的小鬼会出现在城堡的中央，带走那些大意的勇","士的生命。在这里，你只有收集到足够的金币才能解放你的力","量，从这里逃出生天。"};
	char *content_2[]={"嘘！它来了！"};
	SetPointSize(20);
	MovePen(winwidth * 4 / 20.0, winheight / 10.0 + winheight * 4 / 8.0);
	DrawTextString(content_1[0]);
	MovePen(winwidth * 3 / 20.0,winheight / 10.0 + winheight * 3.5 / 8.0);
	DrawTextString(content_1[1]);
	MovePen(winwidth * 3 /20.0,winheight /10.0 +winheight *3.0 /8.0);  
	DrawTextString(content_1[2]);
	MovePen(winwidth * 3 /20.0,winheight /10.0+winheight *2.5/8.0);
	DrawTextString(content_1[3]); 
	MovePen(winwidth * 3 /20.0,winheight /10.0+winheight *2.0/8.0);
	DrawTextString(content_1[4]);
	MovePen(winwidth * 4 /20.0,winheight /10.0+winheight *1.5/8.0);
	DrawTextString(content_2[0]);
	DrawBlinky(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 1 / 19.0 , 2.0, Dir_right);
	DrawPinky(winwidth * 7 / 20.0, winheight / 10.0 + winheight * 1 / 19.0 , 2.0, Dir_left);
	DrawInky(winwidth * 13 / 20.0, winheight / 10.0 + winheight * 1 / 19.0 , 2.0, Dir_right);
	DrawClyde(winwidth * 17 / 20.0, winheight / 10.0 + winheight * 1 /19.0 , 2.0, Dir_left);
}

void DrawHelp4()
{
	char *content_1[]={"Paku是一个普通人。他没","有什么特长，如果硬要说点什","么的话，那就是他很容易满足。","因此，在游戏中你只需要吃够","2/3的金币就可以顺利过关了。"};
	char *content_2[]={"加油！苟到最后就是成功！"};
	DrawEater(winwidth * 3.0 / 10.0, winheight * 5.0 /10, 2.5, Dir_right, "Purple1", 0);
	SetPointSize(20);
	SetPenColor("White"); 
	MovePen(winwidth / 2.0 +winwidth /18.0,winheight / 10.0 + winheight * 4/8.0);
	DrawTextString(content_1[0]); 
	MovePen(winwidth / 2.0 ,winheight / 10.0 + winheight * 3.5/8.0);
	DrawTextString(content_1[1]);
	MovePen(winwidth / 2.0 ,winheight / 10.0 + winheight * 3.0/8.0);
	DrawTextString(content_1[2]);
	MovePen(winwidth / 2.0 ,winheight / 10.0 + winheight * 2.5/8.0);
	DrawTextString(content_1[3]);
	MovePen(winwidth / 2.0 ,winheight / 10.0 + winheight * 2.0/8.0);
	DrawTextString(content_1[4]);
	MovePen(winwidth  * 7.0 / 20.0 ,winheight / 10.0 + winheight * 1.0/8.0);
	DrawTextString(content_2[0]);
}

void DrawHelp5()
{
	DrawEater(winwidth * 3.0 / 10.0, winheight * 5.0 /10, 2.5, Dir_right, "Purple1", 1);
	char *content_1[]={"布鲁斯班纳博士，是世界著","名的物理学家，在一次意外中被","自己制造出的伽马炸弹的放射线","大量辐射，身体产生异变，后来","每他情绪激动心跳加速的时候，","就会变成名为浩克的绿色怪物。"};
	char *content_2[]={"游戏中的你具有摧毁一切的潜能，需要收集金币积攒能","量(左侧能量条），能量满之后可以按“空格键”变身绿巨人。","这时连魔鬼都会为你颤抖。"};
	SetPointSize(20);
	SetPenColor("White"); 
	MovePen(winwidth / 2.0 +winwidth /18.0,winheight / 10.0 + winheight * 5.0/8.0);
	DrawTextString(content_1[0]); 
	MovePen(winwidth / 2.0 ,winheight / 10.0 + winheight * 4.5/8.0);
	DrawTextString(content_1[1]);
	MovePen(winwidth / 2.0 ,winheight / 10.0 + winheight * 4.0/8.0);
	DrawTextString(content_1[2]);
	MovePen(winwidth / 2.0 ,winheight / 10.0 + winheight * 3.5/8.0);
	DrawTextString(content_1[3]);
	MovePen(winwidth / 2.0 ,winheight / 10.0 + winheight * 3.0/8.0);
	DrawTextString(content_1[4]);
	MovePen(winwidth / 2.0 ,winheight / 10.0 + winheight * 2.5/8.0);
	DrawTextString(content_1[5]); 
	MovePen(winwidth * 4.0 / 20.0 ,winheight / 10.0 + winheight * 1.5/8.0);
	DrawTextString(content_2[0]);
	MovePen(winwidth * 3.0 /20.0 ,winheight / 10.0 + winheight * 1.0 /8.0);
	DrawTextString(content_2[1]);
	MovePen(winwidth * 3.0 /20.0 ,winheight / 10.0 + winheight * 0.5 /8.0);
	DrawTextString(content_2[2]);
}

void DrawHelp6()
{
	DrawEater(winwidth * 3.0 / 10.0, winheight * 5.0 /10, 2.5, Dir_right, "Purple1", 3);
	char *content_1[]={"尼奥（Neo），真名为托马斯","·安德森（Thomas A. Anderson），","身为黑客帝国母体Matrix中的救世","主，为了促成了机器与人类之间","的和平进入母体完成任务。"};
	char *content_2[]={"游戏中的你具有瞬间移动的力量，需要你收集金币积攒能","量（左侧能量条），能量满之后可以按“空格键”瞬间移动到前","方最多十格位置，这时连魔鬼也无法阻拦你。"};
	SetPointSize(20);
	SetPenColor("White"); 
	MovePen(winwidth / 2.0 +winwidth /18.0,winheight / 10.0 + winheight * 4.5/8.0);
	DrawTextString(content_1[0]); 
	MovePen(winwidth / 2.0 ,winheight / 10.0 + winheight * 4.0/8.0);
	DrawTextString(content_1[1]);
	MovePen(winwidth / 2.0 ,winheight / 10.0 + winheight * 3.5/8.0);
	DrawTextString(content_1[2]);
	MovePen(winwidth / 2.0 ,winheight / 10.0 + winheight * 3.0/8.0);
	DrawTextString(content_1[3]);
	MovePen(winwidth / 2.0 ,winheight / 10.0 + winheight * 2.5/8.0);
	DrawTextString(content_1[4]);
	MovePen(winwidth * 4.0 / 20.0 ,winheight / 10.0 + winheight * 1.5/8.0);
	DrawTextString(content_2[0]);
	MovePen(winwidth * 3.0 /20.0 ,winheight / 10.0 + winheight * 1.0 /8.0);
	DrawTextString(content_2[1]);
	MovePen(winwidth * 3.0 /20.0 ,winheight / 10.0 + winheight * 0.5 /8.0);
	DrawTextString(content_2[2]);
}

void DrawHelp7()
{
	char *content_1={"红色鬼魂阴魂不散，会一直追踪你，但它也需要休息"};
	char *content_2={"青色鬼魂诡计多端，时而埋伏，时而追击"};
	char *content_3={"橙色鬼魂欲擒故纵，距离较远时追击，距离较近时反而远离"};
	char *content_4={"粉色鬼魂清高骄傲，人不近我，我不近人"};
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
	char *content_1[]={"我们来讲一讲地图编辑器。在游戏界面，你可以看到'MAP"," EDITOR',这就是我们设计的地图编辑器。为了让玩家获得更好","的游戏体验，我们把地图的创作权交给玩家，在地图编辑器上","下左右控制色块，Q墙W路E吃豆人R鬼，所有的信息都会保存在","7个PMM文件中。"};
	MovePen(winwidth * 4 / 20.0, winheight / 10.0 + winheight * 4 / 8.0);
	SetPointSize(20); 
	DrawTextString(content_1[0]);
	MovePen(winwidth * 3 / 20.0,winheight / 10.0 + winheight * 3.5 / 8.0);
	DrawTextString(content_1[1]);
	MovePen(winwidth * 3 /20.0,winheight /10.0 +winheight *3.0 /8.0);  
	DrawTextString(content_1[2]);
	MovePen(winwidth * 3 /20.0,winheight /10.0+winheight *2.5/8.0);
	DrawTextString(content_1[3]);
	MovePen(winwidth * 3 /20.0,winheight /10.0 +winheight *2.0/8.0);
	DrawTextString(content_1[4]);
	DrawBlinky(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 1 / 19.0 , 2.0, Dir_right);
	DrawPinky(winwidth * 7 / 20.0, winheight / 10.0 + winheight * 1 / 19.0 , 2.0, Dir_left);
	DrawInky(winwidth * 13 / 20.0, winheight / 10.0 + winheight * 1 / 19.0 , 2.0, Dir_right);
	DrawClyde(winwidth * 17 / 20.0, winheight / 10.0 + winheight * 1 /19.0 , 2.0, Dir_left);
}

void DrawHelp9()
{
	char *content_1[]={"接下来我们介绍排行榜系统。分数最高的前十名可以进入","排行榜。玩家的游戏信息会记录在rank.dat文件中，一般情况下","请不要修改这个文件，以避免造成信息的丢失。"};
	MovePen(winwidth * 4 / 20.0, winheight / 10.0 + winheight * 4 / 8.0);
	SetPointSize(20); 
	DrawTextString(content_1[0]);
	MovePen(winwidth * 3 / 20.0,winheight / 10.0 + winheight * 3.5 / 8.0);
	DrawTextString(content_1[1]);
	MovePen(winwidth * 3 /20.0,winheight /10.0 +winheight *3.0 /8.0);  
	DrawTextString(content_1[2]);
	DrawBlinky(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 1 / 19.0 , 2.0, Dir_right);
	DrawPinky(winwidth * 7 / 20.0, winheight / 10.0 + winheight * 1 / 19.0 , 2.0, Dir_left);
	DrawInky(winwidth * 13 / 20.0, winheight / 10.0 + winheight * 1 / 19.0 , 2.0, Dir_right);
	DrawClyde(winwidth * 17 / 20.0, winheight / 10.0 + winheight * 1 /19.0 , 2.0, Dir_left);
}

void DrawHelp10()
{
	char *content_1[]={"由于游戏体量的原因，部分内存数据加载过后无法清空","完全，如果想要更好的游戏体验，再开一局的话建议重新启动。"};
	MovePen(winwidth * 4 / 20.0, winheight / 10.0 + winheight * 4 / 8.0);
		SetPointSize(20); 
		DrawTextString(content_1[0]);
		MovePen(winwidth * 3 / 20.0,winheight / 10.0 + winheight * 3.5 / 8.0);
		DrawTextString(content_1[1]);
		DrawBlinky(winwidth * 3 / 20.0, winheight / 10.0 + winheight * 1 / 19.0 , 2.0, Dir_right);
		DrawPinky(winwidth * 7 / 20.0, winheight / 10.0 + winheight * 1 / 19.0 , 2.0, Dir_left);
		DrawInky(winwidth * 13 / 20.0, winheight / 10.0 + winheight * 1 / 19.0 , 2.0, Dir_right);
		DrawClyde(winwidth * 17 / 20.0, winheight / 10.0 + winheight * 1 /19.0 , 2.0, Dir_left);
}

void DrawHelp11()
{
	char *content_1[]={"感谢你一直读到了这里。我","们真心地希望你能喜欢我们做的","游戏。但是由于图形库简单，作","者能力有限，难免会有错误出现。","如果你有更好的建议，也欢迎在","互评结束后找我们讨论。"};
	MovePen(winwidth * 3.0 /20.0,winheight * 6.0 /10.0 );
	StartFilledRegion(1);
	DrawHeart();
	EndFilledRegion();
	SetPointSize(20);
	SetPenColor("White"); 
	MovePen(winwidth / 2.0 +winwidth /18.0,winheight / 10.0 + winheight * 4.5/8.0);
	DrawTextString(content_1[0]); 
	MovePen(winwidth / 2.0 ,winheight / 10.0 + winheight * 4.0/8.0);
	DrawTextString(content_1[1]);
	MovePen(winwidth / 2.0 ,winheight / 10.0 + winheight * 3.5/8.0);
	DrawTextString(content_1[2]);
	MovePen(winwidth / 2.0 ,winheight / 10.0 + winheight * 3.0/8.0);
	DrawTextString(content_1[3]);
	MovePen(winwidth / 2.0 ,winheight / 10.0 + winheight * 2.5/8.0);
	DrawTextString(content_1[4]);
	MovePen(winwidth  / 2.0 ,winheight / 10.0 + winheight * 2.0/8.0);
	DrawTextString(content_1[5]);
	MovePen(winwidth * 7.0 / 20.0,winheight / 10.0 + winheight * 1.0/8.0);
	DrawTextString("再次感谢你的阅读。"); 
	setButtonColors("S_pink", "S_blue", "S_pink", "S_blue", 1);
	if (button((14), winwidth * 14 / 20.0, winheight * 2.8 / 20.0, winwidth * 3 / 20.0, winwidth / 18.0, "进入游戏"))
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
	MovePen(winwidth * 3 /20.0,winheight * 6.0 /10.0 );
	DrawLine(winwidth * 1.50 / 20.0 ,winheight * 1.0 /10.0);
	DrawLine(winwidth * 1.5 /20.0 ,-winheight * 1.0 / 10.0);
	DrawLine(winwidth * 1.5 / 20.0 ,winheight * 1.0 /10.0);
	DrawLine(winwidth * 1.5 /20.0 ,-winheight * 1.0 / 10.0);
	DrawLine(-winwidth * 3.0 / 20.0 ,-winheight * 2.0 /10.0);
	DrawLine(-winwidth *3.0 /20.0 ,winheight * 2.0 /10.0);
}
