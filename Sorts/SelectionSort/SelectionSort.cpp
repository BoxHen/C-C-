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
