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
double _stepSize = 0;

int main()
{
	cout << "This program will approximate the value of the integral of Sin(x) using Simpson's rule given a lower limit, upper limit, and number of steps that should be used." << endl;

	cout << "Enter the lower limit: ";
	cin >> _lowerLimit;
	cout << "Enter the upper limit: ";
	cin >> _upperLimit;
	cout << "Enter the number of steps to use: ";
	cin >> _numSteps;

	_stepSize = (_upperLimit - _lowerLimit) / _numSteps;

	cout << "The step size is " << _stepSize << "." << endl << endl;
	cout << endl << "A table of calculation data is shown below:" << endl << endl;

	DoCalculationsAndPrintResults(_lowerLimit, 0);

	return EXIT_SUCCESS;
}

void DoCalculationsAndPrintResults(double a, int count)
{
	// Variable names came from the handout
	double b = a + _stepSize;
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
		DoCalculationsAndPrintResults(b, ++count);
	else
	{
		cout << endl << "Calculations completed." << endl << endl << "The value of the integration of Sin(x) with a lower limit of " << _lowerLimit << " and an upper limit of " << _upperLimit << " using " << _numSteps << " step(s) is approximately " << _total << "." << endl << endl;
		system("pause");
	}
}

void FormatAndPrint(double value)
{
	cout << left << setprecision(5) << setw(10) << value;
}