#ifndef __CORRUPTION_CHECKSUM_H__
#define __CORRUPTION_CHECKSUM_H__

#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include "adventhelper.h"
#include "inputline.h"

using namespace std;

class CorruptionChecksum{
	private:
		InputLine *data;
		int **spreadsheet;
		int numRows;
		int numCols;
	public:
		CorruptionChecksum(InputLine *_data);
		int processData();
		int processData2();
		int* getSize();
		int getCell(int row, int col);
};

#endif