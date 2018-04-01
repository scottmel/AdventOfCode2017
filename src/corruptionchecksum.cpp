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
	int sum = 0;
	for(int row = 0; row < numRows; row++){
		int max = -1;
		int min = -1;
		for(int col = 0; col < numCols; col++){
			int val = spreadsheet[row][col];
			if(val > max){
				max = val;
			}
			if(val < min || min == -1){
				min = val;
			}
		}
		sum += (max-min);
	}
	return sum;
}

int CorruptionChecksum::processData2(){
	int sum = 0;
	for(int row = 0; row < numRows; row++){
		int val1 = -1;
		int val2 = -1;
		for(int col = 0; col < numCols; col++){
			val1 = spreadsheet[row][col];
			for(int i = col+1; i < numCols; i++){
				int v = spreadsheet[row][i];

				if(val1 % v == 0){
					val2 = v;
					break;
				}
				if(v % val1 == 0){
					val2 = val1;
					val1 = v;
					break;
				}
			}
			if(val2 != -1){
				break;
			}
		}
		sum += val1/val2;
	}
	return sum;
}