// Henry Chen CS-311 Project 1
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "time_functions.h"

#ifndef _WIN32
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#endif

using namespace std;
/* ------------------------------------Prototypes--------------------------------------- */
int func_1(char* in_path, char* out_path);
int func_2(char* in_path, char* out_path);
/* ------------------------------------------------------------------------------------- */

int main(int argc, char* argv[]) {
	if(argc != 2) exit(99);
/* -------------------------------------Pathing----------------------------------------- */
	// set path names for platform neutral file access
	#ifdef _WIN32  //Windows
	       char in_path[]="C:\\temp\\coursein\\p1-in.txt";
	       char out_path[]="C:\\temp\\courseout\\p1-out.txt";
	#else          //Linux
           char in_path[200], out_path[200];
           const char *homedir;
           homedir = getenv("HOME");
           if (homedir!= NULL)
                homedir = getpwuid(getuid())->pw_dir; // get the actual home directory for the current user
	       strcpy(in_path, homedir);
           strcpy(out_path, homedir);
           // now add on the common part of the path
	       strcat(in_path,"/temp/coursein/p1-in.txt"); //strcat(in_path,"/Downloads/read.txt");
           strcat(out_path,"/temp/courseout/p1-out.txt"); //strcat(out_path,"/Downloads/write.txt");
	#endif
/* ------------------------------------------------------------------------------------- */
	std::string mode = argv[1];
	if (mode == "0") {
		func_1(in_path, out_path);
	}
	if (mode == "1") {
		func_2(in_path, out_path);
	}
	system("pause");
	return 0;
}

int func_1(char* in_path, char* out_path) {
	char c;
	ifstream inFile;
	inFile.open(in_path, ios::in);
	ofstream outFile;
	outFile.open(out_path, ios::out | std::fstream::app); //std::fstream::app appends to file

	if (!inFile | !outFile) { // if either file doesnt open
		cout << "error in opening a file" << endl;
		return 1;
	}
	/* ---------------------------------------TIME------------------------------------------ */
	start_nanotime();
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

	cout << "CPU clock is:" << (get_nanodiff() / 1000000.0) << " ms" << endl;
	cout << "Wall clock is:" << get_wall_clock_diff()  * 1000.0 << " ms" << endl;
	/* ------------------------------------------------------------------------------------- */

	outFile.close();
	inFile.close();
	return 0;
}

int func_2(char* in_path, char* out_path) {
	ifstream inFile;
	inFile.open(in_path, ios::in);
	ofstream outFile;
	outFile.open(out_path, ios::out | std::fstream::app);

	if (!inFile) {
		cout << "error in opening file" << endl;
		return 1;
	}
	/* ---------------------------------------TIME------------------------------------------ */
	start_nanotime();
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

	cout << "CPU clock is:" << (get_nanodiff() / 1000000.0) << " ms" << endl;
	cout << "Wall clock is:" << get_wall_clock_diff()  * 1000.0 << " ms" << endl;
	/* ------------------------------------------------------------------------------------- */

	outFile.close();
	inFile.close();
	return 0;
}
