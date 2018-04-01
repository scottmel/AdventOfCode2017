#ifndef __SPIRAL_MEMORY_H__
#define __SPIRAL_MEMORY_H__

#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class MemoryRing{
	private:
		int ring;
		int capacity;
		int sideLen;
	public:
		MemoryRing(int index);
		int getRingIndex();
		int getCapacity();
		int getSideLength();
		void updateIndex(int index);
		int getDistanceFromMidlineForSquare(int sq);
};

class SpiralMemory{
	public:
		int stepsFromSquare(string sq);

};

#endif
