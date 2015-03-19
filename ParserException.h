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
	//ctor
	ParserException(){
		MsgParserExp = "";
	} /*default construtcor*/
	ParserException(const std::string& s){
		MsgParserExp = s;
	}/*constructor with parameter string*/
	//dtor
	~ParserException(){}

	//tidak memerlukan opr= dan cctor karena tidak pernah dilakukan instansiasi nilai
	void DisplayMsg(){
		std::cout << MsgParserExp<<std::endl;
	}
private:
	std::string MsgParserExp; 
};

#endif
