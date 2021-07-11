#ifndef ___PM_HELP_H
#define ___PM_HELP_H

/*
Function:Draw screen of help
change the direction by updating line0[],line1[],line2[],line3[]
*/
void ListHelp();
/*
Fuction:Draw screen for your game result
this funtion need a variable 'win' to decide whether to show "you win!" or "you lose",
and the button will also change depending on your game result
we have totally seven levels , so if this is the last level , no need to show "next level"
*/
void ForScreen(int win);
void DrawHeart();
void DrawHelp1();
void DrawHelp2();
void DrawHelp3();
void DrawHelp4();
void DrawHelp5();
void DrawHelp6();
void DrawHelp7();
void DrawHelp8();
void DrawHelp9();
void DrawHelp10();
void DrawHelp11();

#endif
