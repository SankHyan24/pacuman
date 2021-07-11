// By scitbb
#include <math.h>
#include <time.h>
#include "pmanima.h"
#include "pmdirrt.h"
#include "graphics.h"
#include "global.h"
#include "pmgame.h"

bool BlinkCtrlor(int T, double t)
{
    if ((t - 1.0) >= 1e-7)
        return 1;
    return (animatimer % (T) <= T * t);
}

void DrawECircle(double cx, double cy, double rx, double ry, string color, int fillflag)
{
    SetPenColor(color);
    MovePen(cx + rx, cy);
    if (fillflag)
        StartFilledRegion(1);
    DrawEllipticalArc(rx, ry, 0, 360);
    if (fillflag)
        EndFilledRegion();
}

void DrawGhost(double cx, double cy, double size, string color, Dir dir)
{
    double r = size / 2;

    SetPenColor(color);
    if (GmSts.skin == Skin_hulk2)
    {
        r *= 0.8;
        SetPenColor("ZJUblue");
    }
    MovePen(cx + r, cy);
    StartFilledRegion(1);
    DrawArc(r, 0, 180);
    DrawLine(0, -r * 3 / 4);
    DrawLine(size, 0);
    DrawLine(0, +r * 3 / 4);
    EndFilledRegion();

    MovePen(cx - r, cy - r * 3 / 4);
    StartFilledRegion(1);
    DrawArc(r / 4, 180, 180);
    DrawArc(r / 4, 180, 180);
    DrawArc(r / 4, 180, 180);
    DrawArc(r / 4, 180, 180);
    EndFilledRegion();

    DrawECircle(cx - r / 2, cy + r / 4, r / 4, r / 4, "White", 1);
    DrawECircle(cx + r / 2, cy + r / 4, r / 4, r / 4, "White", 1);
    if (GmSts.skin != Skin_hulk2)
        switch (dir)
        {
        case Dir_up:
            DrawECircle(cx - r / 2, cy + r / 4 + r / 8, r / 8, r / 4, "BLACK", 1);
            DrawECircle(cx + r / 2, cy + r / 4 + r / 8, r / 8, r / 4, "BLACK", 1);
            break;
        case Dir_down:
            DrawECircle(cx - r / 2, cy + r / 4 - r / 8, r / 8, r / 4, "BLACK", 1);
            DrawECircle(cx + r / 2, cy + r / 4 - r / 8, r / 8, r / 4, "BLACK", 1);
            break;
        case Dir_right:
            DrawECircle(cx - r / 2 + r / 8, cy + r / 4, r / 8, r / 4, "BLACK", 1);
            DrawECircle(cx + r / 2 + r / 8, cy + r / 4, r / 8, r / 4, "BLACK", 1);
            break;
        case Dir_left:
            DrawECircle(cx - r / 2 - r / 8, cy + r / 4, r / 8, r / 4, "BLACK", 1);
            DrawECircle(cx + r / 2 - r / 8, cy + r / 4, r / 8, r / 4, "BLACK", 1);
            break;

        default:
            break;
        }
}
void DrawBlinky(double cx, double cy, double size, Dir dir)
{
    DrawGhost(cx, cy, size, "ZJUred", dir);
}
void DrawPinky(double cx, double cy, double size, Dir dir)
{
    DrawGhost(cx, cy, size, "Pink", dir);
}
void DrawInky(double cx, double cy, double size, Dir dir)
{
    DrawGhost(cx, cy, size, "Azure", dir);
}
void DrawClyde(double cx, double cy, double size, Dir dir)
{
    DrawGhost(cx, cy, size, "Orange", dir);
}

