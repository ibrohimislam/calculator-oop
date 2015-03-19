#ifndef _PERINTAH_H_
#define _PERINTAH_H_

#include "Token.h"
#include <iostream>
#include <assert.h>
#include <string>
/**
 * Class Perintah
 * 
 * @class     Perintah Perintah.h "Perintah.h"
 * @package   Parser
 * @brief     Kelas yang digunakan untuk merepresentasikan token perintah
 * @author    Satria Priambada
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */

class Perintah : public Token{
	public:
		//ctor
		Perintah(){}/*default constructor*/
		Perintah(std::string _s);/*constructor with parameter string*/
		//dtor
		~Perintah(){}
		//cctor dan operator= tidak dibutuhkan karena tidak akan dilakukan assignment antar operator
		EnumPerintah GetJenisPerintah();
		std::string Display();
		EnumType GetType();
		static std::string KarakterPerintah[];
		static int BanyakPerintah;
	private:
		EnumPerintah JenisPerintah;
};

#endif