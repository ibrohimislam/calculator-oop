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


/**
 * Class Arab
 * 
 * @class     Arab Arab.h "Arab.h"
 * @package   Parser
 * @brief     Kelas yang digunakan untuk merepresentasikan bilangan arab
 * @author    Satria Priambada
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */

class Arab: public Bilangan{
	public:
		//ctor
		Arab(); /* default constructor */
		Arab(const double d); /* constructor with parameter double */
		Arab(const std::string& s); /* constructor with parameter string */
		//dtor
		~Arab(){}
		//cctor dan operator= tidak pernah dipakai karena tidak mungkin instansiasi
		double GetValue();
		std::string Display();

	private:
		double Value;
};

#endif