void DrawEater(double cx, double cy, double size, int direct, string background, int skin)
{
    if (skin == Skin_plain)
        SetPenColor("Yellow");
    else if (skin == Skin_hulk1)
        SetPenColor("Meat");
    else if (skin == Skin_hulk2)
        SetPenColor("Green1");
    else if (skin == Skin_flash)
        SetPenColor("White");
    double arc = 1.0 * (animatimer % 60);
    if (arc >= 60)
        arc = 0;
    else
        arc = arc + 2;
    double r = size, dx, dy;
    if (skin == Skin_hulk1)
        r *= 0.9;
    if (skin == Skin_hulk2)
        r *= 1.2;
    dx = r * sin(arc / piepie);
    dy = r * cos(arc / piepie);
    MovePen(cx + r, cy);
    StartFilledRegion(1);
    DrawArc(r, 0, 360);
    EndFilledRegion();
    SetPenColor(background);
    MovePen(cx, cy);
    switch (direct)
    {
    case Dir_left:
        StartFilledRegion(1);
        DrawLine(-r, dy);
        DrawLine(0, -2 * dy);
        DrawLine(r, dy);
        EndFilledRegion();
        if (skin == Skin_hulk1 || skin == Skin_hulk2)
        {
            DrawECircle(cx, cy + r / 2, r / 4, r / 4, "White", 1);
            DrawECircle(cx, cy + r / 2, r / 6, r / 6, "Black", 1);
        }
        break;
    case Dir_right:
        StartFilledRegion(1);
        DrawLine(r, dy);
        DrawLine(0, -2 * dy);
        DrawLine(-r, dy);
        EndFilledRegion();
        if (skin == Skin_hulk1 || skin == Skin_hulk2)
        {
            DrawECircle(cx, cy + r / 2, r / 4, r / 4, "White", 1);
            DrawECircle(cx, cy + r / 2, r / 6, r / 6, "Black", 1);
        }
        break;
    case Dir_up:
        StartFilledRegion(1);
        DrawLine(-dx, r);
        DrawLine(2 * dx, 0);
        DrawLine(-dx, -r);
        EndFilledRegion();
        if (skin == Skin_hulk1 || skin == Skin_hulk2)
        {
            DrawECircle(cx + r / 2, cy, r / 4, r / 4, "White", 1);
            DrawECircle(cx + r / 2, cy, r / 6, r / 6, "Black", 1);
        }
        break;
    case Dir_down:
        StartFilledRegion(1);
        DrawLine(-dx, -r);
        DrawLine(2 * dx, 0);
        DrawLine(-dx, r);
        EndFilledRegion();
        if (skin == Skin_hulk1 || skin == Skin_hulk2)
        {
            DrawECircle(cx + r / 2, cy, r / 4, r / 4, "White", 1);
            DrawECircle(cx + r / 2, cy, r / 6, r / 6, "Black", 1);
        }
        break;
    default:
        break;
    }
}

void DrawCoin(double cx, double cy, double r)
{
    r = r * 3 / 4;
    DrawECircle(cx - r / 8, cy, r * 3 / 4, r, "Coin1", 1);
    DrawECircle(cx + r / 8, cy, r * 3 / 4, r, "Coin2", 1);
}

void DrawMenuBackG()
{
    SetPenColor("Purple3");
    drawBox(0, 0, winwidth / 10, winheight, 1, "", '1', "Black");
    drawBox(0, 0, winwidth, winheight / 10, 1, "", 's', "Black");
    drawBox(winwidth * 9 / 10, 0, winwidth / 10, winheight, 1, "", 's', "Black");
    drawBox(0, winheight * 9 / 10, winwidth, winheight / 10, 1, "", 's', "Black");
    SetPenColor("Purple1");
    SetPointSize(30);
    MovePen(winwidth / 4, 0.2);
    DrawTextString("Pay tribute to the Namco Cor.");
    SetPointSize(13);
}

