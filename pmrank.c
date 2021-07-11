#include "pmrank.h"
#include "global.h"
#include "pmgame.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <io.h>
int ifrankadded = 0;
int ifrankwrtd = 0;
int ifrankgotten = 0;
rkinfo toplist[11];
int rknumber = 0;
rkinfo head;
static bool cmpname(char *infosrc);

void GetRank()
{
    INITCHECK(ifrankgotten)
    memset(toplist, 0, 11 * sizeof(rkinfo));
    FILE *fop = NULL;
    fop = fopen("rank.dat", "r");
    if (fop == NULL)
    {
        fop = fopen("rank.dat", "w+");
        fprintf(fop, "  2  1Revenger#Thu Feb 29 09:36:19 2001");
        fclose(fop);
        fop = fopen("rank.dat", "r");
    }
    int cnt = 0;
    rkinfo *wkp = NULL, *tmp;
    if (fgetc(fop) != '\0')
        while (!feof(fop))
        {
            fscanf(fop, "%d", &(toplist[cnt].level));
            fscanf(fop, "%d", &(toplist[cnt].score));
            fgets(toplist[cnt].cinfo, 40, fop);
            char *tmp = strstr(toplist[cnt].cinfo, "\n"); // 去掉末尾的\n
            if (tmp != NULL)
                *tmp = '\0';
            // if (cmpname(toplist[cnt].cinfo)) // 更新等级
            //     if (GmSts.lvl < toplist[cnt].level)
            //         GmSts.lvl = toplist[cnt].level;
            cnt++;
        }
    fclose(fop);
    rknumber = cnt;
}

void PrintRank()
{
    rkinfo *header = toplist;
    char outrank[6], outlvl[6], outscr[10], outputer[50], *workp;
    int lenthno = 0;
    SetPointSize(30);
    SetPenColor("Purple3");
    drawBox(0, 0, winwidth, winheight, 1, "", 's', "GREEN");
    SetPenColor("ZJUblue");
    drawBox(winwidth / 10, winheight * 8 / 10, winwidth / 10, winheight / 10, 1, "Rank", 's', "White");
    SetPenColor("ZJUblue");
    drawBox(winwidth * 2 / 10, winheight * 8 / 10, winwidth / 10, winheight / 10, 1, "Level", 's', "White");
    SetPenColor("ZJUblue");
    drawBox(winwidth * 3 / 10, winheight * 8 / 10, winwidth / 10, winheight / 10, 1, "Score", 's', "White");
    SetPenColor("ZJUblue");
    drawBox(winwidth * 4 / 10, winheight * 8 / 10, winwidth * 2 / 10, winheight / 10, 1, "Name", 's', "White");
    SetPenColor("ZJUblue");
    drawBox(winwidth * 6 / 10, winheight * 8 / 10, winwidth * 3 / 10, winheight / 10, 1, "Time", 's', "White");
    SetPointSize(22);
    while (lenthno < rknumber)
    {
        sprintf(outrank, "%d", lenthno + 1);
        sprintf(outlvl, "%d", header->level);
        sprintf(outscr, "%d", header->score);
        sprintf(outputer, "%s", header->cinfo);
        workp = strstr(outputer, "#");
        *workp = '\0';
        workp++;
        SetPenColor("Purple1");
        drawBox(winwidth * 1 / 10, winheight * 8 / 10 - winheight * (lenthno + 1) * 4 / 55, winwidth * 1 / 10, winheight / 10, 1, outrank, 's', "White");
        SetPenColor("Purple2");
        drawBox(winwidth * 2 / 10, winheight * 8 / 10 - winheight * (lenthno + 1) * 4 / 55, winwidth * 1 / 10, winheight / 10, 1, outlvl, 's', "White");
        SetPenColor("Purple2");
        drawBox(winwidth * 3 / 10, winheight * 8 / 10 - winheight * (lenthno + 1) * 4 / 55, winwidth * 1 / 10, winheight / 10, 1, outscr, 's', "White");
        SetPenColor("Purple2");
        drawBox(winwidth * 4 / 10, winheight * 8 / 10 - winheight * (lenthno + 1) * 4 / 55, winwidth * 2 / 10, winheight / 10, 1, outputer, 's', "White");
        SetPenColor("Purple2");
        drawBox(winwidth * 6 / 10, winheight * 8 / 10 - winheight * (lenthno + 1) * 4 / 55, winwidth * 3 / 10, winheight / 10, 1, workp, 's', "White");
        SetPenColor("Black");
        drawBox(winwidth * 1 / 10, winheight * 8 / 10 - winheight * (lenthno + 1) * 4 / 55, winwidth * 8 / 10, winheight / 10, 0, "", 's', "GREEN");
        lenthno++;
        if (lenthno == 10)
            break;
        header++;
    }
}

static void RkifCpy(rkinfo *a, rkinfo *b)
{
    strcpy(a->cinfo, b->cinfo);
    a->level = b->level;
    a->score = b->score;
}

static void RkifSwp(rkinfo *a, rkinfo *b)
{
    rkinfo c;
    strcpy(c.cinfo, b->cinfo);
    c.level = b->level;
    c.score = b->score;
    strcpy(b->cinfo, a->cinfo);
    b->level = a->level;
    b->score = a->score;
    strcpy(a->cinfo, c.cinfo);
    a->level = c.level;
    a->score = c.score;
}

void AddRank()
{
    INITCHECK(ifrankadded)
    time_t timer;
    timer = time(&timer);
    rkinfo *new = (rkinfo *)malloc(sizeof(rkinfo)), *header = &head, *tmphd;
    char tmp[35] = {"\0"}, tmp2[35] = {"\0"}, *tmp3;
    strcat(tmp2, GmSts.name);
    strcat(tmp2, "#");
    strcat(tmp2, ctime(&timer));
    tmp3 = strstr(tmp2, "\n");
    if (tmp3 != NULL)
        *tmp3 = '\0';
    strcpy(new->cinfo, tmp2);
    if (GmSts.lvl == 0)
        GmSts.lvl = 1;
    new->level = GmSts.lvl;
    new->score = GmSts.score;
    RkifCpy(&toplist[rknumber], new);
    rknumber++;

    int i, j, flag;
    for ( i = 0; i < rknumber; i++)
        for ( j = 0; j < rknumber - i - 1; j++)
        {
            flag = 0;
            if (toplist[j].level < toplist[j + 1].level)
                flag = 1;
            else if (toplist[j].level > toplist[j + 1].level)
                flag = 0;
            else if (toplist[j].level == toplist[j + 1].level)
            {
                if (toplist[j].score < toplist[j + 1].score)
                    flag = 1;
                else if (toplist[j].score > toplist[j + 1].score)
                    flag = 0;
            }
            if (flag)
                RkifSwp(&toplist[j], &toplist[j + 1]);
        }
}

void WriteRank()
{
    INITCHECK(ifrankwrtd)
    rkinfo *header = toplist;
    FILE *fop = fopen("rank.dat", "w");
    int cnt = 0;
    while (cnt < rknumber)
    {
        if (cnt == 10)
            break;
        if (cnt)
            fprintf(fop, "\n");
        fprintf(fop, "%3d %4d%s", header->level, header->score, header->cinfo);
        cnt++;
        header++;
    }
    fclose(fop);
}

static bool cmpname(char *infosrc)
{
    bool flag;
    char *mtmp, *cp;
    mtmp = strstr(infosrc, "#");
    *mtmp = '\0';
    cp = infosrc;
    if (strcmp(infosrc, GmSts.name) == 0)
        flag = 1;
    else
        flag = 0;
    *mtmp = '#';
    return flag;
}
