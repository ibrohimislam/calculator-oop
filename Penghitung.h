#ifndef _PENGHITUNG_H_
#define _PENGHITUNG_H_

#include "Arab.h"
#include "Enum.h"
#include "Expression.h"
#include "Operator.h"
#include "STL/stack.h"

class Penghitung {
public:
	Penghitung();
	Penghitung(const Penghitung&);
	~Penghitung();
	// operator= tidak diperlukan karena tidak ada pointer

	double Calculate(Expression E);
	void SetSintaks(EnumSintaks Mode);
	void SetMathLogic(EnumMathLogic Mode);
	double CalculatePostfix(Expression& E);
	void ParseInfix(Expression& E);
	double CalculateAtom(double a, double b, Operator o);

private:
	EnumSintaks ModeSintaks;
	EnumMathLogic ModeMathLogic;
};

#endif