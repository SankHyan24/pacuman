// Demon Version
/*
 * File: pmrun.h
 * PacMan_RUN
 * Version: 1.0  for Pac-Man
 * ------------------------------------------------------
 * RUN THE GAME !!!
 */
#ifndef _PMRUN_H_
#define _PMRUN_H_
#include "pmminit.h"
#include "global.h"
#include "pmgame.h"
typedef enum
{
    MvChase,
    MvAmbush,
    MvWonder,
    Mvpret,
    MvRun
} MvMode;
extern bool timlopflag;            //玩家回合判定
extern bool timghstflag;           //鬼回合判定
extern bool newbeeflag;            //牛逼变身之后的判定
extern int runmvctrl;              //玩家移动控制
extern int alittlegg;              //用来设计一个彩蛋：博士变身之后，点击pause暂停游戏，之后退出游戏。之后重新重新选择地图进入游戏，点击resume继续。此时永久激活新角色绿巨人形态。注意！因为在外面打开游戏可能会秒退，建议用我们提供的新版dev编译调试从而体验此功能
void DeletPea();                   //删除吃豆人位置的豆子
bool runifkey(int key, int event); // 用在launcher里，判断是否是游戏标准信息
void Changedir();                  // 更改吃豆人的方向
void MoveMan();                    // 根据上面的方向改变吃豆人位置
// 鬼魂的AI函数族（已被封装好）
void AiChase(int gstid);  // AI 追逐
void AiWonder(int gstid); // AI 随即溜达
void AiAmbush(int gstid); // AI 埋伏（没做好）
void AiPreTen(int gstid); // AI 假装抓你
void AiRun(int gstid);    // Ai逃走
//
void MoveGst(int gstid, int mode); // 鬼控制函数，前面是鬼的序号，后面是Ai代号
void Lost_Win();                   // 判断输赢
#endif
