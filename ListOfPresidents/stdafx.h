// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include "Date.h"


// TODO: reference additional headers your program requires here

void LoadFile();
void AddPresident();
Date FillPresidentialDates(const Date date, const string cs);