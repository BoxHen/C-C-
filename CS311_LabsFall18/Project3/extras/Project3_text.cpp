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
/*============================================================Global======================================================================*/
struct turbinePos{
    int m;
    int n;
}turbinePos;

float  maxPower[ROWCOUNT][COLCOUNT];
float currPower[ROWCOUNT][COLCOUNT];
turbinePos  pos[ROWCOUNT][COLCOUNT];
pthread_t gener[ROWCOUNT][COLCOUNT];
float targetVal[1][6];

pthread_mutex_t mutex_condition = PTHREAD_MUTEX_INITIALIZER; //PTHREAD_MUTEX_INITIALIZER initializes the static mutex, setting its attributes to default values
pthread_cond_t turbine_done = PTHREAD_COND_INITIALIZER; //PTHREAD_COND_INITIALIZER initializes the static condition variable cond, setting its attributes to default values
pthread_cond_t turbine_start = PTHREAD_COND_INITIALIZER;

int turbineCounter = 0; // 
/*==========================================================Prototypes====================================================================*/
void generator(void* arg);

/*=======================================================================================================================================*/
int main(){
    /*open file and get rid of text - prepare for parsing of initial conditions*/
    ifstream inFile;
    inFile.open("turbine_setup.txt", ios::in);
    ofstream outFile ("parsedInfo.txt", ios::out | std::fstream::app); // create second file to read parsed data without words
    if(!inFile){ // checks for errors in opening the file
        cout << "error in opening the turbine setup file" << endl; exit(1);
    }
    while (!inFile.eof()) { // parses out the test in turbine_setup
		string line;
		getline(inFile, line); // reads one line at a time
        if (!any_of(line.begin(), line.end(), ::isdigit)) continue; // checks if the line contains letter and skips over it if letters are present
        outFile << line << endl;
    }
    outFile.close();

    /*Print initial values of generators*/
    ifstream inFile2("parsedInfo.txt", ios::in);
    if(!inFile2){ // checks for errors in opening the file
        cout << "error in opening the parsedInfo file" << endl; exit(1);
    }
    for (int i=0; i != ROWCOUNT; i++) { //read in initial values for max power
        for (int j=0; j != COLCOUNT; j++) {
            inFile2 >> maxPower[i][j];
        }
    }
    for (int i=0; i != ROWCOUNT; i++) { //read in initial values for current power
        for (int j=0; j != COLCOUNT; j++) {
            inFile2 >> currPower[i][j];
        }
    }
    for (int i=0; i != 1; i++) { //read in initial values for target cycle 
        for (int j=0; j != 6; j++) {
            inFile2 >> targetVal[i][j];
        }
    }
 /*----------------------------------------------------------prints------------------------------------------------------------------*/
    for (int i=0; i < ROWCOUNT; i++ ) {
        for (int j=0; j < COLCOUNT; j++ ) {
            cout << maxPower[i][j] << " ";
        }
        cout << endl;
   }
   for (int i=0; i < ROWCOUNT; i++ ) {
        for (int j=0; j < COLCOUNT; j++ ) {
            cout << currPower[i][j] << " ";
        }
        cout << endl;
   }
   for (int i=0; i < 1; i++ ) {
        for (int j=0; j < 6; j++ ) {
            cout << targetVal[i][j] << " ";
        }
        cout << endl;
   }

    /*Update the generator values*/
    /*Create a 4th 2D global array of type pthread_t so you can use it in a loop to call pthread_create which starts the threads running. You CANNOT reuse a single pthread_t variable for ALL your threads.*/
    for(int i=0; i<ROWCOUNT; i++){
        for(int j=0; j<COLCOUNT; j++){
            pos[i][j].n = i;
            pos[i][j].m = j;
        }
    }

	return 0;
}
/*=======================================================================================================================================*/
void generator(void* arg){
    turbinePos *tpos = (turbinePos *)arg;
    int m, n;
    m = turbinePos->m;
    n = turbinePos->n;

    while(true){
        pthread_mutex_lock(&mutex_condition); //pthread_mutex_lock takes a pointer so we use & to access the address
        turbineCounter++;

        //

        pthread_cond_signal(&turbine_done); //Inform main that you are done 

        while(true){
            pthread_cond_wait(&turbine_start, &mutex_condition);
            if(!ThreadRunAlready(m,n)) break; // fix this!!
        }

        pthread_mutex_unlock(&mutex_condition);
        
        
    }

}
