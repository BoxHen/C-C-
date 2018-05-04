 #include "stack.h"
#include "stackFunctions.h"

/*----------------------------------------------Functon---------------------------------------------------*/
/*-----------------------------------------Push---------------------------------------------*/
// adds one element, a character, to the top of the stack
int PushStack(char X){
  stackNode *Temp;
  Temp = (stackNode*)malloc(sizeof(stackNode));
  if(isFullStack() == 1){
    //SystemError("System storage is full");
    return -1;
  }
  else if(isFullStack() == -1){ // if empty
    Temp->next = anchorStack;
    Temp->item = X;
    anchorStack = Temp; //let S point to the new topmost stack node
    return 1;
  }
  else{
    Temp->next = anchorStack;
    Temp->item = X;
    anchorStack = Temp;
    return 0;
  }
}

/*------------------------------------------Pop---------------------------------------------*/
char PopStack(){
  stackNode *Temp;
  char X;
  if(isFullStack() == -1){
      printf("you are attempting to pop an empty stack"); // return something
      return '\0'; // stack empty return null character
  }
  else{
    Temp = anchorStack;
    X = Temp->item;
    anchorStack = Temp->next;
    free(Temp);
    return X;
  }
}
/*------------------------------------------Top---------------------------------------------*/
//returns topmost element
char TopStack(){
  if(isFullStack() == -1){
    printf("Nothing in the stack");
    return '\0'; // stack empty return null character
  }
  else{
    //printf("The topmost  element is, %c\n",S->anchor->item);
    return anchorStack->item;
  }
}
/*----------------------------------------is Full-------------------------------------------*/
int isFullStack(){
  stackNode *Temp;
  Temp = (stackNode*)malloc(sizeof(stackNode));
  if(anchorStack == NULL){
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
