#ifndef __SPIRAL_MEMORY_H__
#define __SPIRAL_MEMORY_H__

#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class MemoryRing;

class MemoryCell{
	private:
		int spiralIdx;
		int relativeRingIdx;
		int x;
		int y;
		MemoryRing *parent;
	public:
		MemoryCell(MemoryRing *ring, int _spiralIdx);
		int getSpiralIdx();
		int getRelativeRingIdx();
		int getY();
		int getX();
		int getDistanceFromAccess();
		bool isNeighborsWithCell(MemoryCell *c);
		int value;
};

class MemoryRing{
	private:
		int ring;
		int capacity;
		int sideLen;
		int perimeter;
	public:
		MemoryCell **cells;
		MemoryRing(int index);
		int getRingIndex();
		int getCapacity();
		int getSideLength();
		int getPerimeter();
		int getRelativeIdx(int index);
};

class SpiralMemory{
	private:
		MemoryRing **spiral;
	public:
		int stepsFromSquare(string sq);
		int spiralMagnitudeTest(string value);

};

#endif
