#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tstdata.h"
#include "functions.h"

int main(){
  int ret, count = 0;
  char value, RememberedValue;
  while(1){
    printf("input value to be pushed in\n");
    scanf(" %c",&value);
    count++;
    if(count > 10){ // checks for at least 10 characters
      if(value == '^'){
        break; // exit loop if "^" is inputted
      }
    }
    if(count == 3){
      RememberedValue = value;
    }
    ret = Push(value);
    if(ret == 0 || ret == 1){
      printf("\nvalue, %c, is inserted\n",value);
    }
    else if(ret == -1){
      printf("The List is full. Enter the ‘^’ character to stop\n");
    }
  } // end while
  
  /*------------------------------Output List---------------------------------*/
  PrintForward();
  // 1. display the position # of that character in the list
  FindValue(RememberedValue);
  printf("\nThe position of %c is %i\n", RememberedValue, GetNodeNumber());
  // 2. insert the symbol, "*", after the remembered character
  InsertAfter((FindValue(RememberedValue)), '*' );
  // 3. delete that remembered character from the list
  DeleteNode(FindValue(RememberedValue));
  // 4. print the list in forward order again, so we can see it was deleted
  printf("\n\nafter the remembered character is deleted and * is inserted:");
  PrintForward();
  // 5. delete all remaining copies of the remembered character (if any).
  // 6. print the list in forward order again
  printf("\n\nafter all the remembered characters are deleted:");
  PrintForward();
  printf("\n");
  return 0;
} // end main
