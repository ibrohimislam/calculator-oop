#ifndef _CALCULATOREXCEPTION_H_
#define _CALCULATOREXCEPTION_H_

#include <string>

class CalculatorException
{
public:
	//ctor
	CalculatorException(){
		MsgCalculatorExp = "";
	}
	CalculatorException(const std::string& s){
		MsgCalculatorExp = s;
	}
	//dtor
	~CalculatorException(){}

	//tidak memerlukan opr= dan cctor
	void DisplayMsg(){
		std::cout << MsgCalculatorExp<<std::endl;
	}
private:
	std::string MsgCalculatorExp; 
};

#endif
