#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Lab10Functions.h"

#include "queue.h"
#include "stack.h"

#include "queueFunctions.h"
#include "queueFunctions2.h"
#include "stackFunctions.h"
#include "stackFunctions2.h"


int main(){
   char i, value;
     printf("input sequence to be pushed in\n");

  while (1) {
      if (isFullQueue() == 1) {printf("\nThe queue is full. Enter the '^' character to stop.\n");}
      scanf(" %c", &value);

      if (value != '^') {PushQueue(value);}
      else{ break;} // exit loop if "^" is inputted
  }
  /*------------------------------Output List---------------------------------*/
  printf("\nFront to end is: ");
    i = FrontQueue();
    while(i != '\0'){
      printf("%c ", i);
      i = GetNextQueue(0);
    }
    printf("\n");

    infixToPostfix();
    evalPostFix();
  }
