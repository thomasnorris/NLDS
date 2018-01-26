// NumericalIntegration.cpp : Defines the entry point for the console application.
// Created by Thomas Norris for EECS:2510

#include "stdafx.h"
#include <iostream>
#include <list>
#include <iomanip>

using namespace std;

int _numSteps;
double _total = 0;
double _upperLimit = 0;
double _lowerLimit = 0;

void DoCalculationsAndPrintResults(double lower_limit, double step_size, int i);

int main()
{
	cout << "This program will approximate the value of the integral of Sin(x) using Simpson's rule given a lower limit, upper limit, and number of steps that should be used." << endl;

	cout << "Enter the lower limit: ";
	cin >> _lowerLimit;
	cout << "Enter the upper limit: ";
	cin >> _upperLimit;
	cout << "Enter the number of steps to use: ";
	cin >> _numSteps;
	cout << endl << "A table of calculation data follows" << endl << endl;

	double stepSize = (_upperLimit - _lowerLimit) / _numSteps;

	cout << "The step size is " << stepSize << "." << endl << endl;

	DoCalculationsAndPrintResults(_lowerLimit, stepSize, 0);

	return EXIT_SUCCESS;
}

void DoCalculationsAndPrintResults(double a, double h, int count)
{
	// Variable names came from the handout
	double b = a + h;
	double firstPart = sin(a);
	double secondPart = sin(((2 * a) + b) / 3);
	double thirdPart = sin((a + (2 * b)) / 3);
	double fourthPart = sin(b);
	double value = ((b - a) / 8) * (firstPart + (3 * secondPart) + (3 * thirdPart) + fourthPart);

	_total += value;

	FormatAndPrint(b);
	FormatAndPrint(firstPart);
	FormatAndPrint(secondPart);
	FormatAndPrint(thirdPart);
	FormatAndPrint(fourthPart);
	FormatAndPrint(value);
	cout << endl;
	
	if (count != _numSteps - 1)
		DoCalculationsAndPrintResults(b, h, ++count);
	else
	{
		cout << endl << "Calculations completed." << endl << endl << "The value of the integration of Sin(x) with a lower limit of " << _lowerLimit << " and an upper limit of " << _upperLimit << " using " << _numSteps << " steps is approximately " << _total << "." << endl << endl;
		system("pause");
	}
}

void FormatAndPrint(double value)
{
	cout << left << setprecision(5) << setw(10) << value;
}