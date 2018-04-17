#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tstdata.h"
#include "functions.h"

int main()
{
  char i; // used for printing out
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
      if(ret == 0 || ret == 1)
      {
        printf("\nvalue, %c, is inserted\n",value);
      }
      else if(ret == -1)
      {
        printf("The List is full. Enter the ‘^’ character to stop\n");
      }
    }
  } // end while
  /*------------------------------Output List---------------------------------*/
  printf("\nFront to end is: ");
    i = Front();
  while(i != '\0'){
    printf("%c ", i);
    i = GetNext(0);
  }

  printf("\nEnd to Front is: ");
  i = Back();
  while(i != '\0'){
    printf("%c ", i);
    i = GetNext(1);
  }
	printf("\n");

  return 0;
} // end main
