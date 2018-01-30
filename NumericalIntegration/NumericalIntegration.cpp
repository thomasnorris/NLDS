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
	vector<double> calculations;

	calculations.push_back(a);
	calculations.push_back(a + _stepSize);
	calculations.push_back(sin(a));
	calculations.push_back(sin(((2 * a) + calculations[1]) / 3));
	calculations.push_back(sin((a + (2 * calculations[1])) / 3));
	calculations.push_back(sin(calculations[1]));
	calculations.push_back(((calculations[1] - a) / 8) * (calculations[2] + (3 * calculations[3]) + (3 * calculations[4]) + calculations[5]));

	_total += calculations[6];

	for (auto it = calculations.begin(); it != calculations.end(); ++it) {
		FormatAndPrint(*it);
	}

	cout << endl;
	
	if (count != _numSteps - 1)
		DoCalculationsAndPrintResults(calculations[1], ++count);
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