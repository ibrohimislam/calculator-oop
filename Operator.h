#ifndef _OPERATOR_H_
#define _OPERATOR_H_

#include "Token.h"
#include <iostream>
#include <assert.h>
#include <string>
/**
 * Class Operator
 *
 * Kelas yang digunakan untuk merepresentasikan token operator
 * 
 * @class     Operator Operator.h "Operator.h"
 * @package   Parser
 * @brief     Kelas yang digunakan untuk merepresentasikan token operator
 * @author    Satria Priambada
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */
class Operator : public Token {
	public:
		//ctor
		Operator() {}/*default constructor*/
		Operator(std::string _s);/*consturctor with parameter string*/
		//dtor
		~Operator(){}
		//cctor dan operator= tidak dibutuhkan karena tidak akan dilakukan assignment antar operator
		EnumOperator GetJenisOperator();
		std::string Display();
		EnumType GetType();
		static std::string KarakterOperator[];
		static int BanyakOperator;
	private:
		EnumOperator JenisOperator;
};

#endif