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
		/**
		 * Constructor default
		 *
		 * Konstruktor yang digunakan untuk membuat Objek Operator
		 *
		 */

		Operator() {}/*default constructor*/

		/**
		 * Constructor with parameter string
		 *
		 * Konstruktor yang digunakan untuk membuat Objek operator dari nilai 
		 * string yang diberikan
		 *
		 * @param s string
		 * @pre s terdefinisi
		 */

		Operator(std::string _s);/*consturctor with parameter string*/
		
		/**
		 * Destructor
		 *
		 * @param none
		 */
		~Operator(){}
		
		//cctor dan operator= tidak dibutuhkan karena tidak akan dilakukan assignment antar operator
		
		/**
		 * Fungsi GetJenisOperator
		 * 
		 * @param none
		 * return  EnumOperator
		 */
		EnumOperator GetJenisOperator();

		/**
		 * Fungsi Display
		 *
		 * Fungsi untuk mendapatkan string untuk ditampilkan
		 *
		 * @param none
		 * @return string
		 */

		std::string Display();
		
		/**
		 * Fungsi GetType
		 *
		 * Fungsi untuk tipe polimorf token
		 *
		 * @param none
		 * @return EnumType
		 */
		EnumType GetType();
		
		static std::string KarakterOperator[];
		static int BanyakOperator;
	private:
		EnumOperator JenisOperator;
};

#endif