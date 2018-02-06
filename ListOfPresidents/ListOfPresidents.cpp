// ListOfPresidents.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cstdlib"
#include <string>
#include <iostream>
#include "President.h"
using namespace std;

int main()
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
    return 0;
}

