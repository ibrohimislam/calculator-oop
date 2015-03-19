#ifndef _CALCULATOREXCEPTION_H_
#define _CALCULATOREXCEPTION_H_

#include <string>

/**
 * Class CalculatorException
 * 
 * @class     CalculatorException CalculatorException.h "CalculatorException.h"
 * @package   Parser
 * @brief     Kelas exception spesifik class Calculator
 * @author    Satria Priambada
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */

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
