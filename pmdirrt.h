// Demon Version
/*
 * File: pmdirrt.h
 * PacMan_Direction
 * Version: 1.0  for Pac-Man
 * ------------------------------------------------------
 * This file contains some consensus on the identification
 * of the direction file-mp.pms.
 */
#ifndef _PMDIRRT_H_
#define _PMDIRRT_H_

#include <time.h>
#include "pmminit.h"

/*
 * 4 Directions
 */
typedef enum
{
    Dir_up,
    Dir_down,
    Dir_left,
    Dir_right,
    Dir_error
} Dir; //四个方向
/*
 * Function: Juge_Dir
 * Judge the direction of the 2 Vertexes by thier ID information
 * Usage: Input 2 Vertexes: from, to. And it will return the 
 * direction of these Vertexes.
 */
int Juge_Dir(ID fr, ID to);

#endif