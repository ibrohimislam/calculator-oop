#ifndef _PARSEREXCEPTION_H_
#define _PARSEREXCEPTION_H_

#include <string>

/**
 * Class ParserException
 * 
 * Kelas yang digunakan untuk melakukan proses pembuatan execption dari parser
 * 
 * @class     ParserException ParserException.h "ParserException.h"
 * @package   Parser
 * @brief     Kelas yang digunakan untuk melakukan proses pembuatan execption dari parser
 * @author    Satria Priambada
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */

class ParserException
{
public:
	/**
	 * Konstruktor default
	 * 
	 * Konstruktor tanpa parameter yang menginisiasi
	 * nilai pesan kesalahan dengan string kosong
	 * 
	 * @param none
	 */
	 
	ParserException(){
		MsgParserExp = "";
	} /*default constructor*/
	
	/**
	 * Konstruktor dengan parameter string
	 * 
	 * Konstruktor dengan parameter string yang menginisiasi
	 * nilai pesan kesalahan dengan string masukan
	 * 
	 * @param string
	 */
	 
	ParserException(const std::string& s){
		MsgParserExp = s;
	} /*constructor with parameter string*/
	
	/**
	 * Destruktor 
	 */
	 
	~ParserException(){}

	/* tidak memerlukan opr= dan cctor karena tidak pernah dilakukan instansiasi nilai */
	
	/**
	 * Prosedur DisplayMsg
	 * 
	 * Mencetak pesan kesalahan dari exception yang dilempar
	 * 
	 * @param none
	 * @return none
	 */
	 
	void DisplayMsg(){
		std::cout << MsgParserExp<<std::endl;
	}
	
private:
	std::string MsgParserExp; 
};

#endif
