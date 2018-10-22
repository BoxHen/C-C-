#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <semaphore.h>
#include <pthread.h>
#include "time_functions.h"
#include "setpath_defs.h"
using namespace std;

/* ------------------------------------Prototypes--------------------------------------- */
void *producer(void *arg); // producer function to run when thread starts
void *consumer(void *arg); // consumer function to run when thread starts
/* ------------------------------------------------------------------------------------- */
sem_t sem_thres, sem_incr, sem_decr;
pthread_t readFile, writeFile;

int read_index=0, write_index=0;
#define buffer_slot 10
string buffer[buffer_slot];
/* =========================================================================================================================== */
int main() {
	setpath();
	ifstream inFile;
	inFile.open(in_path, ios::in);
	ofstream outFile;
	outFile.open(out_path, ios::out | std::fstream::app); //std::fstream::app appends to file

	if (!inFile | !outFile) { // if either file doesnt open
		cout << "error in opening a file" << endl;
		exit(1);
	}

	// initialize an unnamed semaphore (since this is first time I am doing this it helps me remember! Not useless comment)
	sem_init(&sem_thres, 0, 1);
	sem_init(&sem_decr, 0, buffer_slot); // buffer size of 10
	sem_init(&sem_incr, 0, 0);

	/* ---------------------------------------TIME------------------------------------------ */
	start_timing();
	/* ------------------------------------------------------------------------------------- */

	// creates a new read and write thread and makes it executable
	if (pthread_create(&readFile, NULL, producer, &inFile)) { //On success, pthread_create() returns 0; on error, it returns an error number, and the contents of *thread are undefined.
		printf("Producer thread could not be created");
		return -1;
	}
	if (pthread_create(&writeFile, NULL, consumer, &outFile)) {
		printf("Consumer thread could not be created");
		return -1;
	}

	pthread_join(readFile, NULL); //blocks the calling thread until the specified thread terminates.
	pthread_join(writeFile, NULL);
	/* ---------------------------------------TIME------------------------------------------ */
	stop_timing();
	cout << "CPU clock is:" << (get_nanodiff() / 1000000.0) << " ms" << endl;
	cout << "Wall clock is:" << get_wall_clock_diff() * 1000.0 << " ms" << endl;
	/* ------------------------------------------------------------------------------------- */
	sem_destroy(&sem_thres);
	sem_destroy(&sem_incr);
	sem_destroy(&sem_decr);

	system("pause");
	return 0;
}
/*=======================================================Thread-1=============================================================*/
// read lines from the file and place into the buffer
void *producer(void *arg) { // when used in pthread_create, inFile is passed in (refer to doc for more info)
	ifstream *inFile = (ifstream*)arg;

	if (inFile) {
		for (string line; getline(*inFile, line);) {
			sem_wait(&sem_decr); // decrements &sem_decr. If the semaphore's value is greater than zero, then the decrement proceeds, and the function returns
			sem_wait(&sem_thres); // If the semaphore currently has the value zero, then the call blocks until either it becomes possible to perform the decrement

			buffer[write_index] = line;	// add in line from getline 
			write_index = (write_index + 1) % buffer_slot; // circular array as specified in description 

			sem_post(&sem_thres); // unlocks sem_thres which we previosuly locked
			sem_post(&sem_incr); // increment slots available in buffer

		}
		/* ---------------------------------------EOF-Reached------------------------------------------ */
		sem_wait(&sem_decr); // needed to add special character
		sem_wait(&sem_thres); 

		buffer[write_index] = "$%$%^&*(";	// special character which we need to find later

		sem_post(&sem_thres); 
		sem_post(&sem_incr);	
	}else {
		cerr << "Error: Not able to execute producer thread. Possible read file error.";
		exit(1);
	}
	pthread_exit(NULL);
	return NULL;
}
/*=======================================================Thread-2=============================================================*/
void *consumer(void *arg) {
	ofstream *outFile = (ofstream*)arg;
	streampos previousPos; // Type to represent positions in a stream.

	if (outFile){
		while(true){
			sem_wait(&sem_incr); 
			sem_wait(&sem_thres); 
			//as long as there is data in the buffer, waits if the buffer is empty
			if (buffer[read_index] == "$%$%^&*(" ) { // Special character located
				(*outFile).seekp(previousPos);
				break; // gets a line from a buffer slot and writes the line to a 2nd file BUT exits when the special code is in the buffer.
			}

			previousPos = (*outFile).tellp();
			(*outFile) << buffer[read_index] << endl; // write the line from buffer into new file
			read_index = (read_index + 1) % buffer_slot; 
			sem_post(&sem_thres);
			sem_post(&sem_decr);
		}
	}else {
		cerr << "Error: Not able to execute consumer thread. Possible write file error.";
		exit(1);
	}
	pthread_exit(NULL);
	return NULL;
}

#include "setpath_fn.h"
