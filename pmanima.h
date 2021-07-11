// Demon Version
/*
 * File: pmanima.h
 * PacMan_ANIMAtion
 * Version: 1.0 for Pac-Man
 * ------------------------------------------------------------------
 * This file contains the fundamental Graphics used in the Pac-Man. 
 */
#ifndef _PMANIMA_H_
#define _PMANIMA_H_

#include "graphics.h"
#include <windows.h>
#include <winuser.h>
#include "graphics.h"
#include "extgraph.h"
#include "pmdirrt.h"
#include "imgui.h"
#include "global.h"

/*
 * \pie = 3.14......
  */
#define piepie 3.1415926545897932
typedef enum
{
  tg_Blinky,
  tg_Pinky,
  tg_Inky,
  tg_Clyde
} TypeGst;
/*
 * Function: BlinkCtrlor
 * To control the Graphics to blink
 * -------------------------------------------------------------------
 * Usage:
 * T is the cycle whose unit is 40*ms. t is the ratio of the blink period.
 * In the displaytime, the return value is 1, else is 0.
 */
bool BlinkCtrlor(int T, double t);
/*
 * Function: DrawECircle
 * Draw a Elipsecircle
 * --------------------------------------------------------------------
 * Usage: 
 * (cx,cy) is the center position of the Elipse circle.
 * And r is the Radius. 
 * color is the color of the circle.
 * Whether it is filled by the color depends on the fillflag. 
 */
void DrawECircle(double cx, double cy, double rx, double ry, string color, int fillflag);
/*
 * Function: DrawGhost
 * Draw a Ghost
 * --------------------------------------------------------------------
 * Usage: 
 * (cx,cy) is the center position of the Ghost.
 * size is the width and height.
 * color is the color of it.
 * dir is the direction of its eyes.
 * Further more:
 * Blinky, Pinky, Clyde and Inky are 4 different Ghosts.
 */
void DrawGhost(double cx, double cy, double size, string color, Dir dir);
void DrawBlinky(double cx, double cy, double size, Dir dir);
void DrawPinky(double cx, double cy, double size, Dir dir);
void DrawInky(double cx, double cy, double size, Dir dir);
void DrawClyde(double cx, double cy, double size, Dir dir);
/*
 * Function: DrawEater
 * Draw the Yellow Pea Eater with a moving mouth
 * --------------------------------------------------------------------
 * Usage: 
 * (cx,cy) is the center position of the Eater.
 * size is the 2*radius size of the body.
 * direction determines the direction of the mouth.
 */
void DrawEater(double cx, double cy, double size, int direct, string background, int skin);
/*
 * Function: DrawCoin
 * Draw a Coin
 * --------------------------------------------------------------------
 * Usage: 
 * (cx,cy) is the center position of the coin.
 * r is the radius.
 */
void DrawCoin(double cx, double cy, double r);
/*
 * Function: DrawMenuBackG
 * Draw the Back Ground of the Menu
 * --------------------------------------------------------------------
 * Usage:
 * Use it in the Function: drawpmMenu and DrawAnima.
 */
void DrawMenuBackG();
/*
 * Function: DrawMenuLable
 * Draw the Animation Menu Lable 
 * --------------------------------------------------------------------
 * Usage:
 * mei sha jiang de 
 */
void DrawMenuLable();
/*
 */
void DrawStar(double cx, double cy, double halfsize, string background, string color);
void DrawBlinkyStar();
/*
 * Function: DrawAnima
 * Draw the opening animation at the beginning of the program
 * --------------------------------------------------------------------
 * Usage:
 * Use it at the beginning of the program.
 * You Must make sure the Value of the "launchselecter" is "MENU_ANIM".
 */
void DrawAnima();
void DrawGamePreview(); // 绘制game的ui界面
void DrawEditName();    //绘制主菜单的姓名输入框
#endif
