#ifndef _PENGHITUNG_H_
#define _PENGHITUNG_H_

#include "Arab.h"
#include "Enum.h"
#include "Expression.h"
#include "Operator.h"
#include "STL/stack.h"

/**
 * Class Penghitung
 * 
 * @class     Penghitung Penghitung.h "Penghitung.h"
 * @package   Menghitung
 * @brief     Kelas yang digunakan untuk melakukan proses menghitung token
 * @author    Afrizal Fikri
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */

class Penghitung {
public:
	//ctor
	Penghitung();/*default constructor*/
	Penghitung(const Penghitung&);/*cctor*/
	//dtor
	~Penghitung();
	// operator= tidak diperlukan karena tidak ada pointer

	double Calculate(Expression E);
	void SetSintaks(EnumSintaks Mode);
	void SetMathLogic(EnumMathLogic Mode);
	double CalculatePostfix(Expression& E);
	void ParseInfix(Expression& E);
	double CalculateAtom(double a, double b, Operator* o);

private:
	EnumSintaks ModeSintaks;
	EnumMathLogic ModeMathLogic;
};

#endif