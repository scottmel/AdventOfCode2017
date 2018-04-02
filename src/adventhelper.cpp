#include "adventhelper.h"


char* AdventHelper::stringToCString(string str){
	int len = str.length();
	char *cstr = new char[len+1];
	strcpy(cstr, str.c_str());

	return cstr;
}

int AdventHelper::instancesOfCharInCString(char c, const char* cstr){
	int count = 0;
	int i = -1;
	do {
		i++;
		if(cstr[i] == c) count++;
	} while (cstr[i] != '\0');

	return count;
}

void AdventHelper::splitCStringOnChar(const char* cstring, char divider, char** outSplit, int splitCount){
	int i = -1;
	int prevDiv = -1;
	int subStrIdx = 0;
	do {
		i++;
		if(cstring[i] == divider || cstring[i] == '\0')
		{
			int subLen = i - prevDiv - 1;
			char *subStr = new char[subLen];
			for(int j = i-subLen; j <= i; ++j){
				if(j == i){
					subStr[j-(i-subLen)] = '\0';
				} else {
					subStr[j-(i-subLen)] = cstring[j];
				}
			}
			outSplit[subStrIdx] = subStr;
			subStrIdx++;
			prevDiv = i;
		}
	} while(cstring[i] != '\0');

}