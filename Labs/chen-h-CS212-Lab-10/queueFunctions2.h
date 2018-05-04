#ifndef queueFunctions2_H
#define queueFunctions2_H
#include <stdio.h>
/*------------------------------------------------Prototypes------------------------------------------------*/
int PushQueue2(char X);
char PullQueue2(void);
char PullBackQueue2(void);
char FrontQueue2(void);
char BackQueue2(void);
int isFullQueue2(void);
char GetNextQueue2(int direction);
//Node *GetCurrentQueue2(void);
int ResetQueue2(int r);
//int DeleteQueue2(Node *pointer);

#endif
