#include "tstdata.h"
#include "functions.h"

int stack[STACKSZ];
int topStack = -1; //initialize top
int holder;
/*----------------------------------------------Functon---------------------------------------------------*/
/*-----------------------------------------Push---------------------------------------------*/
// adds one element, a character, to the top of the stack
int Push(int value)
{
  if(topStack == (STACKSZ-1))
  {
    return -1; // stack full
  }
  else
  {
    topStack++;
    stack[topStack] = value;
    return 0; // successfully added
  }
}

/*------------------------------------------Pop---------------------------------------------*/
//– removes the top element
char Pop()
{
  //char delValue;
  if(topStack == -1)
  {
    printf("ERROR! No more values in stack to pop");
    return '\0'; // stack empty return null character
  }
  else
  {
    //printf("value, %c, in position, %d, is deleted.\n",stack[topStack], topStack);
    //delValue = stack[topStack];
    //stack[topStack] == Null;
    holder = topStack;
    topStack--;
    return stack[holder]; // returns deleted value
  }
}
/*------------------------------------------Top---------------------------------------------*/
//returns topmost element
char Top()
{
  if(topStack == -1)
  {
    printf("Nothing in the stack");
    return '\0'; // stack empty return null character
  }
  else
  {
    printf("The topmost  element is, %c\n",stack[topStack]);
    return stack[topStack];
  }
}
/*----------------------------------------is Full-------------------------------------------*/
int isFull()
{
  if(topStack == -1)
  {
    //printf("Stack is empty");
    return -1; // stack empty
  }
  else if(topStack == (STACKSZ-1))
  {
    //printf("Stack is full");
    return 1; // stack full
  }
  else
  {
    //printf("More room in stack");
    return 0; // neither full or empty
  }
}
