
#ifndef _ROMAWI_H_
#define _ROMAWI_H_
#include "Token.h"
#include "Bilangan.h"
#include <string>
#include <cstring>

class Romawi: public Bilangan{
	public:
		//ctor
		Romawi();
		Romawi(const std::string s);
		//dtor
		~Romawi(){}
		//cctor dan operator= tidak pernah dipakai karena tidak mungkin instansiasi
		long double GetValue();

		void Display();
	private:
		int Value;
};

#endif
