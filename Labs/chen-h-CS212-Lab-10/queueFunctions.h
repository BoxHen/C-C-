#ifndef queueFunctions_H
#define queueFunctions_H
#include <stdio.h>
/*------------------------------------------------Prototypes------------------------------------------------*/
int PushQueue(char X);
char PullQueue(void);
char PullBackQueue(void);
char FrontQueue(void);
char BackQueue(void);
int isFullQueue(void);
char GetNextQueue(int direction);
//Node *GetCurrentQueue(void);
int ResetQueue(int r);
//int DeleteQueue(Node *pointer);

#endif
