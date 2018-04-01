#include "corruptionchecksum.h"

CorruptionChecksum::CorruptionChecksum(InputLine *_data){
	data = _data;
	InputLine *cur = data;

	numRows = 0;
	numCols = 0;

	//calculate space needed
	while(cur){
		numRows++;

		string line = cur->getLine();
		int len = line.length();
		char dat[len+1];
		strcpy(dat, line.c_str());
		int rowCols = 1;
		for (int i = 0; i < len; ++i)
		{
			if(dat[i] == '\t'){
				rowCols++;
			}
		}
		if(rowCols > numCols){
			numCols = rowCols;
		}

		cur = cur->getNext();
	}

	//allocate space
	spreadsheet = new int*[numRows];
	for (int i = 0; i < numRows; ++i)
	{
		spreadsheet[i] = new int[numCols];
	}

	//populate space
	int r = 0;
	cur = data;
	while(cur){
		string line = cur->getLine();
		int len = line.length();
		char dat[len+1];
		strcpy(dat, line.c_str());

		int c = 0;
		int prevT = -1;
		for(int i = 0; i < len+1; ++i){
			if(dat[i] == '\t' || dat[i] == '\0'){
				int numLen = i - prevT - 1;
				char numStr[numLen];
				for(int j = i-numLen; j <= i; ++j){
					if(j == i){
						numStr[j-(i-numLen)] = '\0';
					} else {
						numStr[j-(i-numLen)] = dat[j];
					}
				}
				// printf("Parsing num starting %d, ending %d, len %d, parsed %s\n", i-numLen, i, numLen, numStr);
				spreadsheet[r][c++] = atoi(numStr);
				prevT = i;
			}
		}
		r++;
		cur = cur->getNext();
	}
}

int* CorruptionChecksum::getSize(){
	int *size = new int[2];
	size[0] = numRows;
	size[1] = numCols;
	return size;
}

int CorruptionChecksum::getCell(int row, int col){
	return spreadsheet[row][col];
}

int CorruptionChecksum::processData(){
	return 0;
}

int CorruptionChecksum::processData2(){
	return 0;
}