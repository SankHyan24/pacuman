#include "pmeditor.h"
#include "global.h"
#include "pmgame.h"

int mpedictrl;
bool ifmecc = 0;
bool ifmapedinit = 0;
short *mpedist;
ID mpchsps;

bool mapifkey(int key, int event)
{
    if (launchselecter == MENU_EDIT && event == KEY_DOWN)
    {
        if (key == VK_UP)
            return 1;
        if (key == VK_DOWN)
            return 1;
        if (key == VK_LEFT)
            return 1;
        if (key == VK_RIGHT)
            return 1;
        if (key == 'Q')
            return 1;
        if (key == 'W')
            return 1;
        if (key == 'E')
            return 1;
        if (key == 'R')
            return 1;
    }
    else
        return 0;
}

void mapedinit()
{

    if (ifmapedinit)
        return;
    Length = Inivation("s");
    GetMaxN();
    mpchsps.x = Length / 2;
    mpchsps.y = Length / 2;
    ifmapedinit = 1;
    mpedist = (short *)malloc(sizeof(short) * Length * Length);
    int i, j;
    for (i = 0; i < Length; i++)
        for (j = 0; j < Length; j++)
            *(mpedist + i * Length + j) = (short)Map[i][j];
}

void mapprint()
{

    SetPenColor("Gray");
    drawBox(0, 0, winwidth, winheight, 1, "", 's', "White");
    SetPenColor("Black");
    SetPointSize(30);
    drawBox(winwidth * 3 / 10, 0, winwidth * 2 / 5, winheight / 12 - 0.1, 1, "上下左右调方向，Q路W墙E吃豆人R鬼", 's', "Azure");
    SetPenColor("Black");
    drawBox(winwidth * 1 / 5, winheight * 11 / 12, winwidth * 3 / 5, winheight / 12, 1, "Map Editor", 's', "White");
    SetPointSize(13);
    SetPenColor("White");
    drawBox(winwidth / 12 - 0.1, winheight / 12 - 0.1, winwidth * 10 / 12 + 0.2, winheight * 10 / 12 + 0.2, 1, "", 's', "White");
    SetPenColor("White");
    drawBox(winwidth / 12, winheight / 12, winwidth * 5 / 6, winheight * 5 / 6, 1, "", 's', "BLACK");
    double startx = winwidth / 12, starty = winheight / 12;
    double dx = winwidth * 10 / (12 * Length), dy = winheight * 10 / (12 * Length);
    // MAP
    int cnti, cntj;
    for (cnti = 0; cnti < Length; cnti++)
        for (cntj = 0; cntj < Length; cntj++)
        {
            if (cnti == mpchsps.x && cntj == mpchsps.y && BlinkCtrlor(15, 0.5))
                SetPenColor("Azure");
            else if (*(mpedist + cnti * Length + cntj) == Mp_way)
                SetPenColor("Black");
            else if (*(mpedist + cnti * Length + cntj) == Mp_wall)
                SetPenColor("ZJUblue");
            else if (*(mpedist + cnti * Length + cntj) == Mp_start)
                SetPenColor("Green");
            else if (*(mpedist + cnti * Length + cntj) == Mp_Ghst)
                SetPenColor("ZJUred");
            drawBox(startx + cntj * dx, starty + cnti * dy, dx, dy, 1, "", 's', "White");
        }
}

void mapchose()
{
    if (!ifmecc)
        return;
    ifmecc = 0;
    switch (mpedictrl)
    {
    case VK_UP:
        if (mpchsps.x == Length - 1)
            return;
        else
            mpchsps.x++;
        break;
    case VK_DOWN:
        if (mpchsps.x == 0)
            return;
        else
            mpchsps.x--;
        break;
    case VK_LEFT:
        if (mpchsps.y == 0)
            return;
        else
            mpchsps.y--;
        break;
    case VK_RIGHT:
        if (mpchsps.y == Length - 1)
            return;
        else
            mpchsps.y++;
        break;
    case 'Q':
        *(mpedist + mpchsps.x * Length + mpchsps.y) = Mp_way;
        break;
    case 'W':
        *(mpedist + mpchsps.x * Length + mpchsps.y) = Mp_wall;
        break;
    case 'E':
        *(mpedist + mpchsps.x * Length + mpchsps.y) = Mp_start;
        break;
    case 'R':
        *(mpedist + mpchsps.x * Length + mpchsps.y) = Mp_Ghst;
        break;
    default:
        break;
    }
}

void mapwrite()
{
    char stroffile[30] = "lv", houzhui[6] = ".pmm", xuhao[4];
    if (GmSts.lvl == 0)
        GmSts.lvl = 1;
    sprintf(xuhao, "%d", GmSts.lvl);
    strcat(stroffile, xuhao);
    strcat(stroffile, houzhui);
    FILE *fcg = fopen(stroffile, "w");
    int i, j;
    for (i = 0; i < Length; i++)
    {
        for (j = 0; j < Length; j++)
        {
            fprintf(fcg, "%d", *(mpedist + i * Length + j));
        }
        fprintf(fcg, "\n");
    }
    fclose(fcg);
    free(mpedist);
    Length = Inivation("S");
    ifmapedinit = 0;
}
