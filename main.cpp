#include <iostream>

using namespace std;

int main(int argc , char* argv[]){
	if(argc < 2){
		cerr << "Missing Argument for Challenge Number (1-25)" << endl;
		return 1;
	}
	char* challenge = argv[1];
	cout << "Advent of Code 2017: Challenge " << challenge << endl;

	return 0;
}