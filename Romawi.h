#include "Token.h"
#include "Bilangan.h"

#ifndef _ROMAWI_H_
#define _ROMAWI_H_

class Romawi: public Bilangan{
	public:
		Romawi();
		Romawi(string);
		int GetValue();
	private:
		int Value;
};

#endif
