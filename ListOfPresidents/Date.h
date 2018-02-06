
#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date
{
public:
	Date();
	Date(string month, int day, int year);
	~Date();

	string Month;
	int Day;
	int Year;
};

#endif // DATE_H