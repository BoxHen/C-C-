#include "stack2.h"
#include "stackFunctions2.h"
#include <stdlib.h>

/*----------------------------------------------Functon---------------------------------------------------*/
/*-----------------------------------------Push---------------------------------------------*/
// adds one element, a character, to the top of the stack
double PushStack2(double X){
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
double PopStack2(){
  stackNode2 *Temp;
  double X;
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
double TopStack2(){
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
double isFullStack2(){
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
