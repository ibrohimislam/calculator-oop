#ifndef _PENGHITUNG_H_
#define _PENGHITUNG_H_

#include "Enum.h"
#include "Expression.h"


class Penghitung {
public:
	Penghitung();
	Penghitung(const Penghitung&);
	~Penghitung();
	// operator= tidak diperlukan karena tidak ada pointer
	// 

	long double Calculate(Expression E);
	void SetSintaks(EnumSintaks Mode);
	void SetMathLogic(EnumMathLogic Mode);
private:
	EnumSintaks ModeSintaks;
	ModeMathLogic ModeMathLogic;
};

#endif