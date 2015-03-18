#ifndef _OPERATOR_H_
#define _OPERATOR_H_

#include "Token.h"
#include <string>

class Operator : public Token {
	public:
		//ctor
		Operator() {}
		Operator(std::string _s);
		//dtor
		~Operator(){}
		//cctor dan operator= tidak dibutuhkan karena tidak akan dilakukan assignment antar operator
		EnumOperator GetJenisOperator();
		void Display();
		EnumType GetType();
		static std::string KarakterOperator[];
		static int BanyakOperator;
	private:
		EnumOperator JenisOperator;
};

#endif