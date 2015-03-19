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