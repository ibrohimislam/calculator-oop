#include "Token.h"
#include "Bilangan.h"
#include "Arab.h"
#include "BilanganException.h"
#include <stdio.h>

void Arab:: Display(){
	printf("%lf", Value);
}

Arab:: Arab(){
	Value = 0;
}

Arab:: Arab(const std::string& s) {
	std::cout << "\"" << s << "\""<< std::endl;

	int val = 0;
	int frac = 0;

	int len = s.length();

	int i;

	for (i = 0; (i < len) && (s[i] != '.'); ++i)
	{
		if (s[i]>='0' && s[i]<='9')
			val = val*10 + (s[i] - '0');
		else
			throw BilanganException("Bilangan tidak dikenali.");
	}

	for (int j = i+1; j<len; j++)
	{
		if (s[i]>='0' && s[i]<='9')
			frac = frac*10 + (s[j] - '0');
		else
			throw BilanganException("Bilangan tidak dikenali.");
	}

	int pembagi=1;

	for (int i = 0; i < (len-i-2); ++i)
		pembagi = pembagi*10;

	if (i<len-1)
		Value = double(val)+(double(frac)/double(pembagi));
	else
		Value = double(val);
}

double Arab:: GetValue(){
	return Value;
}