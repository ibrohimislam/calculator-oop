#ifndef _ARAB_H_
#define _ARAB_H_

#include "Token.h"
#include "Bilangan.h"
#include <string.h>

class Arab: public Bilangan{
	public:
		Arab();
		Arab(std::string);
		long double GetValue();
	private:
		long double Value;
};

#endif
