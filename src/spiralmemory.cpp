#include "spiralmemory.h"

MemoryCell::MemoryCell(MemoryRing *ring, int _spiralIdx){
	if(ring->getCapacity() > spiralIdx){
		parent = ring;
		spiralIdx = _spiralIdx;
		relativeRingIdx = parent->getRelativeIdx(spiralIdx);

		int ri = parent->getRingIndex();
		int sl = parent->getSideLength();

		if(relativeRingIdx <= (sl-1)){
			x = ri;
			y = relativeRingIdx + 1 - ri;
		} 
		else if(relativeRingIdx <= 2*(sl-1))
		{
			x = ri - (relativeRingIdx % (sl-1));
			y = ri;
		} 
		else if(relativeRingIdx < 3*(sl-1))
		{
			x = -ri;
			y = ri - (relativeRingIdx % (sl-1));
		} 
		else 
		{
			x = (relativeRingIdx % (sl-1)) - ri;
			y = -ri;
		}
	}
}


int MemoryCell::getSpiralIdx(){
	return spiralIdx;
}
int MemoryCell::getRelativeRingIdx(){
	return relativeRingIdx;
}
int MemoryCell::getX(){
	return x;
}
int MemoryCell::getY(){
	return y;
}

bool MemoryCell::isNeighborsWithCell(MemoryCell *c){
	int cx = c->getX();
	int cy = c->getY();
	bool xNeighbor = cx <= (x+1) && cx >= (x-1);
	bool yNeighbor = cy <= (y+1) && cy >= (y-1);

	return xNeighbor && yNeighbor;
}

int MemoryCell::getDistanceFromAccess(){
	int _x = (x<0) ? -x : x;
	int _y = (y<0) ? -y : y;
	return _x + _y;
}

MemoryRing::MemoryRing(int index){
	ring = index;
	sideLen = 1+(2*(ring));
	capacity = sideLen *sideLen;
	perimeter = 4 * (sideLen - 1);

	cells = new MemoryCell*[perimeter];
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
int MemoryRing::getPerimeter(){
	return perimeter;
}

int MemoryRing::getRelativeIdx(int index){
	return perimeter - (capacity - index);
}

void MemoryRing::addCellAtRelativeIdx(MemoryCell *c, int index){
	cells[index] = c;
}

int SpiralMemory::stepsFromSquare(string sq){

	int square = atoi(sq.c_str());

	int ring = 0;
	int maxCap = 1;
	while(maxCap < square){
		ring++;
		maxCap = (ring*2 + 1) * (ring*2 + 1);
	}
	MemoryRing *mring = new MemoryRing(ring);

	printf("Mem Ring Idx: %d, Capacity: %d\n", ring, mring->getCapacity());


	MemoryCell *mcell = new MemoryCell(mring, square);

	return mcell->getDistanceFromAccess();
}

int SpiralMemory::spiralMagnitudeTest(string value){
	
	return 1;
}