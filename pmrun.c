#include "pmrun.h"
#include "pmgame.h"
#include "pmrank.h"
#include "pmeditor.h"
#include <stdlib.h>
#include "graphics.h"
#include "pmhelp.h"
#define Recursion1(a)               \
    do                              \
    {                               \
        int plyy = GmSts.player->x; \
        int plyx = GmSts.player->y; \
        GmSts.ifmv = 0;             \
        a                           \
    } while (GmSts.ifmv && cnt < 10); //*迭代过程
#define RANKAD       \
    ifrankadded = 0; \
    GetRank();       \
    ifrankadded = 0; \
    AddRank();       \
    ifrankwrtd = 0;  \
    WriteRank(); //*排行榜添加的标准格式
bool timlopflag = 0;
bool timghstflag = 0;
bool newbeeflag = 0;
int runmvctrl;
int alittlegg = 0;

void DeletPea() // 删除吃豆人所在位置的豆子
{
    int plyx = GmSts.player->x, plyy = GmSts.player->y;
    int lens = GmSts.Lens;
    if (*(GmSts.map + plyx * lens + plyy) == Mp_pea)
    {
        *(GmSts.map + plyx * lens + plyy) = Mp_way;
        GmSts.score++;
        if (GmSts.skin == Skin_hulk1)
        {
            if (energy != 20)
                energy++;
        }
        if (GmSts.skin == Skin_flash)
        {
            if (energy != 15)
                energy++;
        }
    }
}

bool runifkey(int key, int event) // 判断是否是对应操作的键盘
{
    if (launchselecter == MENU_GMAP && event == KEY_DOWN)
    {
        if (key == VK_UP)
            return 1;
        if (key == VK_DOWN)
            return 1;
        if (key == VK_LEFT)
            return 1;
        if (key == VK_RIGHT)
            return 1;
        if (key == 'W')
            return 1;
        if (key == ' ')
            return 1;
        // if (key == 'A')
        //     return 1;
        // if (key == 'S')
        //     return 1;
        // if (key == 'D')
        //     return 1;
    }
    else
        return 0;
}

void Changedir()
{
    if (!ifmecc)
        return;
    ifmecc = 0;
    if (energy == 0 && GmSts.skin == Skin_hulk2 && alittlegg == 0)
    {
        GmSts.skin = Skin_hulk1;
    }
    if (GmSts.skin == Skin_hulk2)
    {

        if (energy >= 3)
            energy -= 3;
        else
            energy = 0;
    }
    switch (runmvctrl)
    {
    case VK_UP:
        GmSts.plyrd = Dir_up;
        break;
    case ' ':
    {
        int plyy = GmSts.player->x;
        int plyx = GmSts.player->y;
        int lens = GmSts.Lens;
        {
            if (GmSts.skin == Skin_hulk1 && energy == 20)
                GmSts.skin = Skin_hulk2;
            if (GmSts.skin == Skin_flash && energy == 15)
            {
                int cnt = 0;
                switch (GmSts.plyrd)
                {
                case Dir_up:
                    Recursion1(
                        if (plyy == lens - 1)
                        {
                            if (SpLocateVer(0, plyx) != NULL)
                            {
                                GmSts.player = SpLocateVer(0, plyx);
                                GmSts.ifmv = 1;
                                cnt++;
                            }
                        } else if (SpLocateVer(plyy + 1, plyx) != NULL)
                        {
                            GmSts.player = SpLocateVer(plyy + 1, plyx);
                            cnt++;
                            GmSts.ifmv = 1;
                        } DeletPea();) break;
                case Dir_down:
                    Recursion1(
                        if (plyy == 0)
                        {
                            if (SpLocateVer(lens - 1, plyx) != NULL)
                            {
                                GmSts.player = SpLocateVer(lens - 1, plyx);
                                cnt++;
                                GmSts.ifmv = 1;
                            }
                        } else if (SpLocateVer(plyy - 1, plyx) != NULL)
                        {
                            GmSts.player = SpLocateVer(plyy - 1, plyx);
                            cnt++;
                            GmSts.ifmv = 1;
                        } DeletPea();) break;
                case Dir_left:
                    Recursion1(
                        if (plyx == 0)
                        {
                            if (SpLocateVer(plyy, lens - 1) != NULL)
                            {
                                GmSts.player = SpLocateVer(plyy, lens - 1);
                                cnt++;
                                GmSts.ifmv = 1;
                            }
                        } else if (SpLocateVer(plyy, plyx - 1) != NULL)
                        {
                            GmSts.player = SpLocateVer(plyy, plyx - 1);
                            cnt++;
                            GmSts.ifmv = 1;
                        } DeletPea();) break;
                case Dir_right:
                    Recursion1(
                        if (plyx == lens - 1)
                        {
                            if (SpLocateVer(plyy, 0) != NULL)
                            {
                                GmSts.player = SpLocateVer(plyy, 0);
                                cnt++;
                                GmSts.ifmv = 1;
                            }
                        } else if (SpLocateVer(plyy, plyx + 1) != NULL)
                        {
                            GmSts.player = SpLocateVer(plyy, plyx + 1);
                            cnt++;
                            GmSts.ifmv = 1;
                        } DeletPea();) break;
                default:
                    break;
                }
                energy = 0;
            }
            break;
        }
    }
    case VK_DOWN:
        GmSts.plyrd = Dir_down;
        break;
    case VK_LEFT:
        GmSts.plyrd = Dir_left;
        break;
    case VK_RIGHT:
        GmSts.plyrd = Dir_right;
        break;
    default:
        break;
    }
}

