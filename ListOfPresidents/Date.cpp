#include "stdafx.h"
#include "Date.h"

Date::Date()
{
}

Date::Date(string month, int day, int year)
{
	this->Month = month;
	this->Day = day;
	this->Year = year;
}

Date::~Date()
{
	this->Month = "DELETED";
	this->Day = 99;
	this->Year = 9999;
}
