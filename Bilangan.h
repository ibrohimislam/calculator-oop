#include "EnumToken.h"
#include <iostream>
#include "Token.h"

#ifndef _BILANGAN_H_
#define _BILANGAN_H_
class Bilangan: public Token{
	public:
		ctor(string S);
		Display(EnumBilangan T);
		virtual long double GetValue() ;//deffered
	private:
};

#endif