int Juli(ID *a, ID *b)
{
    return (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y);
}

void MoveMan()
{
    if (!timlopflag)
        return;
    durstepply = 0;
    GmSts.ifmv = 0;
    int plyy = GmSts.player->x;
    int plyx = GmSts.player->y;
    int *wkp = GmSts.map;
    int lens = GmSts.Lens;
    switch (GmSts.plyrd)
    {
    case Dir_up:
        if (plyy == lens - 1)
        {
            if (SpLocateVer(0, plyx) != NULL)
            {
                GmSts.player = SpLocateVer(0, plyx);
                GmSts.ifmv = 1;
            }
        }
        else if (SpLocateVer(plyy + 1, plyx) != NULL)
        {
            GmSts.player = SpLocateVer(plyy + 1, plyx);
            GmSts.ifmv = 1;
        }
        break;
    case Dir_down:
        if (plyy == 0)
        {
            if (SpLocateVer(lens - 1, plyx) != NULL)
            {
                GmSts.player = SpLocateVer(lens - 1, plyx);
                GmSts.ifmv = 1;
            }
        }
        else if (SpLocateVer(plyy - 1, plyx) != NULL)
        {
            GmSts.player = SpLocateVer(plyy - 1, plyx);
            GmSts.ifmv = 1;
        }
        break;
    case Dir_left:
        if (plyx == 0)
        {
            if (SpLocateVer(plyy, lens - 1) != NULL)
            {
                GmSts.player = SpLocateVer(plyy, lens - 1);
                GmSts.ifmv = 1;
            }
        }
        else if (SpLocateVer(plyy, plyx - 1) != NULL)
        {
            GmSts.player = SpLocateVer(plyy, plyx - 1);
            GmSts.ifmv = 1;
        }
        break;
    case Dir_right:
        if (plyx == lens - 1)
        {
            if (SpLocateVer(plyy, 0) != NULL)
            {
                GmSts.player = SpLocateVer(plyy, 0);
                GmSts.ifmv = 1;
            }
        }
        else if (SpLocateVer(plyy, plyx + 1) != NULL)
        {
            GmSts.player = SpLocateVer(plyy, plyx + 1);
            GmSts.ifmv = 1;
        }
        break;
    default:
        break;
    }
    DeletPea();
    timlopflag = 0;
}

static void ChangeGhstDir(Dir *dir)
{
    if (*dir == Dir_up)
        *dir = Dir_left;
    else if (*dir == Dir_down)
        *dir = Dir_right;
    else if (*dir == Dir_right)
        *dir = Dir_up;
    else if (*dir == Dir_left)
        *dir = Dir_down;
}

void AiChase(int gstid) // 追逐
{
    ID *fromposi = GmSts.ghst[gstid];
    ID *nextposi = SpFstStp(GmSts.ghst[gstid], GmSts.player);
    GmSts.ghstd[gstid] = Juge_Dir(*fromposi, *nextposi);
    GmSts.ghst[gstid] = nextposi;
    ChangeGhstDir(&GmSts.ghstd[gstid]);
}

void AiWonder(int gstid) // 随机溜达
{
    int randm, posi;
    int plyy = GmSts.ghst[gstid]->x;
    int plyx = GmSts.ghst[gstid]->y;
    int lens = GmSts.Lens;
    int mvflag = 0;
    do
    {
        randm = rand() % 4;
        switch (randm)
        {
        case Dir_up:
            if (plyy == lens - 1)
            {
                if (SpLocateVer(0, plyx) != NULL)
                {
                    GmSts.ghst[gstid] = SpLocateVer(0, plyx);
                    mvflag = 1;
                }
            }
            else if (SpLocateVer(plyy + 1, plyx) != NULL)
            {
                GmSts.ghst[gstid] = SpLocateVer(plyy + 1, plyx);
                mvflag = 1;
            }
            break;
        case Dir_down:
            if (plyy == 0)
            {
                if (SpLocateVer(lens - 1, plyx) != NULL)
                {
                    GmSts.ghst[gstid] = SpLocateVer(lens - 1, plyx);
                    mvflag = 1;
                }
            }
            else if (SpLocateVer(plyy - 1, plyx) != NULL)
            {
                GmSts.ghst[gstid] = SpLocateVer(plyy - 1, plyx);
                mvflag = 1;
            }
            break;
        case Dir_left:
            if (plyx == 0)
            {
                if (SpLocateVer(plyy, lens - 1) != NULL)
                {
                    GmSts.ghst[gstid] = SpLocateVer(plyy, lens - 1);
                    mvflag = 1;
                }
            }
            else if (SpLocateVer(plyy, plyx - 1) != NULL)
            {
                GmSts.ghst[gstid] = SpLocateVer(plyy, plyx - 1);
                mvflag = 1;
            }
            break;
        case Dir_right:
            if (plyx == lens - 1)
            {
                if (SpLocateVer(plyy, 0) != NULL)
                {
                    GmSts.ghst[gstid] = SpLocateVer(plyy, 0);
                    mvflag = 1;
                }
            }
            else if (SpLocateVer(plyy, plyx + 1) != NULL)
            {
                GmSts.ghst[gstid] = SpLocateVer(plyy, plyx + 1);
                mvflag = 1;
            }
            break;
        default:
            break;
        }
    } while (!mvflag);
    GmSts.ghstd[gstid] = randm;
}

