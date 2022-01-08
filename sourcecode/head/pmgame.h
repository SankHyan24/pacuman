// Demon Version
/*
 * File: pmgame.h
 * PacMan_GAME
 * Version: 1.0  for Pac-Man
 * ------------------------------------------------------
 * To draw the game graphics.
 */
#ifndef _PMGAME_H_
#define _PMGAME_H_
#include "boolean.h"
#include "pmminit.h"
#include "pmsp.h"
typedef struct
{
    int Lens, *map;         // Map Information
    int lvl;                // Level
    Skin skin;              // Your Skin
    ID *player;             // Player Position
    Dir plyrd;              // Player Direction
    bool ifmv;              // If Player Move
    bool ifghst[4];         // If Ghost Exist
    ID *ghst[4];            // Ghost Position
    Dir ghstd[4];           // Ghost Direction
    int plyvelo, ghtvelo;   // Player/Ghost Velocity
    int score, scoregoal;   // Your Score and the Goal
    char name[50];          // Your Name
} stateofgame;              //游戏实时数据
extern stateofgame GmSts;   //Game Settings and States
extern int scoretmp;        // 暂时分数
extern bool ifpause;        // 暂停键按钮
extern bool ifgminit;       //是否初始化地图
extern int durstepply;      //玩家的游戏周期
extern int durstepght;      //鬼魂的游戏周期
extern double tmpsts;       //鬼魂动画控制
extern int energy;          //能量值
extern ID *ghststart;       // 鬼的起始位置
extern int ghstrenewcnt[4]; //鬼的复活信息

void gameinit();                                      //*初始化地图加载（初始化保护）
void gmstinit();                                      // */游戏参数初始化/归零
void drawmap();                                       //*绘制Map
void dmapname();                                      //*地图名称栏
void drawlvl(double x, double y, double w, double h); //绘制等级栏
void drawscore();                                     //绘制分数栏
void drawEnerbar();                                   //绘制能量条
static void drawGstBar();                             //绘制鬼魂条和游戏进程条
void loadsrc();                                       //加载地图元素
void disppacman();                                    //游戏进程主程序
#endif
