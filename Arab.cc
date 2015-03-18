#include "Token.h"
#include "Bilangan.h"
#include "Arab.h"

EnumType Arab:: GetType(){
	return Bilangan;
}
void Arab:: Display(){
	cout << Value;
}

Arab:: Arab(){
	Value = 0;
}

Arab:: Arab(string s) {
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
