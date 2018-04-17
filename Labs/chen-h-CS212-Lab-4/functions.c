#include "tstdata.h"
#include "functions.h"

char queue[QUEUESZ];
char b[(2 * QUEUESZ)];
int f, size = 0; //initialize size
int front = 0; //initialize front
int end = QUEUESZ-1; //initialize end

/*
a. Push – adds one element to the end of the queue (accepts a character as input), returns
an int:
i. -1 if the queue is already full,
ii. 0 if the item was successfully added

b. Pull – removes the front element (if it exists) and returns the value:
i. NULL if there were no elements (queue was empty)
ii. The Front element itself, if there was one

c. Front – does NOT remove anything. Returns the value:
i. NULL if there are no elements (queue is empty)
ii. The front char element if there is one

d. isFull – does NOT remove anything. Returns an int:
i. -1 if there are no elements (the queue is empty)
ii. 1 if the queue is full
iii. 0 for all other cases
*/
/*-----------------------------------------Push---------------------------------------------*/
// adds one element, a character, to the end of the queue
int Push(int value)
{
  f = isFull();
  if(f == 1)
  {
    //printf("\nThe stack is full. Enter the \"^\" character to stop.\n");
    return -1; // stack full
  }
  else
  {
    //printf("\nvalue, %c, is inserted in position, %d\n", value, size);
    end = (end+1)% QUEUESZ; // use mod to find end value
    queue[end] = value;
    size += 1;
    return 0; // successfully added
  }
}
/*------------------------------------------Pop---------------------------------------------*/
//– removes the front element
char Pull()
{
  f = isFull();
  if(f == -1)
  {
    printf("\nERROR! No more values in queue to pull");
    return '\0'; // stack empty return null character
  }
  else
  {
    //printf("\nvalue, %c, in position, %d, is deleted.\n",queue[front], front);
    int print = Front();
    //queue[front] =
    front = (front+1)%QUEUESZ;
    size -= 1;
    return print; // returns deleted value
  }
}
/*------------------------------------------Top---------------------------------------------*/
//returns topmost element
char Front()
{
  f = isFull();
  if(f == -1)
  {
    printf("Nothing in the queue");
    return '\0'; // stack empty return null character
  }
  else
  {
    //printf("The topmost  element is, %c\n",queue[front]);
    return queue[front];
  }
}
/*----------------------------------------is Full-------------------------------------------*/
int isFull()
{
  if(size == 0)
  {
    //printf("Stack is empty");
    return -1; // stack empty
  }
  else if(size == QUEUESZ)
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
