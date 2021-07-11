//
// By scitbb
//
#ifndef _PMEDITOR_H_
#define _PMEDITOR_H_
//
#include "pmminit.h"
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
////
typedef enum //��ͼԪ�ص�����
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
extern int mpedictrl;    // ���Ƶ�ͼ�༭��
extern bool ifmecc;      //�Ƿ񰴶���ͼ�༭���İ�ť
extern short *mpedist;   //��ͼ�������ָ��
extern bool ifmapedinit; //�Ƿ��ͼ�༭����ʼ��
extern ID mpchsps;       //���λ��
//
bool mapifkey(int key, int event);
void mapedinit();
void mapprint();
void mapchose();
void mapwrite();
//
#endif