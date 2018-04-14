#include "mysorts.h"
#include <iostream> //preprocessor directive which includes file we will use

using namespace std; // standard library
// :: - binary scope resolution operator
/*==============================insertion sort================================*/
//like a poker hand - go thru from index 0-n and comapres current to previous
// moves current is smaller
void mysorts::Sort(int arr[]){
   cout << "The int array is:    ";
   for(i = 1; i < arr_size; i++){
      key = arr[i];
      j = i-1;
      while( (arr[j] > key) && (j >= 0) ){
          arr[j+1] = arr[j];
          j = j-1;
      }
      arr[j+1] = key;
  }
}
/*==============================selection sort================================*/
// look for smallest and put in front
void mysorts::Sort(double arr[]){
    cout << "The double array is: ";
    for(i = 0; i < arr_size-1; i++){ // -1 since we dont need to check rightmost() it will be max already)
        min_index = i; // initialize min to first index
        // need 2 for loops since we cant keep updating min every loop
        for(j = i+1; j<arr_size; j++){
            if(arr[min_index] > arr[j]){
                min_index = j;
            }
        }
        Temp_d = arr[min_index]; // switches lowest value and index at beginning
        arr[min_index] = arr[i];
        arr[i] = Temp_d;
    }
}
/*===============================bubble sort==================================*/
// compares two at a time ex-(01)->(12)->(23)...
void mysorts::Sort(float arr[]){
    cout << "The float array is:  ";
    for(i=0; i<arr_size; i++){
        for(j=0; j<arr_size-i-1; j++){ // we do i-1 since the rightmsot is already the max - dont need to compare
            if(arr[j]>arr[j+1]){
                Temp_f = arr[j+1];
                arr[j] = arr[j+1];
                arr[j+1] = Temp_f;
            }
        }
    }
}
