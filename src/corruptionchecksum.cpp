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
		char *dat = AdventHelper::stringToCString(line);
		int rowCols = 1 + AdventHelper::instancesOfCharInCString('\t', dat);

		if(rowCols > numCols){
			numCols = rowCols;
		}

		delete dat;

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
		
		char *dat = AdventHelper::stringToCString(line);

		char** cellData = new char*[numCols];
		AdventHelper::splitCStringOnChar(dat, '\t', cellData, numCols);

		for(int c = 0; c < numCols; c++){
			spreadsheet[r][c] = atoi(cellData[c]);
		}
		r++;

		delete dat;

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