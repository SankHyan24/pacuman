#include "pmsp.h"
#include <stdlib.h>
//
//
#define CONFIRMFREE(a) \
    if (a != NULL)     \
        free(a);
ID *verhead = NULL;      //点表头
int noofver = 0;         //点数
struct SpEdge *edgehead; //边表头
IDnode *spheap;          //堆数组
int noofedge = 0;        //边数
int *sppath;             //前置顶点数组
int *spdis;              //最短距离数组
//下面是几个初始化辅助变量
static bool ifvertexget = 0;
static bool ifedgeget = 0;
static bool ifgraphget = 0;
static bool ifdjskrainit = 0;
//
static int n = 0;     // 堆中元素个数
static bool *sphadhp; //堆排序，是否进过堆
//
//
bool Spifpath(int Vertype)
{
    if (Vertype != Mp_wall)
        return 1;
    else
        return 0;
}

void SpCopyID(ID *a, ID *b)
{
    if (b == NULL)
        return;
    a->x = b->x;
    a->y = b->y;
}

ID *SpLocateVer(int x, int y)
{
    ID *workp = verhead;
    if (workp == NULL)
        exit(ER_VER_HD);
    int i;
    for (i = 0; i < noofver; i++)
        if ((workp + i)->x == x)
            if ((workp + i)->y == y)
                return workp + i;
    return NULL;
}

int SpContVer(int x, int y)
{
    ID *workp = verhead;
    if (workp == NULL)
        exit(ER_VER_HD);
    int i;
    for (i = 0; i < noofver; i++)
        if ((workp + i)->x == x)
            if ((workp + i)->y == y)
                return i;
    return EOF;
}

void SpGetVertex()
{
    INITCHECK(ifvertexget)
    noofver = 0;
    int i, j, vernumber = 0;
    for (i = 0; i < Length; i++)
        for (j = 0; j < Length; j++)
            if (Spifpath(Map[i][j]))
                noofver++;
    //锟斤拷锟斤拷锟斤拷锟节达拷
    verhead = (ID *)calloc(noofver, sizeof(ID));
    //锟斤拷锟斤拷锟斤拷锟?
    ID *workp = verhead;
    for (i = 0; i < Length; i++)
        for (j = 0; j < Length; j++)
            if (Spifpath(Map[i][j]))
            {
                (workp + vernumber)->x = i;
                (workp + vernumber)->y = j;
                vernumber++;
            }
    //锟斤拷锟斤拷锟斤拷锟?
    // for (i = 0; i < noofver; i++)
    // {
    //     printf("No.%2d: (%2d, %2d)\n", i, (workp + i)->x, (workp + i)->y);
    // }
}

