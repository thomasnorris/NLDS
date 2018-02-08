
#include "Date.h"
#include <vector>

string GetAllPresidentInfo();
void DisplayFileError(const string cs);
void LoadFile();
void AddPresident();
void FindPresidentsFromState(const string cs);
Date FillDates(const Date date, const string cs);
string ConvertToUpperCase(const string cs);
string ConvertPresidentIntoString(President pres);
string FindPresident(President pres, const string cs);