#include "Token.h"
#include "Operator.h"
#include <iostream>
#include <assert.h>

std::string Operator::KarakterOperator[] = {"+", "-", "/", "*", "Div", "Mod", "&&", "||", "!", "^", "(", ")"};

Operator::Operator(std::string _s) {
	int banyak_operator = sizeof(KarakterOperator)/sizeof(std::string);
	
	bool ditemukan = false;

	for (int i = 0; (i < banyak_operator) && (!ditemukan); ++i)
		if (_s == KarakterOperator[i]){
			JenisOperator = (EnumOperator)i;
			ditemukan = true;
		}

	assert(ditemukan);
}

EnumType Operator::GetType(){
	return opr;
}

void Operator::Display(){
	std::cout << Operator::KarakterOperator[JenisOperator];
}

EnumOperator Operator:: GetJenisOperator(){
	return JenisOperator;
}