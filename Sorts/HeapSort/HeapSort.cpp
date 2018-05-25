// n is size of heap
// i is the index in arr[]
void heapify(int arr[], int n, int i){
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
      swap(i, largest);
      //recursively do this heapify process
      heapify(int arr, n, largest);
  }
}

void sort(int arr[], int n){
  // Build heap (rearrange array)
   for (int i = n / 2 - 1; i >= 0; i--)
       heapify(arr, n, i);

   // One by one extract an element from heap
   for (int i=n-1; i>=0; i--)
   {
       // Move current root to end
       swap(arr[0], arr[i]);

       // call max heapify on the reduced heap
       heapify(arr, i, 0);
   }
}

void swap(int swap1, int swap2){
  int Temp = arr[swap1];
  arr[swap1] = arr[swap2];
  arr[swap2] = Temp;
}