void DrawMenuLable()
{
    string ghostcolor;
    switch ((animatimer % 120) / 24)
    {
    case 0:
        ghostcolor = "ZJUred";
        break;
    case 1:
        ghostcolor = "ZJUblue";
        break;
    case 2:
        ghostcolor = "Azure";
        break;
    case 3:
        ghostcolor = "Pink";
        break;
    case 4:
        ghostcolor = "Orange";
        break;
    default:
        ghostcolor = "Black";
        break;
    }
    SetPointSize(50);
    SetPenColor("Purple1");
    drawBox(winwidth / 2 - winwidth / 5, winheight * 3 / 4, winwidth * 2 / 5, GetFontHeight() * 2, 1, "PA     MAN", 's', "GREEN");
    DrawEater(winwidth / 2 - GetFontHeight() / 2, winheight * 3 / 4 + GetFontHeight() * 7 / 8, GetFontHeight() / 3, Dir_right, "Purple1", Skin_plain);
    if (animatimer % 30 < 15)
        DrawGhost(winwidth / 2 + GetFontHeight() * 8 / 7, winheight * 3 / 4 + GetFontHeight() * 7 / 8, GetFontHeight() * 2 / 3, ghostcolor, Dir_left);
    if (animatimer % 30 >= 15)
        DrawGhost(winwidth / 2 + GetFontHeight() * 8 / 7, winheight * 3 / 4 + GetFontHeight() * 7 / 8, GetFontHeight() * 2 / 3, ghostcolor, Dir_right);
    DrawCoin(winwidth / 2, winheight * 3 / 4 + GetFontHeight() * 7 / 8, GetFontHeight() / 4);
    SetPenColor("Purple2");
    int blinkctrl = animatimer % 20;
    if (blinkctrl < 12)
        drawBox(winwidth / 2 - winwidth / 5, winheight / 2, winwidth * 2 / 5, GetFontHeight() * 2, 1, "LET'S PLAY PAC MAN!", 's', "White");
    else
        drawBox(winwidth / 2 - winwidth / 5, winheight / 2, winwidth * 2 / 5, GetFontHeight() * 2, 1, "", 's', "White");
}

void DrawStar(double cx, double cy, double halfsize, string background, string color)
{
    double size = 2 * halfsize;
    SetPenColor(background);
    drawBox(cx - halfsize, cy - halfsize, size, size, 1, "", 's', "Black");
    SetPenColor(background);
}

void DrawBlinkyStar()
{
}

