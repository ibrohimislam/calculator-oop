#include "Token.h"
#include "Arab.h"
#include "Romawi.h"
#include "Bilangan.h"
#include "Perintah.h"
#include "Operator.h"
#include "Parser.h"
#include "Expression.h"
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	string s1,s2,s3;
	Parser P1;
	Expression E1;
	Token* T1;
	//tes string
	cout << "Masukkan string : "; getline(std::cin, s1);
	
	E1 = P1.Parse(s1);

	cout << "Parse Selesai" << std::endl;
	int LengthExpr = E1.GetLength();

	for (int i = 0; i < LengthExpr; ++i)
	{
		T1 = E1.GetToken(i);
		std::cout << T1->Display();
	}

	std::cout << std::endl;

	return 0;
}
