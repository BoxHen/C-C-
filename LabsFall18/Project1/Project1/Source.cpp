#include <iostream>
#include <fstream>
#include <string>
#include "time_functions.h"
using namespace std;

int func_1() {
	char c;
	ifstream inFile;
	inFile.open("read.txt", ios::in); 
	ofstream outFile;
	outFile.open("write.txt", ios::out | std::fstream::app);

	if(!inFile) {
		cout << "error in opening file" << endl;
		return 1;
	}
	while(!inFile.eof()) {
		c = inFile.get(); // reads one ch at a time
		if (inFile.peek() == inFile.eof()) break;
		outFile << c;
	}
	outFile.close();
	inFile.close();
	return 0;
};

int func_2() {
	char c;
	ifstream inFile;
	inFile.open("read.txt", ios::in);
	ofstream outFile;
	outFile.open("write.txt", ios::out | std::fstream::app);

	if (!inFile) {
		cout << "error in opening file" << endl;
		return 1;
	}
	while (!inFile.eof()) {
		std::string line;
		std::getline(inFile, line); // reads one ch at a time
		if (inFile.peek() == inFile.eof()) break;
		outFile << line << endl;
	}
	outFile.close();
	inFile.close();
	return 0;
};

int main(int argc, char* argv) {
	int mode = argv[1];
	start_timing();

	func_2();

	stop_timing();
	double wall_clock = get_wall_clock_diff();
	cout << wall_clock;

	system("pause");
	return 0;
}