void AiAmbush(int gstid) // 埋伏
{
    ID *a = GmSts.ghst[gstid], *b = GmSts.player;
    Juli(a, b) < 8 ? AiChase(gstid) : AiWonder(gstid);
}

void AiPreTen(int gstid) // 假装抓人
{
    ID *a = GmSts.ghst[gstid], *b = GmSts.player;
    Juli(a, b) > 8 ? AiChase(gstid) : AiWonder(gstid);
}

void AiRun(int gstid)
{
    ID *fromposi = GmSts.ghst[gstid];
    ID *nextposi = SpAntiFS(GmSts.ghst[gstid], GmSts.player);
    GmSts.ghstd[gstid] = Juge_Dir(*fromposi, *nextposi);
    GmSts.ghst[gstid] = nextposi;
    ChangeGhstDir(&GmSts.ghstd[gstid]);
}

void MoveGst(int gstid, int mode)
{

    switch (mode)
    {
    case MvChase:
        AiChase(gstid);
        break;
    case MvWonder:
        AiWonder(gstid);
        break;
    case MvAmbush:
        AiAmbush(gstid);
        break;
    case Mvpret:
        AiPreTen(gstid);
        break;
    case MvRun:
        AiRun(gstid);
        break;
    default:
        break;
    }
}

void Lost_Win() // 判断胜利或者失败，并进行相应操作
{
    int i;
    if (GmSts.score == GmSts.scoregoal) // 胜利
    {
        RANKAD
        free(GmSts.map);
        winorlost = 1;
        alittlegg = 0;
        launchselecter = MENU_WORL;
        return;
    }
    else if (GmSts.skin == Skin_hulk2)
    {
        for (i = 0; i < 4; i++)
        {
            if (GmSts.ifghst[i])
                if (Juli(GmSts.ghst[i], GmSts.player) == 1) // 对撞情况死亡特判
                {
                    bool flag = 1;
                    if (GmSts.ghstd[i] == Dir_down && GmSts.plyrd == Dir_up)
                        flag = 1;
                    if (GmSts.ghstd[i] == Dir_up && GmSts.plyrd == Dir_down)
                        flag = 1;
                    if (GmSts.ghstd[i] == Dir_left && GmSts.plyrd == Dir_right)
                        flag = 1;
                    if (GmSts.ghstd[i] == Dir_right && GmSts.plyrd == Dir_left)
                        flag = 1;
                    if (flag)
                    {
                        GmSts.ifghst[i] = 0;
                        GmSts.score += 5;
                    }
                }
                else if (GmSts.ghst[i]->x == GmSts.player->x)
                    if (GmSts.ghst[i]->y == GmSts.player->y)
                    {
                        GmSts.ifghst[i] = 0;
                        GmSts.score += 5;
                    }
        }
    }
    else
        for (i = 0; i < 4; i++)
        {
            if (GmSts.ifghst[i])
                if (Juli(GmSts.ghst[i], GmSts.player) == 2) // 对撞情况死亡特判
                {
                    bool flag = 0;
                    if (GmSts.ghstd[i] == Dir_down && GmSts.plyrd == Dir_up)
                        flag = 1;
                    if (GmSts.ghstd[i] == Dir_up && GmSts.plyrd == Dir_down)
                        flag = 1;
                    if (GmSts.ghstd[i] == Dir_left && GmSts.plyrd == Dir_right)
                        flag = 1;
                    if (GmSts.ghstd[i] == Dir_right && GmSts.plyrd == Dir_left)
                        flag = 1;
                    if (flag)
                    {
                        RANKAD
                        free(GmSts.map);
                        winorlost = 0;
                        launchselecter = MENU_WORL;
                        return;
                    }
                }
                else if (GmSts.ghst[i]->x == GmSts.player->x)
                    if (GmSts.ghst[i]->y == GmSts.player->y)
                    {
                        RANKAD
                        free(GmSts.map);
                        winorlost = 0;
                        launchselecter = MENU_WORL;
                        return;
                    }
        }
}
