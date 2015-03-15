#include "Token.h"
#include "Bilangan.h"
#include "Arab.h"

EnumType Arab:: GetType(){
	return Bilangan;
}
Arab:: Display(){
	cout << Value;
}
Arab:: Display(EnumBilangan T){
	
	cout << Value;
}
Arab:: Arab(){
	Value = 0;
}

Arab:: Arab(string s){
	sprintf("%lf", s.c_str(), &Value);
}

long double Arab:: GetValue(){
	return Value;
}
