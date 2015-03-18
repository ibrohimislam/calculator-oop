
#ifndef _ROMAWI_H_
#define _ROMAWI_H_
#include "Token.h"
#include "Bilangan.h"


class Romawi: public Bilangan{
	public:
		Romawi();
		Romawi(string);
		long double GetValue();
	private:
		int Value;
};

#endif