void DrawGamePreview()
{
    SetPenColor("Purple2");
    drawBox(0, 0, winwidth, winheight, 1, "", 's', "Black");
    drawBox(0, 0, winwidth, winheight, 1, "", 's', "Black");
    DrawMenuBackG();
    SetPointSize(30);
    SetPenColor("Purple3");
    drawBox(winwidth * 2 / 10, winheight * 8 / 10, winwidth * 2 / 10, winheight / 20, 1, "", 's', "Black");
    SetPenColor("Purple1");
    drawBox(winwidth * 2 / 10 + 0.1, winheight * 8 / 10 + 0.1, winwidth * 2 / 10 - 0.2, winheight / 20 - 0.2, 1, "Map PreView", 's', "White");
    SetPenColor("Purple3");
    drawBox(winwidth * 6 / 10, winheight * 8 / 10, winwidth * 2 / 10, winheight / 20, 1, "", 's', "Black");
    char bar1[40], bar2[40], bar3[40], bar4[40];
    sprintf(bar1, "Name: %s", GmSts.name);
    sprintf(bar2, "Game Level: %d", GmSts.lvl);
    sprintf(bar4, "Map Size: %d*%d", Length, Length);
    GmSts.scoregoal = (GmSts.skin == Skin_plain) ? Maxode * 2 / 3 : (Maxode - 15);
    sprintf(bar3, "Score Goal: %d", GmSts.scoregoal);
    //
    if (button(GenUIID(4), winwidth * 6 / 10 + winwidth * 2 / 10 + 0.2, winheight * 8 / 10 + 0.1, winheight / 20, GetFontHeight() * 1.5, ">>"))
    {
        if (GmSts.lvl == 7)
            GmSts.lvl = 0;
        else
            GmSts.lvl++;
        Length = Inivation("S");
    }
    if (button(GenUIID(4), winwidth * 6 / 10 - winheight / 20 - 0.2, winheight * 8 / 10 + 0.1, winheight / 20, GetFontHeight() * 1.5, "<<"))
    {
        if (GmSts.lvl == 1)
            GmSts.lvl = 7;
        else
            GmSts.lvl--;
        Length = Inivation("S");
    }
    SetPenColor("Purple1");
    drawBox(winwidth * 6 / 10 + 0.1, winheight * 8 / 10 + 0.1, winwidth * 2 / 10 - 0.2, winheight / 20 - 0.2, 1, "Select Map", 's', "White");
    SetPenColor("Purple1");
    drawBox(winwidth * 0.5 + 0.1, winheight * 0.7 + 0.1, winwidth * 0.4 - 0.2, winheight * 0.1 - 0.2, 1, bar1, 's', "White");
    SetPenColor("Purple1");
    drawBox(winwidth * 0.5 + 0.1, winheight * 0.6 + 0.1, winwidth * 0.4 - 0.2, winheight * 0.1 - 0.2, 1, bar2, 's', "White");
    SetPenColor("Purple1");
    drawBox(winwidth * 0.5 + 0.1, winheight * 0.5 + 0.1, winwidth * 0.4 - 0.2, winheight * 0.1 - 0.2, 1, bar3, 's', "White");
    SetPenColor("Purple1");
    drawBox(winwidth * 0.5 + 0.1, winheight * 0.4 + 0.1, winwidth * 0.4 - 0.2, winheight * 0.1 - 0.2, 1, bar4, 's', "White");
    int ci, cj;
    double sx = winwidth * 0.1, sy = winheight * 0.4;
    double dx = winwidth * 0.4 / Length, dy = winheight * 0.4 / Length;
    for (cj = 0; cj < Length; cj++)
        for (ci = 0; ci < Length; ci++)
        {
            if (Spifpath(Map[ci][cj]))
                SetPenColor("Black");
            if (Map[ci][cj] == Mp_start)
                SetPenColor("Green");
            else if (Map[ci][cj] == Mp_Ghst)
                SetPenColor("Red");
            else if (!Spifpath(Map[ci][cj]))
                SetPenColor("ZJUblue");
            drawBox(sx + dx * cj, sy + dy * ci, dx, dy, 1, "", 's', "Black");
        }
    SetPenColor("White");
    drawBox(winwidth * 0.1, winheight * 0.4, winwidth * 0.4, winheight * 0.4, 0, mapnames[GmSts.lvl - 1], 's', "White");
    //
    SetPenColor("Purple3");
    drawBox(winwidth * 2 / 10, winheight * 7 / 20, winwidth * 2 / 10, winheight / 20, 1, "", 's', "Black");
    SetPenColor("Purple1");
    drawBox(winwidth * 2 / 10 + 0.1, winheight * 7 / 20 + 0.1, winwidth * 2 / 10 - 0.2, winheight / 20 - 0.2, 1, "Select Hero", 's', "White");
    SetPenColor("Purple1");
    drawBox(winwidth / 10, winheight / 10, winwidth * 4 / 10, winheight * 2.5 / 10, 1, "", 's', "White");
    SetPenColor("Purple2");
    drawBox(winwidth * 2 / 10 - min(winwidth / 12, winheight / 12), winheight * 5 / 20 - min(winwidth / 12, winheight / 12), min(winwidth / 6, winheight / 6), min(winwidth / 6, winheight / 6), 1, "board", 's', "White");
    DrawEater(winwidth * 2 / 10, winheight * 5 / 20, winheight > winwidth ? winwidth / 14 : winheight / 14, Dir_right, "Purple2", GmSts.skin);
    SetPenColor("Purple2");
    drawBox(winwidth * 1 / 10, winheight * 1 / 10, winwidth * 2 / 10, winheight / 20, 1, "", 's', "Black");
    SetPenColor("Purple1");
    drawBox(winwidth * 1 / 10 + 0.1, winheight * 1 / 10 + 0.1, winwidth * 2 / 10 - 0.2, winheight / 20 - 0.2, 1, skinnames[GmSts.skin], 's', BlinkCtrlor(50, 0.5) ? skinNC[GmSts.skin] : "White");
    SetPenColor("Purple2");
    drawBox(winwidth * 4 / 10 - min(winwidth / 12, winheight / 12), winheight * 5 / 20 - min(winwidth / 12, winheight / 12), min(winwidth / 6, winheight / 6), min(winwidth / 6, winheight / 6), 1, skininfo[GmSts.skin], 's', "White");
    if (button(GenUIID(4), winwidth * 7 / 20 + 0.1, winheight * 1 / 10 + 0.1, winwidth * 1 / 10 - 0.1, winheight / 20 - 0.2, "Change"))
    {
        if (GmSts.skin == 1)
            GmSts.skin++;
        else if (GmSts.skin == 3)
            GmSts.skin = -1;
        GmSts.skin++;
    }
}

