#include "Token.h"
#include "Bilangan.h"
#include "Arab.h"
#include <iostream>

void Arab:: Display(){
	std::cout << Value;
}

Arab:: Arab(){
	Value = 0;
}

Arab:: Arab(const std::string& s) {
	long double tval = 0.0;
	int len = s.length();
	int temp = 1;
	
	for (int i=len; i>=0; i--) {
		if (s[i]=='.')
		{
			tval=tval/temp;
		}
		else
		{
			tval = tval + (s[i] - '0')*temp;
			temp = temp*10;
		}
	}

	Value = tval;
}

long double Arab:: GetValue(){
	return Value;
}
