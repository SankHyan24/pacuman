// Demon Version
// By scitbb
/*
 * File: pmdirect.c
 * PacMan_Direcction
 * Version: 1.0  for Pac-Man
 * ------------------------------------------------------
 * This file contains some consensus on the identification
 * of the direction file-mp.pms
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "global.h"
#include "pmdirrt.h"
#include "pmgame.h"

int Juge_Dir(ID fr, ID to)
{
    if (fr.x == to.x)
    {
        if (fr.y + to.y != Length - 1)
        {
            if (fr.y < to.y)
                return Dir_down;
            else
                return Dir_up;
        }
        else
        {
            if (fr.y < to.y)
                return Dir_up;
            else
                return Dir_down;
        }
    }
    else if (fr.x + to.x != Length - 1)
    {
        if (fr.x < to.x)
            return Dir_right;
        else
            return Dir_left;
    }
    else
    {
        if (fr.x < to.x)
            return Dir_left;
        else
            return Dir_right;
    }
}