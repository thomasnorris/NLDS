
#ifndef PRESIDENT_H
#define PRESIDENT_H

#include <string>
#include "Date.h"
using namespace std;

class President
{
public:
	President();
	President(string firstName, string middleName, string lastName, Date dateInaugurated, Date dateResigned, string homeState);
	~President();

private:
	string FirstName;
	string MiddleName;
	string LastName;
	Date DateInaugurated;
	Date DateResigned;
	string HomeState;
};

#endif // PRESIDENT_H