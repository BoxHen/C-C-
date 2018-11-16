#include <stdio.h>
#include <iostream>
#include <sstream> 
#include <fstream>
#include <string.h>
#include <string>
#include <semaphore.h>
#include <pthread.h>
#include <algorithm>
#include <cctype>

#include "setpath_defs.h"
#include "setpath_fn.h"
//#include "time_functions.h"
#include "turbine_defines.h"
using namespace std;

struct arrSize{
    int m;
    int n;
};


int intCount(string str); 
arrSize matrixSize();
/*=======================================================================================================================================*/
int main(){
    arrSize size;
    size =  matrixSize();
    cout << size.n << endl;
    cout << size.m << endl;
    float currPow[size.m][size.n];
	return 0;
}
/*=======================================================================================================================================*/
arrSize matrixSize(){
    arrSize size;
    int lineCount = 0,count = 0;
    ifstream inFile;
    inFile.open("turbine_setup.txt", ios::in);
    
    if(!inFile){ // checks for errors in opening the file
        cout << "error in opening the turbine setup file" << endl;
        exit(1);
    }

    while (!inFile.eof()) {
		string line;
		getline(inFile, line); // reads one line at a time
		//if (inFile.peek() == EOF) break; 
        if (!any_of(line.begin(), line.end(), ::isdigit)) { // checks if the line contains letter or numbers, increase count if line contains letters
            count++; 
            continue;
        }
        if (count > 1){
            //cout << intCount(line) << endl; 
            size.n = intCount(line); // This tracked the number of columns in the matrix
            break;
        }
        cout << line << endl;
        //cout << extractIntegerWords(line) << endl;
        lineCount++;
	}

	inFile.close();
    //cout << lineCount << endl; 
    size.m = lineCount; // This tracked the number of rows in the matrix
    return size;
}
/*=======================================================================================================================================*/
int intCount(string str) {// counts the number of integers in a line
    int count = 0;
    stringstream ss; 
    ss << str; //Storing the whole string into string stream 
    string temp; //Running loop till the end of the stream 
    int found; 
    while (!ss.eof()) { 
        ss >> temp; //extracting word by word from stream 
        if (stringstream(temp) >> found) count++; //Checking the given word is integer or not and increase count since int is found
        temp = ""; //To save from space at the end of string
    }
    return count; 
} 