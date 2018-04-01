#ifndef __INVERSE_CAPTCHA_H__
#define __INVERSE_CAPTCHA_H__

#include <stdlib.h>
#include <cstring>
#include "inputline.h"

using namespace std;

class InverseCaptcha{
	public:
		int processData(InputLine *data);
		int processData2(InputLine *data);
};

#endif