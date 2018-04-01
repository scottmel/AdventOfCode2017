#include "spiralmemory.h"

MemoryRing::MemoryRing(int index){
	ring = index;
	sideLen = 1+(2*(ring));
	capacity = sideLen *sideLen;
}

void MemoryRing::updateIndex(int index){
	ring = index;
	sideLen = 1+(2*(ring));
	capacity = sideLen * sideLen;
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

	int maxDist = ring;
	int perimeter = 4 * (sideLen - 1);
	int offset =  maxDist;
	int relativeIdx = perimeter - (capacity - sq) - offset;
	printf("perimeter: %d\noffset: %d\nrelativeIdx: %d\n", perimeter, offset, relativeIdx);
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
	printf("Mem Ring Idx: %d, Capacity: %d\n", ring, mring->getCapacity());
	int dist = mring->getDistanceFromMidlineForSquare(square);
	printf("Dist from Midline: %d\n", dist);
	return ring + dist;

}