// ListOfPresidents.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "President.h"
#include "ListOfPresidents.h"
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
const string LIST_COMMAND = "L";
const string ADD_COMMAND = "A";
const string FIND_STATE_COMMAND = "F";
const string PREVIOUS_COMMAND = "P";
const string NEXT_COMMAND = "N";
const string QUIT_COMMAND = "Q";


int main()
{
	LoadFile();

	cout << "There are a number of commands that can be entered:" << endl;
	cout << "\"" << LIST_COMMAND << "\" will list all of the presidents and their information." << endl;
	cout << "\"" << ADD_COMMAND << "\" will further prompt to add a president to the list." << endl;
	cout << "\"" << FIND_STATE_COMMAND << "\" will further prompt to find all presidents that are from a certain state." << endl;
	cout << "\"" << PREVIOUS_COMMAND << "\" will further prompt to find the previous president in the list from one entered." << endl;
	cout << "\"" << NEXT_COMMAND << "\" will further prompt to find the next president in the list from one entered." << endl;
	cout << "\"" << QUIT_COMMAND << "\" will save the information to " << OUTPUT_FILE_NAME << " and then exit." << endl << endl;

	string command;
	while (command != QUIT_COMMAND)
	{
		
	}

    return 0;
}

void LoadFile()
{
	ifstream inputFile;
	inputFile.open(INTPUT_FILE_NAME);
	if (!inputFile.good())
	{
		cout << "There was an issue opening the file \"" << INTPUT_FILE_NAME << "\". Please check the file and try again." << endl << endl;
		system("pause");
		system("exit");
	}
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

			pres.DateInaugurated = FillDates(pres.DateInaugurated, line);
			getline(inputFile, line);
			pres.DateResigned = FillDates(pres.DateResigned, line);

			getline(inputFile, line);
			pres.Party = line;
			getline(inputFile, line);
			pres.HomeState = line;

			presidents.push_back(pres);
		}

		cout << "The file \"" << INTPUT_FILE_NAME << "\" has loaded successfully." << endl << endl;
	}
}

Date FillDates(Date date, string line)
{
	date.Month = line.substr(0, line.find(' '));
	date.Day = stoi(line.substr(line.find(' '), line.find(',')));
	date.Year = stoi(line.substr(line.find(',') + 1, line.length()));

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

