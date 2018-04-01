#include "spiralmemory.h"

MemoryCell::MemoryCell(MemoryRing *ring, int _spiralIdx){
	if(ring->getCapacity() > spiralIdx){
		parent = ring;
		spiralIdx = _spiralIdx;
		relativeRingIdx = parent->getRelativeIdx(spiralIdx);

		if(parent->getRingIndex() == 0){
			x = 0;
			y = 0;
		} else {
			int ri = parent->getRingIndex();
			int sl = parent->getSideLength();

			if(relativeRingIdx < (sl-1)){
				x = ri;
				y = relativeRingIdx + 1 - ri;
			} 
			else if(relativeRingIdx < 2*(sl-1))
			{
				x = ri - (relativeRingIdx % (sl-1)) - 1;
				y = ri;
			} 
			else if(relativeRingIdx < 3*(sl-1))
			{
				x = -ri;
				y = ri - (relativeRingIdx % (sl-1)) - 1;
			} 
			else 
			{
				x = (relativeRingIdx % (sl-1))+1 - ri;
				y = -ri;
			}
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
	return _x + _y - 1;
}

MemoryRing::MemoryRing(int index){
	ring = index;
	sideLen = 1+(2*(ring));
	capacity = sideLen *sideLen;
	perimeter = 4 * (sideLen - 1);
	//special case for ring 0
	if(perimeter == 0) perimeter = 1;

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
	int val = atoi(value.c_str());

	// allocate spiral space assuming we will 
	// hit > value in fewer than value cells
	int maxRing = 0;
	int maxCap = 1;
	while(maxCap < val){
		maxRing++;
		maxCap = (maxRing*2 + 1) * (maxRing*2 + 1);
	}

	spiral = new MemoryRing*[maxRing];


	spiral[0] = new MemoryRing(0);
	spiral[0]->cells[0] = new MemoryCell(spiral[0], 0);
	spiral[0]->cells[0]->value = 1;

	int ringIdx = 0;
	int spiralIdx = 1;
	int maxVal = 1;

	while(maxVal <= val){
		if(spiralIdx >= spiral[ringIdx]->getCapacity()){
			ringIdx++;
			spiral[ringIdx] = new MemoryRing(ringIdx);
		}

		int relativeIdx = spiral[ringIdx]->getRelativeIdx(spiralIdx);
		MemoryCell *c = new MemoryCell(spiral[ringIdx], spiralIdx);
		spiral[ringIdx]->cells[relativeIdx] = c;

		int newVal = 0;


		for(int i = relativeIdx - 1; i >=0; i--){
			if(c->isNeighborsWithCell(spiral[ringIdx]->cells[i])){
				newVal += spiral[ringIdx]->cells[i]->value;
			}
		}
		MemoryRing *prevRing = spiral[ringIdx-1];
		for(int i = 0; i < prevRing->getPerimeter(); i++){
			if(c->isNeighborsWithCell(prevRing->cells[i])){
				newVal += prevRing->cells[i]->value;
			}
		}

		c->value = newVal;

		// printf("X: %d,\t Y: %d,\t Ring: %d,\t SpiralIdx: %d, RelIdx: %d, Val: %d\n", c->getX(), c->getY(), ringIdx, spiralIdx, relativeIdx, newVal);

		if(newVal > maxVal){
			maxVal = newVal;
		}
		spiralIdx++;
	}

	return maxVal;
}