void SpGetEdge()
{
    noofedge = Maxdge;
    // printf(" Number of  Edge 远来的%d", noofedge);
    edgehead = (struct SpEdge *)calloc(noofver * 4, sizeof(struct SpEdge));
    struct SpEdge *workp = edgehead;
    int cnti, cntj, cntm = 0, edgenumber = 0;
    for (cnti = 0; cnti < Length; cnti++)
        for (cntj = 0; cntj < Length; cntj++)
            if (Spifpath(Map[cnti][cntj]))
            {
                if (cnti == 0)
                {
                    if (Spifpath(Map[Length - 1][cntj]))
                    {
                        (workp + edgenumber)->dist = 1;
                        (workp + edgenumber)->fr = SpLocateVer(cnti, cntj);
                        (workp + edgenumber)->to = SpLocateVer(Length - 1, cntj);
                        edgenumber++;
                    }
                }
                else if (Spifpath(Map[cnti - 1][cntj]))
                {
                    (workp + edgenumber)->dist = 1;
                    (workp + edgenumber)->fr = SpLocateVer(cnti, cntj);
                    (workp + edgenumber)->to = SpLocateVer(cnti - 1, cntj);
                    edgenumber++;
                }
                if (cnti == Length - 1)
                {
                    if (Spifpath(Map[0][cntj]))
                    {
                        (workp + edgenumber)->dist = 1;
                        (workp + edgenumber)->fr = SpLocateVer(cnti, cntj);
                        (workp + edgenumber)->to = SpLocateVer(0, cntj);
                        edgenumber++;
                    }
                }
                else if (Spifpath(Map[cnti + 1][cntj]))
                {
                    (workp + edgenumber)->dist = 1;
                    (workp + edgenumber)->fr = SpLocateVer(cnti, cntj);
                    (workp + edgenumber)->to = SpLocateVer(cnti + 1, cntj);
                    edgenumber++;
                }
                if (cntj == 0)
                {
                    if (Spifpath(Map[cnti][Length - 1]))
                    {
                        (workp + edgenumber)->dist = 1;
                        (workp + edgenumber)->fr = SpLocateVer(cnti, cntj);
                        (workp + edgenumber)->to = SpLocateVer(cnti, Length - 1);
                        edgenumber++;
                    }
                }
                else if (Spifpath(Map[cnti][cntj - 1]))
                {
                    (workp + edgenumber)->dist = 1;
                    (workp + edgenumber)->fr = SpLocateVer(cnti, cntj);
                    (workp + edgenumber)->to = SpLocateVer(cnti, cntj - 1);
                    edgenumber++;
                }
                if (cntj == Length - 1)
                {
                    if (Spifpath(Map[cnti][0]))
                    {
                        (workp + edgenumber)->dist = 1;
                        (workp + edgenumber)->fr = SpLocateVer(cnti, cntj);
                        (workp + edgenumber)->to = SpLocateVer(cnti, 0);
                        edgenumber++;
                    }
                }
                else if (Spifpath(Map[cnti][cntj + 1]))
                {
                    (workp + edgenumber)->dist = 1;
                    (workp + edgenumber)->fr = SpLocateVer(cnti, cntj);
                    (workp + edgenumber)->to = SpLocateVer(cnti, cntj + 1);
                    edgenumber++;
                }
            }
    noofedge = edgenumber;
    // printf(" Number of  Edge 后来的%d", noofedge);

    // for (cnti = 0; cnti < edgenumber; cnti++)
    // printf("No.%2d: (%2d, %2d) -> (%2d, %2d)\n", cnti, (workp + cnti)->fr->x, (workp + cnti)->fr->y, (workp + cnti)->to->x, (workp + cnti)->to->y);
}

void SpInitDjskra()
{
    INITCHECK(ifdjskrainit)
    int cnti;
    spheap = NULL;
    sphadhp = (bool *)calloc(noofver, sizeof(bool));
    spdis = (int *)calloc(noofver, sizeof(int));
    sppath = (int *)calloc(noofver, sizeof(int));
    for (cnti = 0; cnti < noofver; cnti++)
        spdis[cnti] = MAXDIST;
}

void SpCreateGraph()
{
    SpGetVertex();
    SpGetEdge();
}

void SpShortPath(ID *StartVer)
{
    SpInitDjskra();
    struct SpEdge *workp = edgehead;
    ID *nodep = verhead;
    int nodenumber = noofver;
    int edgenumber = noofedge;
    int i, j, k;
    IDnode xstart;
    xstart.node = StartVer;
    xstart.data = 0;
    spheap = (IDnode *)calloc(nodenumber, sizeof(IDnode));
    spdis[SpContVer(xstart.node->x, xstart.node->y)] = 0;
    push(xstart);
    while (n != 0)
    {
        IDnode t = spheap[1];
        pop();
        int vernum = SpContVer(t.node->x, t.node->y);
        sphadhp[vernum] = 1;
        for (j = 0; j < edgenumber; j++)
            if (vernum == SpContVer(workp[j].fr->x, workp[j].fr->y))
            {
                int y = SpContVer(workp[j].to->x, workp[j].to->y);
                int yy = spdis[vernum] + workp[j].dist;
                if (sphadhp[y] == 1)
                    continue;
                if (spdis[y] > yy)
                {
                    spdis[y] = yy;
                    IDnode into;
                    into.data = yy;
                    into.node = nodep + y;
                    push(into);
                    sppath[y] = vernum;
                }
            }
    }
}

