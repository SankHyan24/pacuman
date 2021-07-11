// Demon Version
/*
 * File: pmsp.h
 * PacMan_ShortPath
 * Version: 1.0  for Pac-Man
 * ------------------------------------------------------
 * AI Controller
 * 基于迪杰斯特拉算法的ai设计
 */
#ifndef _PMSP_H_
#define _PMSP_H_

#include "pmminit.h"
#include "global.h"
#include "pmrun.h"
#include "pmerr.h"
#include "pmdirrt.h"
// 此为默认的最短路径最大值
#define MAXDIST 0xfffff

struct SpEdge
{
    ID *fr, *to;
    int dist;
}; //边信息
typedef struct
{
    ID *node;
    int data;
} IDnode; //堆结构体
//
extern ID *verhead;             //点表头指针
extern int noofver;             //点的数量
extern struct SpEdge *edgehead; //边表头指针
extern int noofedge;            //边的数量
extern IDnode *spheap;          //堆的头指针
extern int *spdis;              //目前的最短距离
extern int *sppath;             //路径数组
//
extern bool ifspexe; //测试用，是否迪杰斯特拉执行
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
ID *SpLocateVer(int, int);   //点表寻址
int SpContVer(int, int);     //点表寻号
void SpCopyID(ID *a, ID *b); //点赋值
void SpGetVertex();          //构建点表
/*
 * Function: SpGetEdge
 * Add the map Edge into memory
 * ------------------------------------------------------
 */
void SpGetEdge();    //构建边表
void SpInitDjskra(); //迪杰斯特拉初始化
/*
 * Function: SpCreateGraph
 * Judge if the position is a path
 * ------------------------------------------------------
 */
void SpCreateGraph();           //构建“图”
void SpShortPath(ID *StartVer); //迪杰斯特拉调用。需要输入起始位置
/*
 * 函数 SpReinit
 * 对 Short Path 中的变量函数库重新进行初始化
 * 用于地图刷新之后
 */
void SpReinit(); //图重构
/*
 * 函数 SpDjReinit
 * 对 Short Path 中的 Djsktra 相关的变量函数库重新进行初始化
 * 用于起点位置刷新之后
 */
void SpDjReinit(); //迪杰斯特拉数据重构
//Application
/*
 * 函数 SpFstStp
 * Short Path First Step Direction
 * FROM为起点的位置指针，TO为目标点的位置指针
 * 返回值为此路径走第一步的方向
 */
ID *SpFstStp(ID *FROM, ID *TO); //最短路径
ID *SpAntiFS(ID *FROM, ID *TO); //最短路径的相反方向
// 堆函数（一个小根堆）
// The Heap
void swap(IDnode *a, IDnode *b); //堆内元素交换
void up(int p);                  //堆上浮
void push(IDnode x);             //入堆
void down(int p);                //down操作
void pop();                      //出堆

#endif
