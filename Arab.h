#ifndef _ARAB_H_
#define _ARAB_H_

#include "Token.h"
#include "Bilangan.h"
#include <string.h>
#include "BilanganException.h"
#include <stdio.h>
#include <string>
#include <sstream>


/**
 * Class Arab
 *
 * Kelas yang digunakan untuk merepresentasikan bilangan arab
 * 
 * cctor dan operator= tidak pernah dipakai
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
		/**
		 * Constructor default
		 *
		 * Konstruktor yang digunakan untuk membuat Objek arab dengan nilai 0
		 *
		 */

		Arab(); /* default constructor */
		
		/**
		 * Constructor with parameter double
		 *
		 * Konstruktor yang digunakan untuk membuat Objek arab dengan nilai 
		 * double yang diberikan
		 *
		 * @param d double
		 * @pre d terdefinisi
		 */

		Arab(const double d);

		/**
		 * Constructor with parameter string
		 *
		 * Konstruktor yang digunakan untuk membuat Objek arab dari nilai 
		 * string yang diberikan
		 *
		 * @param s string
		 * @pre s terdefinisi
		 */

		Arab(const std::string& s); /* constructor with parameter string */

		/**
		 * Destructor
		 *
		 * @param none
		 */

		~Arab(){}
		
		/**
		 * Fungsi GetValue
		 *
		 * Fungsi untuk mendapatkan nilai dari Bilangan Arab
		 *
		 * @param none
		 * @return double
		 */

		double GetValue();

		/**
		 * Fungsi Display
		 *
		 * Fungsi untuk mendapatkan string untuk ditampilkan
		 *
		 * @param none
		 * @return string
		 */
		std::string Display();

	private:
		double Value;
};

#endif
