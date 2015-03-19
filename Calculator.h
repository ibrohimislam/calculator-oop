#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include "Penghitung.h"
#include "Parser.h"
#include "Memori.h"

/**
 * Class Calculator
 * 
 * Kelas utama kalkulator yang melakukan loop input-proses-output
 * 
 * @class     Calculator Calculator.h "Calculator.h"
 * @package   Parser
 * @brief     Kelas utama kalkulator yang melakukan loop input-proses-output
 * @author    Satria Priambada
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */

class Calculator {
public:
	//ctor
	Calculator();
	//dtor
	~Calculator();
	//tidak diperlukan cctor dan opr= karena tidak pernah ada passing calculator
	//Setter
	void SetMode(EnumMathLogic E);
	void SetSintaks(EnumSintaks S);
	void SetJenisAngka(EnumBilangan B);
	//Eksekusi
	void Run();
	void JalankanPerintah(Expression& E);


private:
	EnumSintaks mode_sintaks;
	EnumMathLogic mode_math_logic;
	EnumBilangan mode_bilangan;
	Memori* MemCalculator;
	Penghitung PenghitungCalculator;
	Parser ParserCalculator;
};

#endif