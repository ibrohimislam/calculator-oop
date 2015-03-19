#include "Operator.h"

std::string Operator::KarakterOperator[] = {"+", "-", "/", "*", "Div", "Mod", "&&", "||", "!", "^", "(", ")"};
int Operator::BanyakOperator = 12;

Operator::Operator(std::string _s) {
	bool ditemukan = false;

	for (int i = 0; (i < BanyakOperator) && (!ditemukan); ++i)
		if (_s == KarakterOperator[i]) {
			JenisOperator = (EnumOperator)i;
			ditemukan = true;
		}

	assert(ditemukan);
}

EnumType Operator::GetType(){
	return opr;
}

std::string Operator::Display(){
	return KarakterOperator[JenisOperator];
}

EnumOperator Operator::GetJenisOperator(){
	return (EnumOperator)JenisOperator;
}