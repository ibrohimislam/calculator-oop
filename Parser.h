#ifndef _PARSER_H_
#define _PARSER_H_


#include "Perintah.h"
#include "Operator.h"
#include "Bilangan.h"
#include "Arab.h"
#include "Romawi.h"
#include "Expression.h"
#include "BilanganException.h"
#include "STL/vector.h"
#include "Expression.h"
#include "Token.h"
#include "Enum.h"
#include <string>

using namespace std;

/**
 * Class Parser
 *
 * Kelas yang digunakan untuk melakukan proses parsing string
 * 
 * @class     Parser parser.h "parser.h"
 * @package   Parser
 * @brief     Kelas yang digunakan untuk melakukan proses parsing string
 * @author    Satria Priambada
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */
class Parser{
	public:
		/**
		 * Constructor default
		 *
		 * Konstruktor yang digunakan untuk membuat Objek Operator
		 *
		 */

		Parser() {ModeB = (EnumBilangan)0;}/*default constructor*/
		
		/**
		 * Destructor
		 *
		 * @param none
		 */

		~Parser(){}
		//operator= dan dan cctor tidak diperlukan karena tidak akan ada inisialisasi objek parser ke parser lain
		
		/**
		 * Prosedur SetModeBilangan
		 *
		 * Prosedur yang digunakan untuk mengubah Mode Bilangan
		 *
		 * @param B EnumBilangan
		 */
		void SetModeBilangan(EnumBilangan B);

		/**
		 * Fungsi Parse
		 *
		 * Fungsi yang digunakan untuk parsing string
		 *
		 * @param s std::string
		 */
		Expression Parse(const std::string& s);
	private:
		EnumBilangan ModeB;
};

#endif