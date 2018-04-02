#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "src/spiralmemory.h"
#include "src/corruptionchecksum.h"
#include "src/inversecaptcha.h"
#include "src/inputline.h"
#include "src/passphrasevalidator.h"

using namespace std;

int main(int argc , char* argv[]){

	if(argc != 3){
		printf("Please pass in only the challenge number and the path to the txt file that contains the challenge data\n");
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
		case 2:{	
			CorruptionChecksum *cc = new CorruptionChecksum(dataLines);
			int *ccSize = cc->getSize();
			printf("Day 2 Input Data (%dx%d):\n", ccSize[0], ccSize[1]);
			for(int row = 0; row < ccSize[0]; row++){
				for(int col = 0; col < ccSize[1]; col++){
					printf("%d\t", cc->getCell(row, col));
				}
				printf("\n");
			}
			int result1 = cc->processData();
			printf("\nDay 2 Part 1 Result: \n%d\n", result1);
			int result2 = cc->processData2();
			printf("\nDay 2 Part 2 Result: \n%d\n", result2);
			break;
		}
		case 3:{
			SpiralMemory *sm = new SpiralMemory();
			string square = dataLines->getLine();
			printf("Day 3 Input Data: %s\n", square.c_str());
			int distance = sm->stepsFromSquare(square);
			printf("Day 3 Part 1 Result: %d\n", distance);
			int magTest = sm->spiralMagnitudeTest(square);
			printf("Day 3 Part 2 Result: %d\n", magTest);
			break;
		}
		case 4:{
			PassphraseValidator *pv = new PassphraseValidator();
			int validCount = pv->countValidPassphrases(dataLines);
			printf("Day 4 Part 1 Result: %d\n", validCount);
			break;
		}
		default:{
			printf("Invalid challenge index given: %d\n", challenge);
			return 1;
		}
	}

	return 0;
}