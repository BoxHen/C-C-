#include "stack2.h"
#include "stackFunctions2.h"

/*----------------------------------------------Functon---------------------------------------------------*/
/*-----------------------------------------Push---------------------------------------------*/
// adds one element, a character, to the top of the stack
int PushStack2(int X){
  stackNode2 *Temp;
  Temp = (stackNode2*)malloc(sizeof(stackNode2));
  if(isFullStack2() == 1){
    //SystemError("System storage is full");
    return -1;
  }
  else if(isFullStack2() == -1){ // if empty
    Temp->next = anchorStack2;
    Temp->item = X;
    anchorStack2 = Temp; //let S point to the new topmost stack node
    return 1;
  }
  else{
    Temp->next = anchorStack2;
    Temp->item = X;
    anchorStack2 = Temp;
    return 0;
  }
}

/*------------------------------------------Pop---------------------------------------------*/
int PopStack2(){
  stackNode2 *Temp;
  int X;
  if(isFullStack2() == -1){
      printf("you are attempting to pop an empty stack"); // return something
      return '\0'; // stack empty return null character
  }
  else{
    Temp = anchorStack2;
    X = Temp->item;
    anchorStack2 = Temp->next;
    free(Temp);
    return X;
  }
}
/*------------------------------------------Top---------------------------------------------*/
//returns topmost element
int TopStack2(){
  if(isFullStack2() == -1){
    printf("Nothing in the stack");
    return '\0'; // stack empty return null character
  }
  else{
    //printf("The topmost  element is, %c\n",S->anchor->item);
    return anchorStack2->item;
  }
}
/*----------------------------------------is Full-------------------------------------------*/
int isFullStack2(){
  stackNode2 *Temp;
  Temp = (stackNode2*)malloc(sizeof(stackNode2));
  if(anchorStack2 == NULL){
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
