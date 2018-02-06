#include "cstdlib";
#include "Date.h"
#include <chrono>

Date::Date(string month, int day, int year)
{
	this->month = month;
	this->day = day;
	this->year = year;
}

Date::~Date()
{
	this->month = "DELETED";
	this->day = 99;
	this->year = 9999;
}
