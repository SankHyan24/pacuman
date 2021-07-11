// By scitbb
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
extern bool timlopflag;            //��һغ��ж�
extern bool timghstflag;           //���غ��ж�
extern bool newbeeflag;            //ţ�Ʊ���֮����ж�
extern int runmvctrl;              //����ƶ�����
extern int alittlegg;              //�������һ���ʵ�����ʿ����֮�󣬵��pause��ͣ��Ϸ��֮���˳���Ϸ��֮����������ѡ���ͼ������Ϸ�����resume��������ʱ���ü����½�ɫ�̾�����̬��ע�⣡��Ϊ���������Ϸ���ܻ����ˣ������������ṩ���°�dev������ԴӶ�����˹���
void DeletPea();                   //ɾ���Զ���λ�õĶ���
bool runifkey(int key, int event); // ����launcher��ж��Ƿ�����Ϸ��׼��Ϣ
void Changedir();                  // ���ĳԶ��˵ķ���
void MoveMan();                    // ��������ķ���ı�Զ���λ��
// �����AI�����壨�ѱ���װ�ã�
void AiChase(int gstid);  // AI ׷��
void AiWonder(int gstid); // AI �漴���
void AiAmbush(int gstid); // AI �����û���ã�
void AiPreTen(int gstid); // AI ��װץ��
void AiRun(int gstid);    // Ai����
//
void MoveGst(int gstid, int mode); // �����ƺ�����ǰ���ǹ�����ţ�������Ai����
void Lost_Win();                   // �ж���Ӯ
#endif
