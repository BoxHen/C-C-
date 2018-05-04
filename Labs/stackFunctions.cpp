#include "tstdata.h"
#include "functions.h"

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
