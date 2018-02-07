// ListOfPresidents.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "President.h"
#include "cstdlib"
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;

const string INTPUT_FILE_NAME = "input.txt";
const string OUTPUT_FILE_NAME = "output.txt";
const char SPACE_DELIMITER = ' ';
const char COMMA_DELIMITER = ',';

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
		vector<President> presidents;

		while(getline(inputFile, line))
		{
			auto pres = President();

			pres.FirstName = line;
			getline(inputFile, line);
			pres.MiddleName = line;
			getline(inputFile, line);
			pres.LastName = line;
			getline(inputFile, line);

			pres.DateInaugurated = FillPresidentialDates(pres.DateInaugurated, line);
			getline(inputFile, line);
			pres.DateResigned = FillPresidentialDates(pres.DateResigned, line);

			getline(inputFile, line);
			pres.Party = line;
			getline(inputFile, line);
			pres.HomeState = line;

			presidents.push_back(pres);
		}
	}
}

Date FillPresidentialDates(Date date, string line)
{
	date.Month = line.substr(0, line.find(SPACE_DELIMITER));
	date.Day = stoi(line.substr(line.find(SPACE_DELIMITER), line.find(COMMA_DELIMITER)));
	date.Year = stoi(line.substr(line.find(COMMA_DELIMITER) + 1, line.length()));

	return date;
}

void AddPresident()
{
	// TODO: finish
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

