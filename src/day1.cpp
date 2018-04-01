#include "day1.h"

int Day1::processData(InputLine *data){
	string line = data->getLine();
	int len = line.length();
	char dat[len+1];

	strcpy(dat, line.c_str());

	int i = 0;
	int total = 0;
	while(dat[i] != '\0'){

		char c = dat[i];
		char next = dat[i+1];
		if(next == '\0'){
			next = dat[0];
		}
		
		if(c == next){
			char cstr[] = {c, '\0'};
			int val = atoi(cstr);
			total += val;
		}
		i++;
	}
	return total;
}