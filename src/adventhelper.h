#ifndef __ADVENT_HELPER_H__
#define __ADVENT_HELPER_H__

#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

class AdventHelper{
	public:
		static int instancesOfCharInCString(char c, const char* cstr);
		static char* stringToCString(string str);
		static void splitCStringOnChar(const char* cstring, char divider, char** outSplit, int splitCount);
};

#endif