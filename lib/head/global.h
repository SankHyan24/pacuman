// Demon Version
/*
 * File: global.h
 * Global_Variable
 * Version: 1.0  for Pac-Man
 * ------------------------------------------------------
 * This file contains the global variables used in the 
 * project.
 */
#ifndef _GLOBAL_H_
#define _GLOBAL_H_
//This is a simple program to make the init prog used only one time
#define INITCHECK(a) \
	if (a == 1)      \
		return;      \
	a = 1;
#include "pmanima.h"
#include "pmminit.h"
#include "pmdirrt.h"
/*
 * 
 *
 * 
 * 
 */
extern double mouse_x;
extern double mouse_y;

/*
 * The information of the map
 * Variables:
 * Length           The Length of the Map
 * Maxdge           The edge number in the Map Graph
 * Maxode           The node number in the Map Graph
 * Map[][]          The Map memorized from the file
 * mapinitialized   If the Map is initialized
 */
extern int Length;
extern int Maxdge;
extern int Maxode;
extern int Map[MAXSTRLEN][MAXSTRLEN];
/*
 * Window information
 * Variables:
 * winheight     the height of the window
 * winwidth      the width of the window
 */
extern double winwidth;
extern double winheight;
/*
 * Rank&Score information
 * Variables:
 * myscore       the user's score
 * myname[]      the user's name
 */
extern int mylevel; // the user's level
extern int myscore;
extern char myname[35];
/*
 * The Launcher of the Game
 * Variable:
 * launchselecter    to select the different GUI
 */
extern int launchselecter;
typedef enum
{
	MENU_MAIN,
	MENU_GAME,
	MENU_RANK,
	MENU_EDIT,
	MENU_HELP,
	MENU_GMAP,
	MENU_ANIM,
	MENU_WORL,
	MENU_TEST
} mpMenuLauncher;
typedef enum
{
	Time_Anima,
	Time_Loop,
	Time_Ghst,
	Time_Newbee,
	Time_Step,
	Time_Result,
	Time_Tester
} MTimer;
typedef enum
{
	Skin_plain, // 平平无奇
	Skin_hulk1, // 浩克1
	Skin_hulk2, // 浩克2
	Skin_flash	// 闪电侠
} Skin;
typedef enum
{
	Mp_way,
	Mp_wall,
	Mp_pea,	  //map地图里不使用，默认为0
	Mp_start, //状态里不使用
	Mp_Ghst	  //状态里不使用
} Mp;

/*
 * Time Controller
 * Variable:
 * timeselecter     to select the timer
 * animatimer       to control the Animation
 */
extern int animatimer;
extern double speed;
extern int winorlost;
extern char *mapnames[];
extern char *skinnames[];
extern char *skinNC[];
extern char *skininfo[];
extern int testflag;
#endif
