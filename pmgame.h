// Demon Version
// By scitbb
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
} stateofgame;              //��Ϸʵʱ����
extern stateofgame GmSts;   //Game Settings and States
extern int scoretmp;        // ��ʱ����
extern bool ifpause;        // ��ͣ����ť
extern bool ifgminit;       //�Ƿ��ʼ����ͼ
extern int durstepply;      //��ҵ���Ϸ����
extern int durstepght;      //�������Ϸ����
extern double tmpsts;       //���궯������
extern int energy;          //����ֵ
extern ID *ghststart;       // ������ʼλ��
extern int ghstrenewcnt[4]; //���ĸ�����Ϣ

void gameinit();                                      //*��ʼ����ͼ���أ���ʼ��������
void gmstinit();                                      // */��Ϸ������ʼ��/����
void drawmap();                                       //*����Map
void dmapname();                                      //*��ͼ������
void drawlvl(double x, double y, double w, double h); //���Ƶȼ���
void drawscore();                                     //���Ʒ�����
void drawEnerbar();                                   //����������
static void drawGstBar();                             //���ƹ���������Ϸ������
void loadsrc();                                       //���ص�ͼԪ��
void disppacman();                                    //��Ϸ����������
#endif
