#ifndef _PARSEREXCEPTION_H_
#define _PARSEREXCEPTION_H_

#include <string>

class ParserException
{
public:
	//ctor
	ParserException(){
		MsgParserExp = "";
	}
	ParserException(const std::string& s){
		MsgParserExp = s;
	}
	//dtor
	~ParserException(){}

	//tidak memerlukan opr= dan cctor
	void DisplayMsg(){
		std::cout << MsgParserExp<<std::endl;
	}
private:
	std::string MsgParserExp; 
};

#endif
