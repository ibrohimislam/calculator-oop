#include "Parser.h"
#include "ParserException.h"

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
		int j=0;
		
		while ((tempChar == ' ') && (i < PanjangS))
			tempChar=s[++i];

		while ((tempChar != ' ') && (i < PanjangS)){
			tempCStr[j++] = s[i];
			i=i+1;
			tempChar=s[i];
		}
		tempCStr[j] = 0;

		std::string tempStr = tempCStr;

		//Keluar loop bila menemukan spasi
		int banyak_perintah = Perintah::BanyakPerintah;
		int banyak_operator = Operator::BanyakOperator;

		bool ditemukan = false;
		//Cari apakah tempString merupakan perintah. Bila iya maka construct Perintah
		for (int k = 0; (k < banyak_perintah) && (!ditemukan); ++k){		
			if (tempStr == Perintah::KarakterPerintah[k]){
				CurToken = new Perintah(tempStr);
				ditemukan = true;
			}
		}

		std::string SpecialEnum[] = {"math", "logic", "arab", "romawi", "prefix", "infix", "postfix"};
		int banyak_special_enum = sizeof(SpecialEnum)/sizeof(std::string);

		for (int k = 0; (k < banyak_special_enum) && (!ditemukan); ++k){		
			if (tempStr == SpecialEnum[k]){
				CurToken = new Arab(k);
				ditemukan = true;
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
			// chained exception
			throw ParserException("Terdapat kesalahan pada ekspresi.");
		}

		if (CurToken!=NULL)
			tempExpression.AddToken(CurToken);
	}
	//Keluar loop bila i >= dari PanjangS atau menemukan char '\0'
	return tempExpression;
}

