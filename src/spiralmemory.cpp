#include "spiralmemory.h"

MemoryRing::MemoryRing(int index){
	ring = index;
	sideLen = 1+(2*(ring));
	capacity = sideLen *sideLen;
}

void MemoryRing::updateIndex(int index){
	ring = index;
	sideLen = 1+(2*(ring));
	capacity = sideLen;
}

int MemoryRing::getRingIndex(){
	return ring;
}
int MemoryRing::getCapacity(){
	return capacity;
}
int MemoryRing::getSideLength(){
	return sideLen;
}

int MemoryRing::getDistanceFromMidlineForSquare(int sq){
	if(capacity == 1) return 0;

	int maxDist = (sideLen-1)/2;
	int relativeIdx = capacity - sq - (maxDist - 1);
	if(relativeIdx < 0) relativeIdx *= -1;
	int quarterPlacement = relativeIdx % (sideLen - 1);

	if(quarterPlacement <= maxDist){
		return quarterPlacement;
	}
	return sideLen - 1 - quarterPlacement;
}

int SpiralMemory::stepsFromSquare(string sq){

	int square = atoi(sq.c_str());

	int ring = 0;
	MemoryRing *mring = new MemoryRing(ring);
	while(mring->getCapacity() < square){
		mring->updateIndex(++ring);
	}

	return ring + mring->getDistanceFromMidlineForSquare(square);

}