
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
		Romawi(const std::string& s);
		//dtor
		~Romawi(){}
		//cctor dan operator= tidak pernah dipakai karena tidak mungkin instansiasi
		double GetValue();
		std::string Display();
	private:
		int Value;
};

#endif
