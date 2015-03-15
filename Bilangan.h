#include "EnumToken.h"
#include <iostream>
#include "Token.h"

#ifndef _BILANGAN_H_
#define _BILANGAN_H_
class Bilangan: public Token{
	public:
		virtual long double GetValue() = 0;//deffered
	private:
};

#endif
