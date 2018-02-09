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
#include <algorithm>
using namespace std;

const string INTPUT_FILE_NAME = "input.txt";
const string OUTPUT_FILE_NAME = "output.txt";
const string LIST_COMMAND = "L";
const string ADD_COMMAND = "A";
const string FIND_STATE_COMMAND = "F";
const string PREVIOUS_COMMAND = "P";
const string NEXT_COMMAND = "N";
const string QUIT_COMMAND = "Q";
const string NEXT_KEYWORD = "Next";
const string PREVIOUS_KEYWORD = "Previous";
const string NO_MIDDLE_NAME = "N/A";

vector<President> _presidents;

int main()
{
	LoadFile();

	cout << "There are a number of commands that can be entered:" << endl;
	string command;
	while (command != QUIT_COMMAND)
	{
		cout << "\"" << LIST_COMMAND << "\" will list all of the presidents and their information." << endl;
		cout << "\"" << ADD_COMMAND << "\" will further prompt to add a president to the list." << endl;
		cout << "\"" << FIND_STATE_COMMAND << "\" will further prompt to find all presidents that are from a certain state." << endl;
		cout << "\"" << PREVIOUS_COMMAND << "\" will further prompt to find the previous president in the list from one entered." << endl;
		cout << "\"" << NEXT_COMMAND << "\" will further prompt to find the next president in the list from one entered." << endl;
		cout << "\"" << QUIT_COMMAND << "\" will save the information to " << OUTPUT_FILE_NAME << " and then exit." << endl << endl;
		cout << "Enter one of the commands and press \"Enter\": ";
		cin >> command;

		if (command == LIST_COMMAND)
			cout << GetAllPresidentInfo() << endl;
		
		else if (command == ADD_COMMAND)
			AddPresident();
		
		else if (command == FIND_STATE_COMMAND)
			FindPresidentsFromState();
		
		else if (command == PREVIOUS_COMMAND)
			cout << FindPresident(PREVIOUS_KEYWORD) << endl;
		
		else if (command == NEXT_COMMAND)
			cout << FindPresident(NEXT_KEYWORD) << endl;
		
		else if (command != QUIT_COMMAND)
			cout << "Invalid command." << endl << endl;
		
		if (command != QUIT_COMMAND)
			system("pause");
	}

	ofstream outputFile;
	outputFile.open(OUTPUT_FILE_NAME);

	if (!outputFile.good())
		DisplayFileError(OUTPUT_FILE_NAME);

	outputFile << GetAllPresidentInfo();

	cout << "File saved successfully to \"" << OUTPUT_FILE_NAME << "\"." << endl << endl;
	system("pause");

    return 0;
}

string FindPresident(string keyword)
{
	President presToFind = President();

	cout << "Enter the president's first name: ";
	cin >> presToFind.FirstName;
	cout << "Enter the president's middle name (enter " << NO_MIDDLE_NAME << " if no middle name): ";
	cin >> presToFind.MiddleName;
	cout << "Enter the president's last name: ";
	cin >> presToFind.LastName;

	int i = 0;
	for (auto pres : _presidents)
	{
		if ((ConvertToUpperCase(presToFind.FirstName) == ConvertToUpperCase(pres.FirstName)) && (ConvertToUpperCase(presToFind.MiddleName) == ConvertToUpperCase(pres.MiddleName) || ConvertToUpperCase(presToFind.MiddleName) == NO_MIDDLE_NAME || pres.MiddleName == "") && (ConvertToUpperCase(presToFind.LastName) == ConvertToUpperCase(pres.LastName)))
		{
			// --Previous and next presidents are found under the assumption that the oldest president is at the beginning of the file and newest presidents are at the end.
			if (keyword == PREVIOUS_KEYWORD)
			{
				if (i == 0)
					return "There is no previous president.\n";
				
				return "The previous president is:\n" + ConvertPresidentIntoString(_presidents[i - 1]);
			}
			
			if (i == _presidents.size() - 1)
				return "There is no next president.\n";

			return "The next president is:\n" + ConvertPresidentIntoString(_presidents[i + 1]);
		}
		++i;
	}

	return "President \"" + presToFind.FirstName + "\" was not found; cannot perform comparison.\n";
}

