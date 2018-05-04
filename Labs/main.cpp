#include "mysorts.h"
#include <iostream> //preprocessor directive which includes file we will use
#include <fstream>
using namespace std; // standard library

int main(){

    ifstream inFile;

    inFile.open("math.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    for(int i=0; i<arr_size; i++){
        inFile >> arr_double[i];
    }
    inFile.close();

    return 0;
}
