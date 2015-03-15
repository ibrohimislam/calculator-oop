#include "EnumToken.h"
#include <iostream>
#include "Token.h"
#include "Bilangan.h"

long double Bilangan :: Display (EnumBilangan T){
	if (T == arab){
		cout << GetValue();
	}else if (T == romawi){
		if (GetValue() == 4){
			cout << "IV";
		}  else if (GetValue() == 9){
			cout << "IX";
		}  else if (GetValue() == 40){
			cout << "IX";
		}  else if (GetValue() == 90){
			cout << "IX";
		}  else if (GetValue() == 400){
			cout << "IX";
		}  else if (GetValue() == 900){
			cout << "IX";
		}  else if (GetValue() == 4000){
			cout << "IX";
		}  else if (GetValue() == 9000){
			cout << "IX";
		}  else if (GetValue() == 40000){
			cout << "IX";
		}  else if (GetValue() == 90000){
			cout << "IX";
		}   else if (GetValue() == 40000){
			cout << "IX";
		} 
	}
}
