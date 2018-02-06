#include "stdafx.h"
#include "President.h"

President::President()
{
}

President::President(string firstName, string middleName, string lastName, Date dateInaugurated, Date dateResigned, string homeState)
{
	this->FirstName = firstName;
	middleName != "" ? this->MiddleName = middleName : this->MiddleName = "N/A";
	this->LastName = lastName;
	this->DateInaugurated = dateInaugurated;
	this->DateResigned = dateResigned;
	this->HomeState = homeState;
}

President::~President()
{
	const string FILLER = "DELETED";

	this->FirstName = FILLER;
	this->MiddleName = FILLER;
	this->LastName = FILLER;
	this->DateInaugurated = Date(FILLER, 99, 9999);
	this->DateResigned = Date(FILLER, 99, 9999);
	this->HomeState = FILLER;
}
