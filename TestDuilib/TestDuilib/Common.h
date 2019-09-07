#pragma once
#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "../lib/DuiLib_ud.lib")  //"C:\\Users\\Administrator\\source\\repos\\TestDuilib\\lib\\DuiLib_ud.lib"
#   else
#       pragma comment(lib, "DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif
#include "MySQL.h"
#include <UIlib.h>
using namespace DuiLib;
CDuiString ANSIToUnicode(const string& str);
string UnicodeToANSI(const CDuiString& str);