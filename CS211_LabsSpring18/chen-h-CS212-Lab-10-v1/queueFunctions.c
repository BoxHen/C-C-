#include "queue.h"
#include "queueFunctions.h"
#include <stdlib.h>

/*----------------------------------------------Functon---------------------------------------------------*/
/*-----------------------------------------Push---------------------------------------------*/
// adds one element, a character, to the top of the queue
int PushQueue(char X){
  Node *Temp;
  Temp = (Node*)malloc(sizeof(Node));
  if(isFullQueue() == 1){
    return -1;
  }
  else if(isFullQueue() == -1){ // if empty
    Temp->next = NULL;
    Temp->previous = NULL;
    Temp->item = X;
    anchor = Temp;
    rear = anchor;
    tracker = anchor;
    return 1;
  }
  else{
    Temp->next = NULL;
    Temp->previous = rear;
    Temp->item = X;
    rear->next = Temp; // link it as new last node of the linked list of queue nodes
    rear = Temp; // has rear pointer point to this new last node
    }
    return 0;
  }
/*------------------------------------------Pull---------------------------------------------*/
char PullQueue(){
  Node *Temp;
  Temp = (Node*)malloc(sizeof(Node));
  char X;
  if(isFullQueue() == -1){
      printf("you are attempting to pull an empty queue\n"); // return something
      return '\0'; // queue empty return null character
  }
  else{
    Temp = anchor;
    X = anchor->item;
    anchor = Temp->next;
    anchor->previous = NULL; // sets the previous anchor to null so tracker does not pick it up
    free(Temp);
    if(anchor == NULL) rear = NULL;
    return X;
  }
}
/*------------------------------------------PullBack---------------------------------------------*/
char PullBackQueue(){
  Node *Temp;
  Temp = (Node*)malloc(sizeof(Node));
  char X;
  if(isFullQueue() == -1){
      printf("you are attempting to pull an empty queue\n"); // return something
      return '\0'; // queue empty return null character
  }
  else{
    Temp = rear;
    X = rear->item;
    rear = Temp->previous;
    rear->next = NULL; // sets the previous rear to null so tracker does not pick it up
    free(Temp);
    if(rear == NULL) anchor = NULL;
    return FrontQueue();
  }
}
/*------------------------------------------Front---------------------------------------------*/
//returns topmost element
char FrontQueue(){
  if(isFullQueue() == -1){
    printf("Nothing in the queue\n");
    return '\0'; // queue empty return null character
  }
  else{
    return anchor->item;
  }
}
/*------------------------------------------Back---------------------------------------------*/
char BackQueue(){
  if(isFullQueue() == -1){
    printf("Nothing in the queue\n");
    return '\0'; // queue empty return null character
  }
  else{
    return rear->item;
  }
}
/*----------------------------------------isFull-------------------------------------------*/
int isFullQueue(){
  Node *Temp;
  Temp = (Node*)malloc(sizeof(Node));
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
/*----------------------------------------GetNext-------------------------------------------*/
char GetNextQueue(int direction){ // initialize tracker to anchor Tracker = anchor;
  if(direction == 0){ // move toward rear
    if(tracker->next != NULL){
      tracker = tracker->next;
      return tracker->item;
    }
    else
      return '\0';
  }else if(direction == 1){ // move toward anchor
    if(tracker->previous != NULL){
      tracker = tracker->previous;
      return tracker->item;
    }else{
      return '\0';
    }
  }
  else
    return '\0';
}
/*----------------------------------------GetCurrent-------------------------------------------*/
/*Node *GetCurrentQueue(){
  if(tracker != NULL){
    return tracker;
  }
  else
    return '\0';
  }*/
/*----------------------------------------Reset-------------------------------------------*/
int ResetQueue(int r){
  if(r == 1){
    tracker = rear;
  } else if(r == 0){
    tracker = anchor;
  }else
    tracker = tracker;
  return 0;
}
/*----------------------------------------Delete-------------------------------------------*/
/*int DeleteQueue(Node *pointer){
  // base case
   if(anchor == NULL || pointer == NULL)
     return 0;

   // If node to be deleted is head node
   if(anchor == pointer)
     anchor = pointer->next;

   // Change next only if node to be deleted is NOT the last node
   if(pointer->next != NULL)
     pointer->next->previous = pointer->previous;

   // Change prev only if node to be deleted is NOT the first node
   if(pointer->previous != NULL)
     pointer->previous->next = pointer->next;

   // Finally, free the memory occupied by del
   free(pointer);
   tracker = anchor; // reset static pointer
   return 1;
}*/
