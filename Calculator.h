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
	/**
	 * Constructor default
	 *
	 * Konstruktor yang digunakan untuk membuat Objek calculator dengan mode default
	 *
	 * @param none
	 * @return double
	 */

	Calculator();

	/**
	 * Destructor
	 *
	 * @param none
	 */

	~Calculator();
	//tidak diperlukan cctor dan opr= karena tidak pernah ada passing calculator
	//Setter

	/**
	 * Prosedur SetMode
	 *
	 * Prosedur yang digunakan untuk mengubah Mode Math dan Logic
	 *
	 * @param E EnumMathLogic
	 */

	void SetMode(EnumMathLogic E);

	/**
	 * Prosedur SetSintaks
	 *
	 * Prosedur yang digunakan untuk mengubah Mode Sintaks
	 *
	 * @param S EnumSintaks
	 */

	void SetSintaks(EnumSintaks S);

	/**
	 * Prosedur SetJenisAngka
	 *
	 * Prosedur yang digunakan untuk mengubah Mode Jenis Angka
	 *
	 * @param B EnumBilangan
	 */
	void SetJenisAngka(EnumBilangan B);
	//Eksekusi

	/**
	 * Prosedur Run
	 *
	 * Prosedur yang melakukan rutin input-proses-output
	 *
	 * @param none
	 */

	void Run();

	/**
	 * Prosedur JalankanPerintah
	 *
	 * Prosedur yang melakukan expresi perintah
	 *
	 * @param E Expression
	 */
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