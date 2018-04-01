#include "inputline.h"

InputLine::InputLine(string _line){
	line = _line;
	next = NULL;
}

InputLine::~InputLine(){
	if(next){
		delete next;
	}
}

string InputLine::getLine(){
	return line;
}

void InputLine::push(InputLine *l){
	if(next){
		next->push(l);
	} else {
		next = l;
	}
}

InputLine* InputLine::getNext(){
	return next;
}

