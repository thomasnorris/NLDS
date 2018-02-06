
#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

class Date
{
public:
	Date(string month, int day, int year);
	~Date();

private:
	string month;
	int day;
	int year;
};

#endif // DATE_H