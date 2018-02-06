// ListOfPresidents.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "President.h"
#include "cstdlib"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

const string INTPUT_FILE_NAME = "input.txt";
const string OUTPUT_FILE_NAME = "output.txt";

int main()
{
	LoadFile();
    return 0;
}

void LoadFile()
{
	ifstream inputFile;
	inputFile.open(INTPUT_FILE_NAME);
	if (!inputFile.good())
		cout << "There was an issue opening the file " << INTPUT_FILE_NAME << ". Please check the file and try again.";
	else
	{
		string line;
		while(getline(inputFile, line))
		{
			cout << line << endl;
		}
	}
}

void AddPresident()
{
	auto pres = President();
	auto date = Date();

	string middleName;

	cout << "Enter the first name: ";
	cin >> pres.FirstName;
	cout << "Enter the middle name (enter \"N/A\" if no middle name): ";
	cin >> pres.MiddleName;
	cout << "Enter the last name: ";
	cin >> pres.LastName;
	cout << "Enter the month of inauguration: ";
	cin >> date.Month;
	cout << "Enter the day of inauguration (e.g. \"10\" for the 10th): ";
	cin >> date.Day;
	cout << "Enter the year of inauguration (e.g. \"2001\"): ";
	cin >> date.Year;

	pres.DateInaugurated = date;
}

