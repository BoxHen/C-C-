#include <stdio.h>
#include <stdlib.h>
#include "tstdata.h"
#include "functions.h"

int main()
{
  int i, j; // used for printing out stack
  char option[10], value;
  while(1)
  {
    printf("\n*****************Implementing a stack with an array*****************\n");
    printf("Choose an option:\n1. Push\n2. Pull\n3. Front\n4. isFull\n5. \"^\" to exit\n");
    scanf("%s", &option);
    if((strcmp(option, "Push") == 0) || (strcmp(option, "push") == 0))
    {
      printf("input value to be pushed in\n");
      scanf(" %c",&value);
      Push(value);
    }
    else if((strcmp(option, "Pull") == 0) || (strcmp(option, "pull") == 0))
    {
      Pull();
    }
    else if((strcmp(option, "Front") == 0) || (strcmp(option, "front") == 0))
    {
      Front();
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
  while(1)
  {
    i = Pull();
    j = isFull();
    printf("%c",i);
    if(j == -1)
      break;
  }
  return 0;

} // end main
