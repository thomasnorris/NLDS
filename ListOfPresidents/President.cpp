#include "stdafx.h"
#include "President.h"

President::President()
{
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
