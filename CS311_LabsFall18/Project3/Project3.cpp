#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <semaphore.h>
#include <pthread.h>

#include "setpath_defs.h"
#include "time_functions.h"
#include "turbine_defines.h"

#define HAVE_STRUCT_TIMESPEC //needed because pthread.h and some windows headers disagree on who owns the timespec struct.
#define turbineNumber COLCOUNT*ROWCOUNT
using namespace std;
/*============================================================Global=====================================================================*/
typedef struct turbinePos{
    int m;
    int n;
}turbinePos;

float  maxPower[ROWCOUNT][COLCOUNT];
float currPower[ROWCOUNT][COLCOUNT];
float prevPower[ROWCOUNT][COLCOUNT];
turbinePos  pos[ROWCOUNT][COLCOUNT];

pthread_t turbine[ROWCOUNT][COLCOUNT];
bool turbine_run[ROWCOUNT][COLCOUNT];

pthread_mutex_t mutex_condition = PTHREAD_MUTEX_INITIALIZER; //PTHREAD_MUTEX_INITIALIZER initializes the static mutex, setting its attributes to default values
pthread_cond_t turbine_done = PTHREAD_COND_INITIALIZER; //PTHREAD_COND_INITIALIZER initializes the static condition variable cond, setting its attributes to default values
pthread_cond_t turbine_start = PTHREAD_COND_INITIALIZER;

int turbineCounter = 0; // counts how many turbines have run 
float cycle_target_values;
/*==========================================================Prototypes====================================================================*/
void *generator(void* arg);

/*============================================================Main=========================================================================*/
int main(){
    /*open file and get rid of text - prepare for parsing of initial conditions*/
    ifstream inFile;
    inFile.open("turbine_setup.txt", ios::in);
	ofstream outFile;
	outFile.open("p3-out.txt", ios::out | std::fstream::app); //std::fstream::app appends to file
    if(!inFile | !outFile){ // checks for errors in opening the file
        cout << "error in opening the turbine setup file" << endl; exit(1);
    }
    string line;
	getline(inFile, line); //Since the first line is text we will read it and discard
    //----------------read in initial values for max power---------------------
	for (int i = 0; i < ROWCOUNT; i++) { 
		for (int j = 0; j < COLCOUNT; j++) {
			inFile >> maxPower[i][j];
		}
	}
    //---------------read in initial values for current power------------------
    getline(inFile, line); getline(inFile, line); // we do this twice since the first one will discard the last line from max and second one will discard text
    for (int i=0; i < ROWCOUNT; i++) { 
        for (int j=0; j < COLCOUNT; j++) {
            inFile >> currPower[i][j];
        }
    }
    //-------------------ready target values for read in----------------------
    getline(inFile, line); getline(inFile, line); // we do this twice since the first one will discard the last line from curr and second one will store targets

    /*Update the generator values*/
    /*Create a 4th 2D global array of type pthread_t so you can use it in a loop to call pthread_create which starts the threads running. You CANNOT reuse a single pthread_t variable for ALL your threads.*/
    for(int i=0; i<ROWCOUNT; i++){
        for(int j=0; j<COLCOUNT; j++){
            pos[i][j].n = j;
            pos[i][j].m = i;
            pthread_create(&turbine[i][j], NULL, generator, &pos[i][j]);
			turbine_run[i][j] = true;
        }
    }

    pthread_mutex_lock(&mutex_condition);
    while (turbineCounter != turbineNumber){ // this will check that all turbines have run
		pthread_cond_wait(&turbine_done, &mutex_condition);
	}
	pthread_mutex_unlock(&mutex_condition);

    //-------------------print inital values of turbines--------------------------
	outFile << "Initial Values of Turbines are: " << endl;
	cout    << "Initial Values of Turbines are: " << endl;
    for (int i=0; i < ROWCOUNT; i++) { // print to screen and to output file 
		for (int j=0; j < COLCOUNT; j++) {
			outFile << currPower[i][j] << "   ";
			cout    << currPower[i][j] << "   ";
		}
		outFile << endl;
		cout    << endl;
	}
	outFile << "**********" << endl;
	cout    << "**********" << endl;

    while(inFile >> cycle_target_values){
        //if(inFile >> cycle_target_values) break; // grab the line we pulled ealier which contains the cycle target values
		swap(currPower, prevPower); //Exchanges the contents of the container adaptor (*this) by those of x.
		for (int i=0; i < ROWCOUNT; i++) { //iterate through turbines to reset so they can run again
			for (int j=0; j < COLCOUNT; j++) {
				turbine_run[i][j] = false;
			}
		}
		pthread_mutex_lock(&mutex_condition); //Locking will allow us to modify the conditional variable
		turbineCounter = 0; // reset count
		pthread_cond_broadcast(&turbine_start);
		while (turbineCounter != turbineNumber) {
			pthread_cond_wait(&turbine_done, &mutex_condition);
		}
		pthread_mutex_unlock(&mutex_condition); //unlock after threads are done 

		outFile << "Cycle Target Value is: " << cycle_target_values << endl;
		cout    << "Cycle Target Value is: " << cycle_target_values << endl;
		for (int i=0; i < ROWCOUNT; i++) {
			for (int j=0; j < COLCOUNT; j++) {
				outFile << currPower[i][j] << "   ";
				cout    << currPower[i][j] << "   ";
			}
			outFile << endl;
			cout    << endl;
		}
		outFile << "**********" << endl;
		cout    << "**********" << endl;
		millisleep(TFARM_CYCLE_TIME * 1000); //Wait for T ms
	}
	return 0;
}//end of main
#include "setpath_fn.h"

