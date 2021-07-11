// Demon Version
// By scitbb
/*
 * File: pmsp.h
 * PacMan_ShortPath
 * Version: 1.0  for Pac-Man
 * ------------------------------------------------------
 * AI Controller
 * ���ڵϽ�˹�����㷨��ai���
 */
#ifndef _PMSP_H_
#define _PMSP_H_

#include "pmminit.h"
#include "global.h"
#include "pmrun.h"
#include "pmerr.h"
#include "pmdirrt.h"
// ��ΪĬ�ϵ����·�����ֵ
#define MAXDIST 0xfffff

struct SpEdge
{
    ID *fr, *to;
    int dist;
}; //����Ϣ
typedef struct
{
    ID *node;
    int data;
} IDnode; //�ѽṹ��
//
extern ID *verhead;             //���ͷָ��
extern int noofver;             //�������
extern struct SpEdge *edgehead; //�߱�ͷָ��
extern int noofedge;            //�ߵ�����
extern IDnode *spheap;          //�ѵ�ͷָ��
extern int *spdis;              //Ŀǰ����̾���
extern int *sppath;             //·������
//
extern bool ifspexe; //�����ã��Ƿ�Ͻ�˹����ִ��
//
/*
 * Function: Spifpath
 * Judge if the position is a path
 * ------------------------------------------------------
 */
bool Spifpath(int Vertex);
/*
 * Function: SpGetVertex
 * Add the map Vertex into memory
 * ------------------------------------------------------
 */
ID *SpLocateVer(int, int);   //���Ѱַ
int SpContVer(int, int);     //���Ѱ��
void SpCopyID(ID *a, ID *b); //�㸳ֵ
void SpGetVertex();          //�������
/*
 * Function: SpGetEdge
 * Add the map Edge into memory
 * ------------------------------------------------------
 */
void SpGetEdge();    //�����߱�
void SpInitDjskra(); //�Ͻ�˹������ʼ��
/*
 * Function: SpCreateGraph
 * Judge if the position is a path
 * ------------------------------------------------------
 */
void SpCreateGraph();           //������ͼ��
void SpShortPath(ID *StartVer); //�Ͻ�˹�������á���Ҫ������ʼλ��
/*
 * ���� SpReinit
 * �� Short Path �еı������������½��г�ʼ��
 * ���ڵ�ͼˢ��֮��
 */
void SpReinit(); //ͼ�ع�
/*
 * ���� SpDjReinit
 * �� Short Path �е� Djsktra ��صı������������½��г�ʼ��
 * �������λ��ˢ��֮��
 */
void SpDjReinit(); //�Ͻ�˹���������ع�
//Application
/*
 * ���� SpFstStp
 * Short Path First Step Direction
 * FROMΪ����λ��ָ�룬TOΪĿ����λ��ָ��
 * ����ֵΪ��·���ߵ�һ���ķ���
 */
ID *SpFstStp(ID *FROM, ID *TO); //���·��
ID *SpAntiFS(ID *FROM, ID *TO); //���·�����෴����
// �Ѻ�����һ��С���ѣ�
// The Heap
void swap(IDnode *a, IDnode *b); //����Ԫ�ؽ���
void up(int p);                  //���ϸ�
void push(IDnode x);             //���
void down(int p);                //down����
void pop();                      //����

#endif
