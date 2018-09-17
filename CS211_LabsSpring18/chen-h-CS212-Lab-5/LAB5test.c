#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char itemType;
/*------------------------------------------------Prototypes------------------------------------------------*/
int Push(itemType X);
char Pop();
char Top(void);
int isFull(void);

typedef struct stackNodeTag{
	itemType item;
	struct stackNodeTag *next;
}stackNode;

stackNode *anchor = NULL;

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
      if(ret == 0 || ret == 1)
      {
        printf("\nvalue, %c, is inserted\n", value);
      }
      else if(ret == -1)
      {
        printf("System storage is full");
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

/*----------------------------------------------Functon---------------------------------------------------*/
/*-----------------------------------------Push---------------------------------------------*/
// adds one element, a character, to the top of the stack
int Push(itemType X){
  stackNode *Temp;
  Temp = (stackNode*)malloc(sizeof(stackNode));
  if(isFull() == 1){
    //SystemError("System storage is full");
    return -1;
  }
  else if(isFull() == -1){ // if empty
    Temp->next = anchor;
    Temp->item = X;
    anchor = Temp; //let S point to the new topmost stack node
    return 1;
  }
  else{
    Temp->next = anchor;
    Temp->item = X;
    anchor = Temp;
    return 0;
  }
}

/*------------------------------------------Pop---------------------------------------------*/
char Pop(){
  stackNode *Temp;
  itemType X;
  if(isFull() == -1){
      printf("you are attempting to pop an empty stack"); // return something
      return '\0'; // stack empty return null character
  }
  else{
    Temp = anchor;
    X = Temp->item;
    anchor = Temp->next;
    free(Temp);
    return X;
  }
}
/*------------------------------------------Top---------------------------------------------*/
//returns topmost element
char Top(){
  if(isFull() == -1){
    printf("Nothing in the stack");
    return '\0'; // stack empty return null character
  }
  else{
    //printf("The topmost  element is, %c\n",S->anchor->item);
    return anchor->item;
  }
}
/*----------------------------------------is Full-------------------------------------------*/
int isFull(){
  stackNode *Temp;
  Temp = (stackNode*)malloc(sizeof(stackNode));
  if(anchor == NULL){
    //printf("Stack is empty");
    return -1; // stack empty
  }
  else if(Temp == NULL){
    //printf("Stack is full");
    return 1; // stack full
  }
  else{
    //printf("More room in stack");
    return 0; // neither full or empty
  }
}
