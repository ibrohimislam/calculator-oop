#ifndef _ROMAWI_H_
#define _ROMAWI_H_


#include <iostream>
#include <cstdlib>
#include <cassert>
#include "Token.h"
#include "Bilangan.h"
#include "BilanganException.h"
#include <string>
#include <cstring>

/**
 * Class Romawi
 *
 * Kelas yang digunakan untuk merepresentasikan bilangan romawi
 * 
 * @class     Romawi Romawi.h "Romawi.h"
 * @package   Parser
 * @brief     Kelas yang digunakan untuk merepresentasikan bilangan romawi
 * @author    Satria Priambada
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */
class Romawi: public Bilangan{
	public:
		//ctor
		Romawi();/*default constructor*/
		Romawi(const double d);/* constructor with parameter double */
		Romawi(const std::string& s);/* constructor with parameter string */
		//dtor
		~Romawi(){}
		//cctor dan operator= tidak pernah dipakai karena tidak mungkin instansiasi
		double GetValue();
		std::string Display();
	private:
		int Value;
};

#endif
