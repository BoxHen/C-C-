#ifndef MY_FUNC_H
#define MY_FUNC_H
#include <stdio.h>
/*---------------------------------------------Global Variales----------------------------------------------*/
extern char queue[QUEUESZ];
extern char b[(2 * QUEUESZ)];
extern int size; //initialize size
extern int front; //initialize front
extern int end; //initialize end
/*------------------------------------------------Prototypes------------------------------------------------*/
int Push(int value);
char Pull(void);
char Front(void);
int isFull(void);

#endif
