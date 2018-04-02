#include "passphrasevalidator.h"

bool stringsAreAnagrams(const char* str1, const char* str2){
	int tally[256];
	for(int i=0; i < 256; i++){
		tally[i] = 0;
	}
	int j=0;
	while(str1[j] != '\0'){
		tally[str1[j]]++;
		j++;
	}
	j = 0;
	while(str2[j] != '\0'){
		tally[str2[j]]--;
		j++;
	}
	for(int i=0; i < 256; i++){
		if(tally[i] != 0){
			return false;
		}
	}
	return true;
}

bool PassphraseValidator::validatePassphrase(string phrase, int part){
	char* pphrase = AdventHelper::stringToCString(phrase);
	int splitCount = 1 + AdventHelper::instancesOfCharInCString(' ', pphrase);
	char **split = new char*[splitCount];
	AdventHelper::splitCStringOnChar(pphrase, ' ', split, splitCount);

	for(int i = 0; i < splitCount; i++){
		for(int j = i+1; j < splitCount; j++){
			if(part == 1 && strcmp(split[i], split[j]) == 0) {
				return false;
			}
			else if(part == 2 && stringsAreAnagrams(split[i], split[j])){
				return false;
			}
		}
	}
	return true;
}

int PassphraseValidator::countValidPassphrases(InputLine* input, int part){
	int valid = 0;
	while(input){

		string phrase = input->getLine();

		if(this->validatePassphrase(phrase, part)){
			valid++;
		}
		
		input = input->getNext();
	}
	return valid;
}