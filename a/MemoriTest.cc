#include "Token.h"
#include "Arab.h"
#include "Romawi.h"
#include "Bilangan.h"
#include "Perintah.h"
#include "Operator.h"
#include "Parser.h"
#include "Expression.h"
#include "Memori.h"
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	string s1;
	Parser P1;
	Expression E1,E2;
	Token* T1;
	Memori M1;
	//tes string
	std::cout << "Masukkan string : "; getline(std::cin, s1);
	
	E1 = P1.Parse(s1);
	//tes add memori
	cout << "Parse Selesai" << std::endl;
	
	M1.AddExpression(E1);
	int LengthExpr = E1.GetLength();

	for (int i = 0; i < LengthExpr; ++i)
	{
		T1 = E1.GetToken(i);
		std::cout << T1->Display();
	}
	//tes undo
	if (M1.Undo(1)){
		cout << "Undo berhasil\n";
	} else {
		cout << "Undo gagal\n";
	}
	//tes redo
	E1 = M1.Redo();
	cout << "berhasil redo\n";
	LengthExpr = E1.GetLength();
	//print hasil redo
	for (int i = 0; i < LengthExpr; ++i)
	{
		T1 = E1.GetToken(i);
		std::cout << T1->Display();
	}
	//tes input kedua
	//tes string
	cout << "Masukkan string : "; getline(std::cin, s1);
	
	E2 = P1.Parse(s1);
	//tes add memori
	M1.AddExpression(E2);
	cout << "Parse Selesai" << std::endl;
	//tes show memori
	M1.ShowAll();
	M1.ShowMem(1);
	//tes save
	M1.Save();
	//undo untuk tes delete
	if (M1.Undo(1)){
		cout << "Undo berhasil\n";
	} else {
		cout << "Undo gagal\n";
	}
	cout << "Masukkan string terakhir untuk menimpa : "; getline(std::cin, s1);
	
	E2 = P1.Parse(s1);
	//tes add memori
	M1.AddExpression(E2);
	M1.ShowAll();
	M1.Save();

	std::cout << std::endl;

	return 0;
}