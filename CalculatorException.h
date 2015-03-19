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
	/**
	 * Constructor default
	 *
	 * Konstruktor yang digunakan untuk membuat Objek exception dengan pesan kosong
	 *
	 */
	CalculatorException(){
		MsgCalculatorExp = "";
	}

	/**
	 * Constructor default
	 *
	 * Konstruktor yang digunakan untuk membuat Objek exception dengan pesan s
	 *
	 * @param s std::string
	 *
	 */
	CalculatorException(const std::string& s){
		MsgCalculatorExp = s;
	}
	
	/**
	 * Destructor
	 *
	 * @param none
	 */
	~CalculatorException(){}

	/**
	 * Prosedur DisplayMsg
	 *
	 * Prosedur yang digunakan untuk menampilkan pesan kesalahan
	 *
	 * @param none
	 *
	 */
	void DisplayMsg(){
		std::cout << MsgCalculatorExp<<std::endl;
	}
private:
	std::string MsgCalculatorExp; 
};

#endif