void SpReinit()
{
    ifgraphget = 0;
    CONFIRMFREE(verhead)
    CONFIRMFREE(edgehead)
    SpDjReinit();
    ifvertexget = 0;
    ifedgeget = 0;
}

void SpDjReinit()
{
    CONFIRMFREE(spheap)
    CONFIRMFREE(sppath)
    CONFIRMFREE(spdis)
    CONFIRMFREE(sphadhp)
    ifdjskrainit = 0;
}
// App
ID *SpFstStp(ID *FROM, ID *TO)
{
    SpShortPath(FROM);
    int destination = SpContVer(TO->x, TO->y);
    int mindis = spdis[destination];
    int minnum = SpContVer(FROM->x, FROM->y);
    SpDjReinit();
    int tmpnumber;

    if (FROM->x + 1 == Length)
    {
        tmpnumber = SpContVer(0, FROM->y);
        if (tmpnumber != EOF)
        {
            SpShortPath(verhead + tmpnumber);
            if (spdis[destination] < mindis)
            {
                mindis = spdis[destination];
                minnum = tmpnumber;
            }
            SpDjReinit();
        }
    }
    else
    {
        tmpnumber = SpContVer(FROM->x + 1, FROM->y);
        if (tmpnumber != EOF)
        {
            SpShortPath(verhead + tmpnumber);
            if (spdis[destination] < mindis)
            {
                mindis = spdis[destination];
                minnum = tmpnumber;
            }
            SpDjReinit();
        }
    }
    //

    if (FROM->x == 0)
    {
        tmpnumber = SpContVer(Length - 1, FROM->y);
        if (tmpnumber != EOF)
        {
            SpShortPath(verhead + tmpnumber);
            if (spdis[destination] < mindis)
            {
                mindis = spdis[destination];
                minnum = tmpnumber;
            }
            SpDjReinit();
        }
    }
    else
    {
        tmpnumber = SpContVer(FROM->x - 1, FROM->y);
        if (tmpnumber != EOF)
        {
            SpShortPath(verhead + tmpnumber);
            if (spdis[destination] < mindis)
            {
                mindis = spdis[destination];
                minnum = tmpnumber;
            }
            SpDjReinit();
        }
    }
    //
    if (FROM->y + 1 == Length)
    {
        tmpnumber = SpContVer(FROM->x, 0);
        if (tmpnumber != EOF)
        {
            SpShortPath(verhead + tmpnumber);
            if (spdis[destination] < mindis)
            {
                mindis = spdis[destination];
                minnum = tmpnumber;
            }
            SpDjReinit();
        }
    }
    else
    {
        tmpnumber = SpContVer(FROM->x, FROM->y + 1);
        if (tmpnumber != EOF)
        {
            SpShortPath(verhead + tmpnumber);
            if (spdis[destination] < mindis)
            {
                mindis = spdis[destination];
                minnum = tmpnumber;
            }
            SpDjReinit();
        }
    }
    //
    if (FROM->y == 0)
    {
        tmpnumber = SpContVer(FROM->x, Length - 1);
        if (tmpnumber != EOF)
        {
            SpShortPath(verhead + tmpnumber);
            if (spdis[destination] < mindis)
            {
                mindis = spdis[destination];
                minnum = tmpnumber;
            }
            SpDjReinit();
        }
    }
    else
    {
        tmpnumber = SpContVer(FROM->x, FROM->y - 1);
        if (tmpnumber != EOF)
        {
            SpShortPath(verhead + tmpnumber);
            if (spdis[destination] < mindis)
            {
                mindis = spdis[destination];
                minnum = tmpnumber;
            }
            SpDjReinit();
        }
    }
    return (verhead + minnum);
}
ID *SpAntiFS(ID *FROM, ID *TO)
{
    SpShortPath(FROM);
    int destination = SpContVer(TO->x, TO->y);
    int mindis = spdis[destination];
    int minnum = SpContVer(FROM->x, FROM->y);
    SpDjReinit();
    int tmpnumber;

    if (FROM->x + 1 == Length)
    {
        tmpnumber = SpContVer(0, FROM->y);
        if (tmpnumber != EOF)
        {
            SpShortPath(verhead + tmpnumber);
            if (spdis[destination] > mindis)
            {
                mindis = spdis[destination];
                minnum = tmpnumber;
            }
            SpDjReinit();
        }
    }
    else
    {
        tmpnumber = SpContVer(FROM->x + 1, FROM->y);
        if (tmpnumber != EOF)
        {
            SpShortPath(verhead + tmpnumber);
            if (spdis[destination] > mindis)
            {
                mindis = spdis[destination];
                minnum = tmpnumber;
            }
            SpDjReinit();
        }
    }
    //

    if (FROM->x == 0)
    {
        tmpnumber = SpContVer(Length - 1, FROM->y);
        if (tmpnumber != EOF)
        {
            SpShortPath(verhead + tmpnumber);
            if (spdis[destination] > mindis)
            {
                mindis = spdis[destination];
                minnum = tmpnumber;
            }
            SpDjReinit();
        }
    }
    else
    {
        tmpnumber = SpContVer(FROM->x - 1, FROM->y);
        if (tmpnumber != EOF)
        {
            SpShortPath(verhead + tmpnumber);
            if (spdis[destination] > mindis)
            {
                mindis = spdis[destination];
                minnum = tmpnumber;
            }
            SpDjReinit();
        }
    }
    //
    if (FROM->y + 1 == Length)
    {
        tmpnumber = SpContVer(FROM->x, 0);
        if (tmpnumber != EOF)
        {
            SpShortPath(verhead + tmpnumber);
            if (spdis[destination] > mindis)
            {
                mindis = spdis[destination];
                minnum = tmpnumber;
            }
            SpDjReinit();
        }
    }
    else
    {
        tmpnumber = SpContVer(FROM->x, FROM->y + 1);
        if (tmpnumber != EOF)
        {
            SpShortPath(verhead + tmpnumber);
            if (spdis[destination] > mindis)
            {
                mindis = spdis[destination];
                minnum = tmpnumber;
            }
            SpDjReinit();
        }
    }
    //
    if (FROM->y == 0)
    {
        tmpnumber = SpContVer(FROM->x, Length - 1);
        if (tmpnumber != EOF)
        {
            SpShortPath(verhead + tmpnumber);
            if (spdis[destination] > mindis)
            {
                mindis = spdis[destination];
                minnum = tmpnumber;
            }
            SpDjReinit();
        }
    }
    else
    {
        tmpnumber = SpContVer(FROM->x, FROM->y - 1);
        if (tmpnumber != EOF)
        {
            SpShortPath(verhead + tmpnumber);
            if (spdis[destination] > mindis)
            {
                mindis = spdis[destination];
                minnum = tmpnumber;
            }
            SpDjReinit();
        }
    }
    return (verhead + minnum);
}
// Heap
void swap(IDnode *a, IDnode *b)
{
    IDnode c;
    c = *a;
    *a = *b;
    *b = c;
}
void up(int p) // helper
{
    while (p > 1)
    {
        if (spheap[p].data < spheap[p / 2].data) //    Wait
        {
            swap(&spheap[p], &spheap[p / 2]);
            p = p / 2;
        }
        else
            break;
    }
}
void push(IDnode x)
{
    spheap[++n] = x;
    up(n);
}
void down(int p) // helper
{
    int s = p * 2;
    while (s <= n)
    {
        if (s < n && spheap[s].data > spheap[s + 1].data)
            s++;
        if (spheap[s].data < spheap[p].data)
        {
            swap(&spheap[s], &spheap[p]);
            p = s;
            s = p * 2;
        }
        else
            break;
    }
}
void pop()
{
    spheap[1] = spheap[n--];
    down(1);
}