#ifndef __PASSPHRASE_VALIDATOR_H__
#define __PASSPHRASE_VALIDATOR_H__

#include <string>
#include <cstring>
#include "adventhelper.h"
#include "inputline.h"

using namespace std;

class PassphraseValidator{
	public:
		bool validatePassphrase(string phrase);
		int countValidPassphrases(InputLine* input);
};

// class PassphraseOrganizer

#endif
