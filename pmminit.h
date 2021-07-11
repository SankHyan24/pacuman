// Demon Version
// By scitbb
/*
 * File: pmminit.h
 * PacMan_Map_INITialization
 * Version: 1.0  for Pac-Man
 * ------------------------------------------------------
 * This file contains some functions used to read the data
 * from the map, calculate the shortest path and store 
 * them in the temporary file located in "./tmp/mp.pms". 
 * [Warning]:This file can't be used in the running game. 
 * The gaming information will be executed by the other-file 
 * functions. 
 */
#ifndef _PMMINIT_H_
#define _PMMINIT_H_
/*
 * Overview:
 * The Functions only used in Dijkstra:
 *  > GetMaxN
 * The tool Functions used in other file:
 *  > LocateVex
 *  > IDcompare
 *  > Inivation
 */

#define MAXSTRLEN 31                    // Maxium strlen
#define MAXNODE (MAXSTRLEN * MAXSTRLEN) // Maxium node
#define MAXI 32767                      // Set as Infinity

#include <stdbool.h>

typedef struct
{
    int x; // the value of x coordinate
    int y; // the value of x coordinate
} ID;      // use ID to record the Position

/*
 * Function: GetMaxN
 * We will read Map and analyze it. We will initialize the value of 
 * "Maxode" "Maxdge" use the function GetMaxN(). We can't use it before 
 * the function "Inivation".
 */
void GetMaxN();
/*
 * Function: Inivation
 * Initialize the Map from the /filename{location}.pmm 
 * Usage: Input the location of the Map. We will read it and analyze it.
 * We will initialize the value of "Length" "Maxode" "Maxdge" (the last 
 * two values use the function "GetMaxN").
 */
int Inivation(char *location);

#endif
