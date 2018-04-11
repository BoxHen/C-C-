#include <stdio.h>
#include <stdlib.h>
#include "tstdata.h"
#include "functions.h"

int main()
{
  char i; // used for printing out stack
  int j;
  int ret;
  char value;
  while(1)
  {
    printf("input value to be pushed in\n");
    scanf(" %c",&value);
    if(value == '^')
    {
      break; // exit loop if "^" is inputted
    }
    else
    {
      ret = Push(value);
      if(ret == 0)
      {
        printf("\nvalue, %c, is inserted in position, %d\n", value, topStack);
      }
      else if(ret == -1)
      {
        printf("\nThe stack is full. Enter the \"^\" character to stop.\n");
      }
    }
  } // end while
  /*------------------------------Output stack---------------------------------*/

  printf("The stack is: ");
  while(1)
  {
    i = Pop();
    j = isFull();
    printf("%c ",i);
    if(j == -1)
      break;
  }
  return 0;
} // end main
