// NumericalIntegration.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>

using namespace std;

void DoCalculations(double lower_limit, double upper_limit, int num_steps);

int main()
{
	double upperLimit;
	double lowerLimit;
	int numSteps;

	cout << "This program will approximate the value of the integral of Sin(x) given a lower limit, upper limit, and number of steps that should be used." << endl;
	cout << "Enter the lower limit: ";
	cin >> lowerLimit;
	cout << "Enter the upper limit: ";
	cin >> upperLimit;
	cout << "Enter the number of steps to use: ";
	cin >> numSteps;

	DoCalculations(lowerLimit, upperLimit, numSteps);

	return EXIT_SUCCESS;
}

void DoCalculations(double lowerLimit, double upperLimit, int numSteps)
{
	double stepSize = (upperLimit - lowerLimit) / numSteps;
}