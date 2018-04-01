#ifndef __INPUT_LINE_H__
#define __INPUT_LINE_H__

#include <string>

using namespace std;

/*
	Simple Linked List to keep track of file inputs
*/

class InputLine {
	private:
		string line;
		InputLine *next;
	public:
		InputLine(string _line);
		~InputLine();
		void push(InputLine *l);
		InputLine *getNext();
		string getLine();
};

#endif