//Charles Canasa

#pragma once

#include "macBook.h"

#include <iostream>
#include <fstream>
#include <iomanip>


class fileIO : public macBook
{
private:
	std::ifstream inputFile;
	std::string inPath;
	std::string inFile;
	std::ofstream outputFile;
	int count;
	int done;


public:
	fileIO();
	~fileIO();

	//creates an array of book objects reading from a file
	int readFile(macBook[]);
	//creates an output file of books in the inventory/can reuse same txt file
	void writeFile(macBook[], int);
};