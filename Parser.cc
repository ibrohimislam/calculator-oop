#include "Parser.h"

using namespace std;

void Parser::SetModeBilangan(EnumBilangan B){
	ModeB = B;
}

Expression Parser::Parse(const std::string& s){
	char tempCStr[256];
	Expression tempExpression;
	Token* CurToken = NULL;
	
	int PanjangS = s.length();
	int i =0;

	char tempChar = s[0];
	while (i < PanjangS){

		std::cout << "sebelum: " << i << " " << PanjangS << std::endl;

		int j=0;
		
		while ((tempChar == ' ') && (i < PanjangS))
			tempChar=s[++i];

		while ((tempChar != ' ') && (i < PanjangS)){
			tempCStr[j++] = s[i];
			i=i+1;
			tempChar=s[i];
		}
		tempCStr[j] = 0;

		std::cout << "sesudah: " << i << " " << PanjangS << std::endl;

		std::string tempStr = tempCStr;

		std::cout << "token: \"" << tempStr << "\"" << std::endl;

		//Keluar loop bila menemukan spasi
		int banyak_perintah = Perintah::BanyakPerintah;
		int banyak_operator = Operator::BanyakOperator;

		bool ditemukan = false;
		//Cari apakah tempString merupakan perintah. Bila iya maka construct Perintah
		for (int k = 0; (k < banyak_perintah) && (!ditemukan); ++k){		
			if (tempStr == Perintah::KarakterPerintah[k]){
				CurToken = new Perintah(tempStr);
				ditemukan = true;
				cout << "cekperintah";
			}
		}

		//tempString bukan perintah. Bila operator construct Operator
		for (int k = 0; (k < banyak_operator) && (!ditemukan); ++k){
			if (tempStr == Operator::KarakterOperator[k]){
				CurToken = new Operator(tempStr);
				ditemukan = true;
			}		
		}

		try
		{
			//Bila bukan operator maupun perintah maka bentuk bilangan
			if (ditemukan == false){
				if (ModeB == 0){
					CurToken = new Arab(tempStr);
				}else{
					CurToken = new Romawi(tempStr);
				}
			}
		}
		catch (BilanganException& E)
		{
			E.DisplayMsg();
		}

		if (CurToken!=NULL)
			tempExpression.AddToken(CurToken);

		std::cout << "akhir: " << i << " " << PanjangS << std::endl;
	}
	//Keluar loop bila i >= dari PanjangS atau menemukan char '\0'
	return tempExpression;
}

