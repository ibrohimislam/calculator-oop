#include "Parser.h"

using namespace std;

void Parser::SetModeBilangan(EnumBilangan B){
	ModeB = B;
}

Expression Parser::Parse(string s){
	string tempStr;
	Token* CurToken;
	
	int PanjangS = s.length();
	int i =0;

	char tempChar = s[0];
	while (i < PanjangS && tempChar != '\0' ){
		while (tempChar != ' '){
			tempStr[i] = s[i];
			tempChar =s[i];
			++i;
		}

		//Keluar loop bila menemukan spasi
		int banyak_perintah = sizeof(Perintah::KarakterPerintah)/sizeof(string);
		int banyak_operator = sizeof(Operator::KarakterOperator)/sizeof(string);
		bool ditemukan = false;
		//Cari apakah tempString merupakan perintah. Bila iya maka construct Perintah
		for (int i = 0; (i < banyak_perintah) && (!ditemukan); ++i){		
			if (tempStr == KarakterPerintah[i]){
				CurToken = new Perintah(tempStr);
				ditemukan = true;
			}
		}

		//tempString bukan perintah. Bila operator construct Operator
		for (int i = 0; (i < banyak_operator) && (!ditemukan); ++i){
			if (_s == KarakterOperator[i]){
				CurToken = new Operator(tempStr);
				ditemukan = true;
			}		
		}
		//Bila bukan operator maupun perintah maka bentuk bilangan
		if (ditemukan == false){
			if (ModeB == 0){
				CurToken = new Arab(tempStr);
			}else{
				CurToken = new Romawi(tempStr);
			}
		}
	}
	//Keluar loop bila i >= dari PanjangS atau menemukan char '\0'
}

