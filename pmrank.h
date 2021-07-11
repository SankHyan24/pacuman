// By scitbb
#ifndef _PMRANK_H_
#define _PMRANK_H_

#include "pmLaucher.h"
#include "global.h"
#include "pmminit.h"
/*
 * VarType: rkinfo
 * The information of the Rank Table
 * int level: the level of the player
 * int score: the score of the player
 * char cinfo[40]: char string information include player's name and Time
 * struct rkinfo *next: linklist struct, the next rank information
 */
typedef struct
{
    int level;
    int score;
    char cinfo[40];
} rkinfo; //*���а���Ϣ
/*
 * Global Variable:
 * rkinfo head: the header of the rank table linklist
 * int ifrankexit: if the rank file exist
 * int ifrankgotten: if the rank information is gotten from the file
 * int ifrankadded: if the new player's rank information is added
 * int ifrankwrtd: if the rank information file is updated 
 */
extern rkinfo head;      //��Ϣͷ
extern int ifrankexit;   //�Ƿ����а����
extern int ifrankgotten; //�Ƿ��Ѿ��õ�����
extern int ifrankadded;  //�Ƿ��Ѿ���������
extern int ifrankwrtd;   //�Ƿ��Ѿ�д������
/*
 * Function: GetRank()
 * Get the information in the rank file.
 */
void GetRank();
/*
 * Function: PrintRank()
 * Print the Rank Table in the Function: disprank()
 * Use it after the rank file is read.
 */
void PrintRank();
/*
 * Function: AddRank()
 * Add the new game rank information to the linklist
 */
void AddRank();
/*
 * Function: WriteRank()
 * 
 */
void WriteRank();
#endif
