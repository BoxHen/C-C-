#ifndef MY_FUNC_H
#define MY_FUNC_H
#include <stdio.h>
/*------------------------------------------------Prototypes------------------------------------------------*/
int Push(itemType X);
char Pull(void);
char PullBack(void);
char Front(void);
char Back(void);
int isFull(void);
char GetNext(int direction);
Node *GetCurrent(void);
int Reset(int r);
int Delete(Node *pointer);

#endif
