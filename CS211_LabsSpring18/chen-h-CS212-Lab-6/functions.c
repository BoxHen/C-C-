#include "tstdata.h"
#include "functions.h"
#include <stdlib.h>

/*----------------------------------------------Functon---------------------------------------------------*/
/*-----------------------------------------Push---------------------------------------------*/
// adds one element, a character, to the top of the stack
int Push(itemType X){
  queueNode *Temp;
  Temp = (queueNode*)malloc(sizeof(queueNode));
  if(isFull() == 1){
    return -1;
  }
  else if(isFull() == -1){ // if empty
    Temp->next = NULL;
    Temp->item = X;
    //if(rear == NULL){
    anchor = Temp;
    rear = Temp;
    return 1;
  }
  else{
    Temp->next = NULL;
    Temp->item = X;
    rear->next = Temp; // link it as new last node of the linked list of queue nodes
    rear = Temp; // has rear pointer point to this new last node
    }
    return 0;
  }
/*------------------------------------------Pull---------------------------------------------*/
char Pull(){
  queueNode *Temp;
  itemType X;
  if(isFull() == -1){
      printf("you are attempting to pop an empty stack"); // return something
      return '\0'; // queue empty return null character
  }
  else{
    Temp = anchor;
    X = anchor->item;
    anchor = Temp->next;
    free(Temp);
    if(anchor == NULL) rear = NULL;
    return X;
  }
}
/*------------------------------------------Top---------------------------------------------*/
//returns topmost element
char Front(){
  if(isFull() == -1){
    printf("Nothing in the queue");
    return '\0'; // queue empty return null character
  }
  else{
    return anchor->item;
  }
}
/*----------------------------------------is Full-------------------------------------------*/
int isFull(){
  queueNode *Temp;
  Temp = (queueNode*)malloc(sizeof(queueNode));
  if(anchor == NULL && rear == NULL){
    return -1; // queue empty
  }
  else if(Temp == NULL){
    return 1; // queue full
  }
  else{
    return 0; // neither full or empty
  }
}
