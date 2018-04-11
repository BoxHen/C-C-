#ifndef MY_FUNC_H
#define MY_FUNC_H
#include <stdio.h>
/*---------------------------------------------Global Variales----------------------------------------------*/
extern int stack[STACKSZ];
extern int topStack;
/*------------------------------------------------Prototypes------------------------------------------------*/
int Push(int value);
char Pop(void);
char Top(void);
int isFull(void);

#endif
