// Demon Version
// By scitbb
/*
 * File: pmminit.c
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
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pmLaucher.h"
#include "pmminit.h"
#include "pmdirrt.h"
#include "global.h"
#include "pmsp.h"

int Inivation(char *location)
{
    FILE *fp; // Read the Map
    int Lenth = 0;
    char mapiniv[MAXSTRLEN][MAXSTRLEN] = {'\0'};
    char stroffile[30] = "lv", houzhui[6] = ".pmm", xuhao[4];
    if (GmSts.lvl == 0)
        GmSts.lvl = 1;
    sprintf(xuhao, "%d", GmSts.lvl);
    strcat(stroffile, xuhao);
    strcat(stroffile, houzhui);
    if ((fp = fopen(stroffile, "r")) == NULL)
    {
        printf("Can't read the File \"lv1.pmm\".\nPlease check it again.\n");
        printf("    >>Input any letter to exit.\n    >>");
        getchar();
        exit(-1);
    }
    int i, j;
    for (i = 0; !feof(fp) && i < MAXSTRLEN; i++)
        fgets(mapiniv[i], MAXSTRLEN, fp);
    for (Lenth = -1; mapiniv[0][Lenth + 1] != '\0'; Lenth++)
        continue;
    for (i = 0; i < Lenth; i++)
    {
        for (j = 0; j < Lenth; j++)
        {
            if (mapiniv[i][j] == '\0')
                Map[i][j] = Mp_wall; // Make up the wall with 1
            else
                Map[i][j] = (int)(mapiniv[i][j] - '0');
            // printf("%2d ", Map[i][j]);
        }
        // printf("\n");
    }
    fclose(fp);

    Length = Lenth;
    GetMaxN();
    printf("Map[][] Init Done\n");
    return Lenth;
}

void GetMaxN()
{
    int i, j, n = 0, m = 0;
    for (i = 0; i < Length; i++)
        for (j = 0; j < Length; j++)
            if (Spifpath(Map[i][j]))
            {
                n++;
                if (i == 0)
                {
                    if (Spifpath(Map[Length - 1][j]))
                        m++;
                }
                else if (Spifpath(Map[i - 1][j]))
                    m++;
                if (i == Length - 1)
                {
                    if (Spifpath(Map[0][j]))
                        m++;
                }
                else if (Spifpath(Map[i + 1][j]))
                    m++;
                if (j == 0)
                {
                    if (Spifpath(Map[i][Length - 1]))
                        m++;
                }
                else if (Spifpath(Map[i][j - 1]))
                    m++;
                if (j == Length - 1)
                {
                    if (Spifpath(Map[i][0]))
                        m++;
                }
                else if (Spifpath(Map[i][j + 1]))
                    m++;
            }
    Maxode = n;
    Maxdge = m;
}
