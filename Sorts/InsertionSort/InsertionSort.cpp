/*==============================insertion sort================================*/
//like a poker hand - go thru from index 0-n and comapres current to previous
// moves current is smaller
void mysorts::Sort(int arr[]){
   cout << "The int array is:    ";
   for(i = 1; i < arr_size-1; i++){
      key = arr[i];
      j = i-1;
      while( (arr[j] > key) && (j >= 0) ){
          arr[j+1] = arr[j];
          j = j-1;
      }
      arr[j+1] = key;
  }
}
