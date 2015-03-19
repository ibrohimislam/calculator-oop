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
		//ctor default arab
		Parser() {ModeB = (EnumBilangan)0;}/*default constructor*/
		//dtor
		~Parser(){}
		//operator= dan dan cctor tidak diperlukan karena tidak akan ada inisialisasi objek parser ke parser lain
		void SetModeBilangan(EnumBilangan B);
		Expression Parse(const std::string& s);
	private:
		EnumBilangan ModeB;
};

#endif