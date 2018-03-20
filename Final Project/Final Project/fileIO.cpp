//Charles Canasa
#include "BST.h"
#include "macHash.h"
#include "fileIO.h"

fileIO::fileIO()
{
	inPath = "";
	inFile = "apple.txt";
	count = 0;
	done = 0;
}

fileIO::~fileIO()
{

}

int fileIO::readFile(macBook catalog[])	//opens file of apple data and inserts into macbook object
{
	//Opens input file where .cpp file is
	inputFile.open(inFile);

	//Directs to file if initial input file can't be found/opened
	while (inputFile.fail())
	{
		inputFile.clear();
		std::cout << "File not found, please enter the folder path where your input file is located.\n(e.g. 'C:\\Users\\')\n";
		getline(std::cin, inPath);
		std::cout << "Now enter the file name including its extension.\n(e.g. 'name.txt')\n";
		getline(std::cin, inFile);
		inputFile.open(inPath + inFile);
	}

	while (inputFile)
	{
		//Inserts each line into corresponding object attribute
		getline(inputFile, orderNum);
		catalog[count].setOrderNum(orderNum);

		getline(inputFile, name);
		catalog[count].setName(name);

		getline(inputFile, releaseDate);
		catalog[count].setReleaseDate(releaseDate);

		inputFile >> price;
		inputFile.ignore();
		catalog[count].setPrice(price);

		inputFile >> quantity;
		inputFile.ignore();
		catalog[count].setQuantity(quantity);

		count++;

	/*	if (inputFile.eof())
		{
			done++;
		}*/
	}
	inputFile.close();

	/*
	//check if books are read correctly without using overloaded <<
	for (int i = 0; i < count; i++)
	{
	std::cout << catalog[i].orderNum << std::endl;
	std::cout << catalog[i].name << std::endl;
	std::cout << catalog[i].releaseDate << std::endl;
	std::cout << catalog[i].price << std::endl;
	std::cout << catalog[i].quantity << std::endl;
	}
	*/

	return count;
}


void fileIO::writeFile(macBook catalog[], int size)
{
	//if you dont want initial book inventory rewritten
	//outputFile.open("output.txt");

	//rewrites initial text file
	outputFile.open(inPath + inFile);

	//writes inventory into file
	for (int i = 0; i < size; i++)
	{
		outputFile << catalog[i].orderNum << std::endl;
		outputFile << catalog[i].name << std::endl;
		outputFile << catalog[i].releaseDate << std::endl;
		outputFile << catalog[i].price << std::endl;
		outputFile << catalog[i].quantity;
		//prevents an extra empty line at the end avoiding a bad reusable file
		if (i != size - 1)
		{
			outputFile << std::endl;
		}
	}

	outputFile.close();
}