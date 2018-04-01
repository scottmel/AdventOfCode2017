#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "src/inversecaptcha.h"
#include "src/inputline.h"

using namespace std;

int main(int argc , char* argv[]){

	if(argc != 3){
		printf("Please pass in only the challenge number and the path to the txt file that contains the challenge data");
		return 1;
	}
	int challenge = atoi(argv[1]);
	char* filepath = argv[2];

	printf("Advent of Code 2017: Challenge %d, input file %s\n", challenge, filepath);

	InputLine *dataLines = NULL;

	ifstream datafile(filepath);
	if(datafile.is_open()){
		string line;
		while( getline(datafile, line) ){
			if(dataLines){
				dataLines->push(new InputLine(line));
			} else {
				dataLines = new InputLine(line);
			}
		}
		datafile.close();
	}

	switch(challenge){
		case 1:{
			printf("Day 1 Input Data: %s\n", dataLines->getLine().c_str());
			InverseCaptcha *ic = new InverseCaptcha();
			int result1 = ic->processData(dataLines);
			int result2 = ic->processData2(dataLines);
			printf("Day 1 Part 1 Result:\n%d\n", result1);
			printf("Day 1 Part 2 Result:\n%d\n", result2);
			break;
		}
		default:{
			printf("Invalid challenge index given: %d\n", challenge);
			return 1;
		}
	}

	return 0;
}