void DrawAnima()
{
    string backgroundcolor = "Purple2";
    double wid = winwidth, hei = winheight;
    double eaterx = (animatimer % 65) * wid / 60;
    double eatery = hei / 2, ghsty = hei / 2;
    double ghstx1 = ((animatimer + 50) % 65) * wid / 60;
    double ghstx2 = ((animatimer + 45) % 65) * wid / 60;
    double ghstx3 = ((animatimer + 40) % 65) * wid / 60;
    double ghstx4 = ((animatimer + 35) % 65) * wid / 60;
    drawBox(0, 0, wid, hei, 1, "", 's', "ZJUred");
    SetPenColor("Purple2");
    drawBox(winwidth / 10, winheight / 10, winwidth * 8 / 10, winheight * 8 / 10, 1, "", 's', "GREEN");

    DrawMenuLable();

    SetPenColor(backgroundcolor);
    DrawEater(eaterx, eatery, hei / 16, Dir_right, backgroundcolor, Skin_plain);
    if (animatimer + 50 > 65)
        DrawPinky(ghstx1, ghsty, hei / 8, Dir_right);
    if (animatimer + 45 > 65)
        DrawInky(ghstx2, ghsty, hei / 8, Dir_right);
    if (animatimer + 40 > 65)
        DrawBlinky(ghstx3, ghsty, hei / 8, Dir_right);
    if (animatimer + 35 > 65)
        DrawClyde(ghstx4, ghsty, hei / 8, Dir_right);
    SetPenColor("Black");
    SetPointSize(30);
    int blinkctrl = animatimer % 20;
    if (blinkctrl < 12)
        drawBox(wid / 4, hei / 4, wid / 2, GetFontHeight() * 2, 0, "Let's <> GO!", 's', "White");
    else
        drawBox(wid / 4, hei / 4, wid / 2, GetFontHeight() * 2, 0, "", 's', "White");
    SetPointSize(13);
    DrawMenuBackG();
}

void DrawEditName()
{
    SetPointSize(30);
    static char memo[30] = "Explorer";
    char displ[40] = "Your Name: ";
    strcat(displ, memo);
    strcpy(GmSts.name, memo);
    SetPenColor("Purple1");
    drawBox(winwidth * 3 / 10, winheight * 7 / 10, winwidth * 4 / 10, GetFontHeight() * 1.5, 1, displ, 's', "White");
    SetPenColor("Black");
    drawBox(winwidth * 3 / 10, winheight * 7 / 10 - GetFontHeight() * 1.5, winwidth * 1 / 5, GetFontHeight() * 1.5, 1, "Edit Name:", 'L', "White");
    drawBox(winwidth * 5 / 10, winheight * 7 / 10 - GetFontHeight() * 1.5, winwidth * 1 / 5, GetFontHeight() * 1.5, 1, "", 'L', "White");
    SetPenColor("Black");
    textbox(GenUIID(0), winwidth * 5 / 10, winheight * 7 / 10 - GetFontHeight() * 1.5, winwidth / 5, GetFontHeight() * 1.5, memo, sizeof(memo));
}
