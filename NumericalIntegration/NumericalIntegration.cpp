// NumericalIntegration.cpp : Defines the entry point for the console application.
// Created by Thomas Norris for EECS:2510

#include "stdafx.h"
#include <iostream>
#include <list>

using namespace std;

int _numSteps;
double _total = 0;

void DoCalculations(double lower_limit, double step_size, int i);

int main()
{
	double upperLimit;
	double lowerLimit;

	cout << "This program will approximate the value of the integral of Sin(x) given a lower limit, upper limit, and number of steps that should be used." << endl;
	cout << "Please input only valid numbers." << endl << "" << endl;

	cout << "Enter the lower limit: ";
	cin >> lowerLimit;
	cout << "Enter the upper limit: ";
	cin >> upperLimit;
	cout << "Enter the number of steps to use: ";
	cin >> _numSteps;
	cout << endl << "A table of calculation data follows" << endl << endl;

	double stepSize = (upperLimit - lowerLimit) / _numSteps;
	
	DoCalculations(lowerLimit, stepSize, 0);

	return EXIT_SUCCESS;
}

void DoCalculations(double a, double h, int count)
{
	// Variable names came from the handout
	double b = a + h;
	double firstPart = sin(a);
	double secondPart = sin(((2 * a) + b) / 3);
	double thirdPart = sin((a + (2 * b)) / 3);
	double fourthPart = sin(b);
	double value = ((b - a) / 8) * (firstPart + (3 * secondPart) + (3 * thirdPart) + fourthPart);

	_total += value;

	cout << a << ", " << b << ", " << firstPart << ", " << secondPart << ", " << thirdPart << ", " << fourthPart << ", " << value << endl;
	
	if (count != _numSteps - 1)
		DoCalculations(b, h, ++count);
	else
	{
		cout << endl << "Calculations completed." << endl << endl << "The end result is approximately: " << _total << endl << endl;
		system("pause");
	}
}