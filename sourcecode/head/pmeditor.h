//
//
#ifndef _PMEDITOR_H_
#define _PMEDITOR_H_
//
#include "pmminit.h"
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
////
typedef enum //地图元素的类型
{
    mp_ROAD,
    mp_WALL,
    mp_WATER,
    mp_PLYR,
    mp_GHST1,
    mp_GHST2,
    mp_GHST3,
    mp_GHST4
} mpType;
////
extern int mpedictrl;    // 控制地图编辑器
extern bool ifmecc;      //是否按动地图编辑器的按钮
extern short *mpedist;   //地图数组的首指针
extern bool ifmapedinit; //是否地图编辑器初始化
extern ID mpchsps;       //光标位置
//
bool mapifkey(int key, int event);
void mapedinit();
void mapprint();
void mapchose();
void mapwrite();
//
#endif