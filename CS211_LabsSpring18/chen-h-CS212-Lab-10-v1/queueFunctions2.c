#include "queue.h"
#include "queueFunctions2.h"
#include <stdlib.h>

/*----------------------------------------------Functon---------------------------------------------------*/
/*-----------------------------------------Push---------------------------------------------*/
// adds one element, a character, to the top of the queue
int PushQueue2(char X){
  Node *Temp;
  Temp = (Node*)malloc(sizeof(Node));
  if(isFullQueue2() == 1){
    return -1;
  }
  else if(isFullQueue2() == -1){ // if empty
    Temp->next = NULL;
    Temp->previous = NULL;
    Temp->item = X;
    anchor2 = Temp;
    rear2 = anchor2;
    tracker2 = anchor2;
    return 1;
  }
  else{
    Temp->next = NULL;
    Temp->previous = rear2;
    Temp->item = X;
    rear2->next = Temp; // link it as new last node of the linked list of queue nodes
    rear2 = Temp; // has rear pointer point to this new last node
    }
    return 0;
  }
/*------------------------------------------Pull---------------------------------------------*/
char PullQueue2(){
  Node *Temp;
  Temp = (Node*)malloc(sizeof(Node));
  char X;
  if(isFullQueue2() == -1){
      printf("you are attempting to pull an empty queue\n"); // return something
      return '\0'; // queue empty return null character
  }
  else{
    Temp = anchor2;
    X = anchor2->item;
    anchor2 = Temp->next;
    anchor2->previous = NULL; // sets the previous anchor to null so tracker does not pick it up
    free(Temp);
    if(anchor2 == NULL) rear2 = NULL;
    return X;
  }
}
/*------------------------------------------PullBack---------------------------------------------*/
char PullBackQueue2(){
  Node *Temp;
  Temp = (Node*)malloc(sizeof(Node));
  char X;
  if(isFullQueue2() == -1){
      printf("you are attempting to pull an empty queue\n"); // return something
      return '\0'; // queue empty return null character
  }
  else{
    Temp = rear2;
    X = rear2->item;
    rear2 = Temp->previous;
    rear2->next = NULL; // sets the previous rear to null so tracker does not pick it up
    free(Temp);
    if(rear2 == NULL) anchor2 = NULL;
    return FrontQueue2();
  }
}
/*------------------------------------------Front---------------------------------------------*/
//returns topmost element
char FrontQueue2(){
  if(isFullQueue2() == -1){
    printf("Nothing in the queue\n");
    return '\0'; // queue empty return null character
  }
  else{
    return anchor2->item;
  }
}
/*------------------------------------------Back---------------------------------------------*/
char BackQueue2(){
  if(isFullQueue2() == -1){
    printf("Nothing in the queue\n");
    return '\0'; // queue empty return null character
  }
  else{
    return rear2->item;
  }
}
/*----------------------------------------isFull-------------------------------------------*/
int isFullQueue2(){
  Node *Temp;
  Temp = (Node*)malloc(sizeof(Node));
  if(anchor2 == NULL && rear2 == NULL){
    return -1; // queue empty
  }
  else if(Temp == NULL){
    return 1; // queue full
  }
  else{
    return 0; // neither full or empty
  }
}
/*----------------------------------------GetNext-------------------------------------------*/
char GetNextQueue2(int direction){ // initialize tracker to anchor Tracker = anchor;
  if(direction == 0){ // move toward rear
    if(tracker2->next != NULL){
      tracker2 = tracker2->next;
      return tracker2->item;
    }
    else
      return '\0';
  }else if(direction == 1){ // move toward anchor
    if(tracker2->previous != NULL){
      tracker2 = tracker2->previous;
      return tracker2->item;
    }else{
      return '\0';
    }
  }
  else
    return '\0';
}
/*----------------------------------------GetCurrent-------------------------------------------*/
/*Node *GetCurrentQueue2(){
  if(tracker2 != NULL){
    return tracker2;
  }
  else
    return '\0';
  }*/
/*----------------------------------------Reset-------------------------------------------*/
int ResetQueue2(int r){
  if(r == 1){
    tracker2 = rear2;
  } else if(r == 0){
    tracker2 = anchor2;
  }else
    tracker2 = tracker2;
  return 0;
}
/*----------------------------------------Delete-------------------------------------------*/
/*int DeleteQueue2(Node *pointer){
  // base case
   if(anchor2 == NULL || pointer == NULL)
     return 0;

   // If node to be deleted is head node
   if(anchor2 == pointer)
     anchor2 = pointer->next;

   // Change next only if node to be deleted is NOT the last node
   if(pointer->next != NULL)
     pointer->next->previous = pointer->previous;

   // Change prev only if node to be deleted is NOT the first node
   if(pointer->previous != NULL)
     pointer->previous->next = pointer->next;

   // Finally, free the memory occupied by del
   free(pointer);
   tracker2 = anchor2; // reset static pointer
   return 1;
}*/
