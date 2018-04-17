/*===============================Bubble sort==================================*/
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
