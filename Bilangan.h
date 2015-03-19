#ifndef _BILANGAN_H_
#define _BILANGAN_H_

#include "Enum.h"
#include <iostream>
#include "Token.h"

/**
 * Class Bilangan
 * 
 * @class     Bilangan bilangan.h "bilangan.h"
 * @package   Token
 * @brief     Kelas Abstrak yang digunakan untuk merepresentasikan bilangan
 * @author    Satria Priambada
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */

class Bilangan: public Token{
	public:
		virtual std::string Display() = 0;
		EnumType GetType();
		virtual double GetValue() = 0; //deffered
	private:
};

#endif
