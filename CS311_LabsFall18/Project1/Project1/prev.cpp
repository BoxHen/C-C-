#include <iostream>
#include <fstream>
#include <string>
//#include <time.h>
//#include <sys/timeb.h>
#include "time_functions.h"
using namespace std;
/* ------------------------------------Prototypes--------------------------------------- */
int func_1();
int func_2();
/* ------------------------------------------------------------------------------------- */
int main(int argc, char* argv[]) {
	std::string mode = argv[1];
	if (mode == "0") {
		func_1();
		cout << "first" << endl;
	}
	if (mode == "1") {
		func_2();
		cout << "second" << endl;
	}
	system("pause");
	return 0;
}

int func_1() {
	char c;
	ifstream inFile;
	inFile.open("read.txt", ios::in);
	ofstream outFile;
	outFile.open("write.txt", ios::out | std::fstream::app); //std::fstream::app appends to file

	if (!inFile | !outFile) { // if either file doesnt open
		cout << "error in opening a file" << endl;
		return 1;
	}
	/* ---------------------------------------TIME------------------------------------------ */
	clock_t CPU_clock = clock(); // amount of time your program used the CPU to do work
	start_timing();
	/* ------------------------------------------------------------------------------------- */

	while (!inFile.eof()) {
		c = inFile.get(); // reads one ch at a time
						  //cout << c << endl;
		outFile << c;
		if (inFile.peek() == EOF) break; // looks to next to check if eof reached 
	}
	/* ---------------------------------------TIME------------------------------------------ */
	stop_timing(); // start and stop used for wall clock
	double wall_clock_diff = get_wall_clock_diff();
	CPU_clock = clock() - CPU_clock;
	double CPU_clock_diff = ((float)CPU_clock) / CLOCKS_PER_SEC;

	cout << "CPU clock is:" << CPU_clock_diff << "ms" << endl;
	cout << "Wall clock is:" << wall_clock_diff << "ms" << endl;
	/* ------------------------------------------------------------------------------------- */

	outFile.close();
	inFile.close();
	return 0;
}

int func_2() {
	ifstream inFile;
	inFile.open("read.txt", ios::in);
	ofstream outFile;
	outFile.open("write.txt", ios::out | std::fstream::app);

	if (!inFile) {
		cout << "error in opening file" << endl;
		return 1;
	}
	/* ---------------------------------------TIME------------------------------------------ */
	clock_t CPU_clock = clock(); // amount of time your program used the CPU to do work
	start_timing();
	/* ------------------------------------------------------------------------------------- */

	while (!inFile.eof()) {
		std::string line;
		std::getline(inFile, line); // reads one ch at a time
		outFile << line << endl;
		if (inFile.peek() == EOF) break;
	}
	/* ---------------------------------------TIME------------------------------------------ */
	stop_timing(); // start and stop used for wall clock
	double wall_clock_diff = get_wall_clock_diff();
	CPU_clock = clock() - CPU_clock;
	double CPU_clock_diff = ((float)CPU_clock) / CLOCKS_PER_SEC;

	cout << "CPU clock is:" << CPU_clock_diff << "ms" << endl;
	cout << "Wall clock is:" << wall_clock_diff << "ms" << endl;
	/* ------------------------------------------------------------------------------------- */

	outFile.close();
	inFile.close();
	return 0;
}