string GetAllPresidentInfo()
{
	string info;
	for (auto pres : _presidents)
		info += ConvertPresidentIntoString(pres);
	
	return info;
}

string ConvertPresidentIntoString(President pres)
{
	string presString;
	presString += pres.FirstName + "\n";
	presString += pres.MiddleName + "\n";
	presString += pres.LastName + "\n";
	presString += pres.DateInaugurated.Month + " " + to_string(pres.DateInaugurated.Day) + ", " + to_string(pres.DateInaugurated.Year) + "\n";
	presString += pres.DateResigned.Month + " " + to_string(pres.DateResigned.Day) += ", " + to_string(pres.DateResigned.Year) + "\n";
	presString += pres.Party += "\n";
	presString += pres.HomeState += "\n";

	return presString;
}

void LoadFile()
{
	ifstream inputFile;
	inputFile.open(INTPUT_FILE_NAME);

	if (!inputFile.good())
		DisplayFileError(INTPUT_FILE_NAME);

	string line;
	while (getline(inputFile, line))
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

		_presidents.push_back(pres);
	}
	
	cout << "The file \"" << INTPUT_FILE_NAME << "\" has loaded successfully." << endl << endl;
}

void DisplayFileError(string fileName)
{
	cout << "There was an issue opening the file \"" << fileName << "\". Please check the file and try again." << endl << endl;
	system("pause");
	_Exit(0);
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
	auto pres = President();
	
	cout << "Enter the first name: ";
	cin >> pres.FirstName;
	cout << "Enter the middle name (Enter " << NO_MIDDLE_NAME << " if no middle name): ";
	cin >> pres.MiddleName;
	cout << "Enter the last name: ";
	cin >> pres.LastName;
	cout << "Enter the month of inauguration (e.g. March): ";
	cin >> pres.DateInaugurated.Month;
	cout << "Enter the day of inauguration (e.g. \"10\" for the 10th): ";
	cin >> pres.DateInaugurated.Day;
	cout << "Enter the year of inauguration (e.g. \"2001\"): ";
	cin >> pres.DateInaugurated.Year;
	cout << "Enter the month of resignation: ";
	cin >> pres.DateResigned.Month;
	cout << "Enter the day of resignation: ";
	cin >> pres.DateResigned.Day;
	cout << "Enter the year of resignation: ";
	cin >> pres.DateResigned.Year;
	cout << "Enter their political party: ";
	cin >> pres.Party;
	cout << "Enter their home state: ";
	cin >> pres.HomeState;

	_presidents.push_back(pres);

	cout << "President \"" << pres.FirstName << "\" has been added." << endl << endl;
}

void FindPresidentsFromState()
{
	string state;
	cout << "Enter a state to find all presidents from: ";
	cin >> state;

	vector<President> matches;

	for (auto president : _presidents)
		if (ConvertToUpperCase(president.HomeState) == ConvertToUpperCase(state))
			matches.push_back(president);
	
	if (size(matches) == 0)
		cout << "There no matching presidents were found for the state of \"" << state << "\"." << endl << endl;
	else
	{
		cout << "There were " << size(matches) << " match(es) for state \"" << state << "\"." << endl;
		cout << "Matches include: " << endl;

		for (auto match : matches)
		{
			cout << match.FirstName << " ";
			match.MiddleName == "" ? cout << match.LastName << endl : cout << match.MiddleName << " " << match.LastName << endl;
		}
		cout << endl;
	}
}

string ConvertToUpperCase(string str)
{
	transform(str.begin(), str.end(), str.begin(), toupper);
	return str;
}

