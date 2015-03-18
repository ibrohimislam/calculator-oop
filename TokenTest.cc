#include "Token.h"
#include "Arab.h"
#include "Romawi.h"
#include "Bilangan.h"
#include "Perintah.h"
#include "Operator.h"
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	string s1,s2,s3;
	//tes angka romawi
	cout << "Masukkan angka Romawi : "; cin >> s1;
	Romawi R1 = Romawi (s1);
	R1.Display();

	//tes angka arab
	cout << "Masukkan angka Arab : "; cin >> s1;
	Arab A1 = Arab (s1);
	A1.Display();

	//tes perintah
	cout << "Masukkan perintah : "; cin >> s2;
	Perintah P1 = Perintah (s2);
	P1.Display();

	//tes operator
	cout << "Masukkan operator : "; cin >> s3;
	Operator O1 = Operator (s3);
	O1.Display();

	return 0;
}
