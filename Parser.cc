#include "Parser.h"
#include "Perintah.h"
#include "Operator.h"
#include "Bilangan.h"
#include "Arab.h"
#include "Romawi.h"
#include "Token.h"
#include "Expression.h"

using namespace std;

void Parser::SetModeBilangan(EnumBilangan B){
	ModeB = B;
}

Expression& Parser::Parse(const std::string& s){
	string tempStr;
	Expression tempExpression;
	Token* CurToken = NULL;
	
	int PanjangS = s.length();
	int i =0;

	char tempChar = s[0];
	while (i < PanjangS && tempChar != '\0' ){
		int j=0;
		
		while (tempChar == ' ')
			tempChar=s[++i];

		while (tempChar != ' '){
			tempStr[j++] = s[i];
			i=i+1;
			tempChar=s[i];
		}

		i=i+1;

		//Keluar loop bila menemukan spasi
		int banyak_perintah = Perintah::BanyakPerintah;
		int banyak_operator = Operator::BanyakOperator;

		bool ditemukan = false;
		//Cari apakah tempString merupakan perintah. Bila iya maka construct Perintah
		for (int i = 0; (i < banyak_perintah) && (!ditemukan); ++i){		
			if (tempStr == Perintah::KarakterPerintah[i]){
				CurToken = new Perintah(tempStr);
				ditemukan = true;
			}
		}

		//tempString bukan perintah. Bila operator construct Operator
		for (int i = 0; (i < banyak_operator) && (!ditemukan); ++i){
			if (tempStr == Operator::KarakterOperator[i]){
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
	}
	//Keluar loop bila i >= dari PanjangS atau menemukan char '\0'
	return tempExpression;
}

