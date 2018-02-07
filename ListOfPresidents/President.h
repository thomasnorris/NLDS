
#ifndef PRESIDENT_H
#define PRESIDENT_H

#include <string>
#include "Date.h"
using namespace std;

class President
{
public:
	President();
	~President();

	string FirstName;
	string MiddleName;
	string LastName;
	Date DateInaugurated;
	Date DateResigned;
	string Party;
	string HomeState;
};

#endif // PRESIDENT_H