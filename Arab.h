#ifndef _ARAB_H_
#define _ARAB_H_

#include "Token.h"
#include "Bilangan.h"
#include <string.h>
#include "Token.h"
#include "Bilangan.h"
#include "BilanganException.h"
#include <stdio.h>
#include <string>
#include <sstream>

class Arab: public Bilangan{
	public:
		//ctor
		Arab();
		Arab(const std::string& s);
		//dtor
		~Arab(){}
		//cctor dan operator= tidak pernah dipakai karena tidak mungkin instansiasi
		double GetValue();
		std::string Display();

	private:
		double Value;
};

#endif
