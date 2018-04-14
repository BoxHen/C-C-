#include "mysorts.h"
#include <iostream> //preprocessor directive which includes file we will use
#include <fstream>
using namespace std; // standard library

int main(){
    int    arr_int[arr_size];
    double arr_double[arr_size];
    float  arr_float[arr_size];

    ifstream inFile;

    inFile.open("sortin.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    for(int i=0; i<arr_size; i++){
        inFile >> arr_double[i];
    }
    inFile.close();

    mysorts LAB9;
    /*===========================print original===============================*/
    cout << "the text file reads: ";
    for(int i=0; i<arr_size-1; i++){
        cout << arr_double[i] << ",";
    }
    cout << arr_double[arr_size-1] << endl;
    /*=================================int===================================*/
    for(int i=0; i<arr_size; i++){
        arr_int[i]=(int)arr_double[i];
    }
    LAB9.Sort(arr_int);
    for(int i=0; i<arr_size-1; i++){
        cout << arr_int[i] << ",";
    }
    cout << arr_int[arr_size-1] << endl;
    /*===============================double==================================*/
    LAB9.Sort(arr_double);
    for(int i=0; i<arr_size-1; i++){
       cout << arr_double[i] << ",";
    }
    cout << arr_double[arr_size-1] << endl;
    /*===============================float===================================*/
    for(int i=0; i<arr_size; i++){
        arr_float[i]=(float)arr_double[i];
    }
    LAB9.Sort(arr_float);
    for(int i=0; i<arr_size-1; i++){
       cout << arr_float[i] << ",";
    }
    cout << arr_float[arr_size-1] << endl;
    return 0;
}
