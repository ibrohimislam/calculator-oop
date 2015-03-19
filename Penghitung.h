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

	double Calculate(Expression);
	void SetSintaks(EnumSintaks);
	void SetMathLogic(EnumMathLogic);
	double CalculatePostfix(Expression&);
	void ParseInfix(Expression&);
	void ParsePrefix(Expression&);
	double CalculateAtom(double, double, Operator*);

private:
	EnumSintaks ModeSintaks;
	EnumMathLogic ModeMathLogic;
};

#endif