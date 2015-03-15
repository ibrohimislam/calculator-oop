#include "Token.h"
#include "Bilangan.h"

#ifndef _ARAB_H_
#define _ARAB_H_

class Arab: public Bilangan{
	public:
		Arab();
		Arab(string);
		long double GetValue();
	private:
		long double Value;
};

#endif
