#include "tstdata.h"
#include <stdio.h>

int main()
{
  int i; // used for printing out stack
  char option[10], value;
  while(1)
  {
    printf("\n*****************Implementing a stack with an array*****************\n");
    printf("Choose an option:\n1. Push\n2. Pop\n3. Top\n4. isFull\n5. \"^\" to exit\n");
    scanf("%s", &option);
    if((strcmp(option, "Push") == 0) || (strcmp(option, "push") == 0))
    {
      printf("input value to be pushed in\n");
      scanf(" %c",&value);
      Push(value);
    }
    else if((strcmp(option, "Pop") == 0) || (strcmp(option, "pop") == 0))
    {
      Pop();
    }
    else if((strcmp(option, "Top") == 0) || (strcmp(option, "top") == 0))
    {
      Top();
    }
    else if((strcmp(option, "isfull") == 0) || (strcmp(option, "isFull") == 0))
    {
      isFull();
    }
    else if(strcmp(option, "^") == 0)
    {
      break; // exit loop is "^" is inputted
    }
    else
    {
      printf("ERROR! Please enter a listed option!");
    }
  } // end while
  /*------------------------------Output stack---------------------------------*/
  printf("The stack is: ");
  for(i = 0; i <= topStack; i++)
  {
    printf("%c ",stack[i]);
  }
  return 0;
} // end main
