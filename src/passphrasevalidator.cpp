#include "passphrasevalidator.h"

bool PassphraseValidator::validatePassphrase(string phrase){
	// char* pphrase = AdventHelper::stringToCString(phrase);
	
	// SplitCStringData* split = AdventHelper::splitCStringOnChar(pphrase, ' ');

	// int wordsInPhrase = split->arrLength;
	// char **words = split->splitString;

	// delete split;

	// for(int i = 0; i < wordsInPhrase; i++){
	// 	for(int j = i+1; j < wordsInPhrase; j++){
	// 		if(strcmp(words[i], words[j]) != 0){
	// 			return false;
	// 		}
	// 	}
	// }
	return true;
}

int PassphraseValidator::countValidPassphrases(InputLine* input){
	int valid = 0;
	while(input){

		string phrase = input->getLine();

		if(this->validatePassphrase(phrase)){
			valid++;
		}

		input = input->getNext();
	}
	return valid;
}