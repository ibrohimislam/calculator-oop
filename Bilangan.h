#ifndef _BILANGAN_H_
#define _BILANGAN_H_

#include "Enum.h"
#include <iostream>
#include "Token.h"

/**
 * Class Bilangan
 * 
 * Kelas Abstrak yang digunakan untuk merepresentasikan bilangan
 * 
 * @class     Bilangan Bilangan.h "Bilangan.h"
 * @package   Parser
 * @brief     Kelas Abstrak yang digunakan untuk merepresentasikan bilangan
 * @author    Satria Priambada
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */

class Bilangan: public Token {
	public:
		/**
		 * Fungsi Display
		 *
		 * Fungsi untuk mendapatkan string Bilangan Arab untuk ditulis
		 *
		 * @param none
		 * @return std::string
		 */

		virtual std::string Display() = 0;

		/**
		 * Fungsi GetType
		 *
		 * Fungsi untuk tipe polimorf token
		 *
		 * @param none
		 * @return EnumType
		 */
		EnumType GetType();

		/**
		 * Fungsi GetValue
		 *
		 * Fungsi untuk mendapatkan nilai dari Bilangan Arab
		 *
		 * @param none
		 * @return double
		 */
		virtual double GetValue() = 0; //deffered
	private:
};

#endif
