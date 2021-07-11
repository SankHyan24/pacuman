#include "global.h"
//
double mouse_x;
double mouse_y;
// Map information
int Length;                          // The Length of the very map
int Maxdge;                          // The number of the Edges
int Maxode;                          // The number of the Nodes
int Map[MAXSTRLEN][MAXSTRLEN] = {0}; // To store the map in the Memory
// Window information
double winheight; // the height of the window
double winwidth;  // the width of the window
// Rank&Score information
int mylevel = 2;            // the user's level
int myscore = 250;          // the user's score
char myname[35] = "scscsc"; // the user's name
// The Launcher of the Game
int launchselecter = 0; // to select the different GUI
int animatimer;         // Control the Animation
int winorlost = 0;
char *mapnames[] = {"Big Riddle", "Classic Battle", "Ziggrate", "Monkey Donkey", "Tank Wolrd", "The \"Matrix\"", "Last War"};
char *skinnames[] = {"Paku~Paku~", "Bruce Banner", "The HULK", "Neo Anderson"};
char *skinNC[] = {"Orange", "Azure", "Azure", "Yellow"};
char *skininfo[] = {"一个普通的吃豆人", "布鲁斯班纳博士", "绿巨人形态", "黑客帝国救世主"};
int testflag = 0; //*第一次进入的是帮助页面