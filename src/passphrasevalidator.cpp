#include "passphrasevalidator.h"

bool PassphraseValidator::validatePassphrase(string phrase){
	char* pphrase = AdventHelper::stringToCString(phrase);
	int splitCount = 1 + AdventHelper::instancesOfCharInCString(' ', pphrase);
	char **split = new char*[splitCount];
	AdventHelper::splitCStringOnChar(pphrase, ' ', split, splitCount);

	printf("Validating %s\n", pphrase);
	for(int i = 0; i < splitCount; i++){
		for(int j = i+1; j < splitCount; j++){
			if(strcmp(split[i], split[j]) == 0){
				printf("Duplicated block %d: %s, %d: %s\n\n", i, split[i], j, split[j]);
				return false;
			}
		}
	}
	printf("\n");
	return true;
}

int PassphraseValidator::countValidPassphrases(InputLine* input){
	int valid = 0;
	int invalid = 0;
	while(input){

		string phrase = input->getLine();

		if(this->validatePassphrase(phrase)){
			valid++;
		} else {
			invalid++;
		}

		input = input->getNext();
	}
	printf("invalid: %d\n", invalid);
	return valid;
}