/*==========================================================Functions======================================================================*/
void *generator(void* arg){ //thread function 
    turbinePos *tpos = (turbinePos *)arg;
    int row, col;
    row = tpos->m; col = tpos->n;

    while(true){
        pthread_mutex_lock(&mutex_condition); //pthread_mutex_lock takes a pointer so we use & to access the address
        turbineCounter++;
        turbine_run[row][col] = true; // used to show that this turbine has already run
        pthread_cond_signal(&turbine_done); //Inform main that you are done 

        while(true){
            pthread_cond_wait(&turbine_start, &mutex_condition);
            if(!turbine_run[row][col]) break; // fix this!!
        }

        pthread_mutex_unlock(&mutex_condition);
        //------------------------------------------------------------------
        float _neighbors = 0, sum = 0;
		if (row > 0){          //(NORTH) if current position is not greater than 0 then we do not have a north
			sum += prevPower[row-1][col];
            _neighbors++;
		}
        if (row < ROWCOUNT-1){ //(SOUTH) if current position is on the last row then we do not have a south neighbor
			sum += prevPower[row+1][col];
            _neighbors++;
		}
		if (col < COLCOUNT-1){ //(EAST) if current position is on the last col then we do not have an east neighbor
			sum += prevPower[row][col+1];
            _neighbors++;
		}
		if (col > 0){          //(WEST) if current position is on the first col then we do not have a west neighbor
			sum += prevPower[row][col-1];
            _neighbors++;
		}
		float average = (sum + prevPower[row][col]) / (_neighbors+1);

		if (average < cycle_target_values){
			if (prevPower[row][col] + (currPower[row][col] * 0.3) > maxPower[row][col]) 
				currPower[row][col] = maxPower[row][col]; // If average is > than max, set it at max
			else
				currPower[row][col] = prevPower[row][col] + (currPower[row][col] * 0.3); //increase your output by 30% of current value.
		}else if (average > cycle_target_values){
			if (prevPower[row][col] - (currPower[row][col] * 0.3) < 0)
				currPower[row][col] = 0; //If average is < 0, set it to 0
			else
				currPower[row][col] = prevPower[row][col] - (currPower[row][col] * 0.3); //decrease your output by 30% of current value
		}else{
			currPower[row][col] = prevPower[row][col]; // covers edge case
		}
        //------------------------------------------------------------------
    }
    pthread_exit(NULL);
	return NULL;
}
