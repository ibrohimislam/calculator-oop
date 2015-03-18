
#ifndef _BILANGAN_H_
#define _BILANGAN_H_

#include "Enum.h"
#include <iostream>
#include "Token.h"

class Bilangan: public Token{
	public:
		virtual long double GetValue() = 0;//deffered
	private:
};

#endif
