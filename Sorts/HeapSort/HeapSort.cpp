// n is size of heap
// i is the index in arr[]
void Heapify(int arr[], int n, int i){
  int largest = i; // we start at the root which is index 0 in the array
  int right = 2*i + 2;
  int left  = 2*i + 1;

  if( (left < n) && (arr[left] > arr[largest]) ){ // we want to check thar left is < than size of arr so we dont go out of array bounds
      largest = left;
  }
  if( (right < n) && (arr[right] > arr[largest]) ){
      largest = right;
  }
  if(largest != i){
      int Temp = arr[i];
      arr[i] = arr[largest];
      arr[largest] = Temp;

      //recursively do this heapify process
      Heapify(int arr, n, largest);
  }
}
