#include "Calculator.h"
#include "CalculatorException.h"
#include "PenghitungException.h"
#include "ParserException.h"
#include <string>
//ctor
Calculator::Calculator(){
	MemCalculator = new Memori();
}
//dtor
Calculator::~Calculator(){
	delete MemCalculator;
}
//tidak diperlukan cctor dan opr= karena tidak pernah ada passing calculator
//Setter
void Calculator::SetMode(EnumMathLogic E){
	mode_math_logic = E;
	PenghitungCalculator.SetMathLogic(E);
	delete MemCalculator;
	MemCalculator = new Memori();
}
void Calculator::SetSintaks(EnumSintaks S){
	mode_sintaks = S;
	PenghitungCalculator.SetSintaks(S);
	delete MemCalculator;
	MemCalculator = new Memori();
}
void Calculator::SetJenisAngka(EnumBilangan B){
	mode_bilangan = B;
	ParserCalculator.SetModeBilangan(B);
	delete MemCalculator;
	MemCalculator = new Memori();
}
//Eksekusi
void Calculator::Run(){
	//Default
	//Bilangan Arab
	mode_bilangan = arab;
	ParserCalculator.SetModeBilangan(arab);
	//Hitung matematika
	mode_math_logic = math;
	PenghitungCalculator.SetMathLogic(math);
	//Sintaks infix
	mode_sintaks = infix;
	PenghitungCalculator.SetSintaks(infix);

	string s;

	getline(cin, s);

	while (s!="exit") {	
		Expression e;

		try {
			
			e = ParserCalculator.Parse(s);
			
			if (e.GetLength() > 0)
			{
				Token* firstToken = e.GetToken(0);
			
				if (firstToken->GetType() == cmd) {
					try {
						JalankanPerintah(e);
					}
					catch (CalculatorException& e) {
						e.DisplayMsg();
					}
				}
				else {
					try {				
						double hasil = PenghitungCalculator.Calculate(e);
						Bilangan* hasilB;
						if (mode_bilangan == romawi)
							hasilB = new Romawi(hasil);
						else if (mode_bilangan == arab)
							hasilB = new Arab(hasil);
						cout << hasilB->Display() << endl;
						delete hasilB;

						MemCalculator->AddExpression(e);
					} catch (PenghitungException& e) {
						e.DisplayMsg();
					} catch (StackExp& e) {
						e.printMsg();
					}
				}
			}
		} catch (ParserException& e) {
			e.DisplayMsg();
		};
		
		getline(cin, s);
	}

}
void Calculator::JalankanPerintah(Expression& E){
	Token* Tperintah;
	string strToken;

	Tperintah = E.GetToken(0);
	EnumPerintah cmdToken = ((Perintah*) Tperintah)->GetJenisPerintah();
	switch (cmdToken){
		case 0 : 
			{
				if (E.GetLength()==2)
				{
					Token* TokenParam = E.GetToken(1);
					if (TokenParam->GetType() != bil) throw CalculatorException("[syntax error]");

					Bilangan* bilParam = (Bilangan*) TokenParam;
					int setParam = int(bilParam->GetValue());

					switch (setParam) 
					{
						case 0 : SetMode(math);break;
						case 1 : SetMode(logic);break;
						case 2 : SetJenisAngka(arab);break;
						case 3 : SetJenisAngka(romawi); break;
						case 4 : SetSintaks(prefix);break;
						case 5 : SetSintaks(infix);break;
						case 6 : SetSintaks(postfix);break;

					}
				}
				else
					throw CalculatorException("[syntax error]");
			}
			break;
		case 1 : 
			{
				int undoParam = 1;

				if (E.GetLength()==2)
				{
					Token* TokenParam = E.GetToken(1);
					if (TokenParam->GetType() != bil) throw CalculatorException("[syntax error]");

					Bilangan* bilParam = (Bilangan*) TokenParam;
					undoParam = int(bilParam->GetValue());
				}
				else if (E.GetLength() > 2)
					throw CalculatorException("[syntax error]");

				if (MemCalculator->Undo(undoParam)){
					std::cout << "[berhasil]\n";
				}else{
					std::cout << "[undo gagal]\n";
				}
			}
			break;
		case 2 :
			{
				int redoParam = 1;

				if (E.GetLength()==2)
				{
					Token* TokenParam = E.GetToken(1);
					if (TokenParam->GetType() != bil) throw CalculatorException("[syntax error]");

					Bilangan* bilParam = (Bilangan*) TokenParam;
					redoParam = int(bilParam->GetValue());
				}
				else if (E.GetLength() > 2)
					throw CalculatorException("[syntax error]");

				for (int i = 0; i < redoParam; ++i) {
					Expression ekspresi = MemCalculator->Redo();
					Token* tempT;

					int lenekspresi = ekspresi.GetLength();
					for (int j = 0; j < lenekspresi-1; ++j){
						tempT = ekspresi.GetToken(j);
						std::cout << tempT->Display() << " ";
					}

					tempT = ekspresi.GetToken(lenekspresi-1);
					std::cout << tempT->Display() << std::endl;

					try {				
						double hasil = PenghitungCalculator.Calculate(ekspresi);
						Bilangan* hasilB;
						if (mode_bilangan == romawi)
							hasilB = new Romawi(hasil);
						else if (mode_bilangan == arab)
							hasilB = new Arab(hasil);
						cout << hasilB->Display() << endl;

						delete hasilB;
					} catch (PenghitungException& thisexception) {
						thisexception.DisplayMsg();
					} catch (StackExp& thisexception) {
						thisexception.printMsg();
					}
				}
			}
			break;
		case 3 :
			{
				if (E.GetLength()==2)
				{
					Token* TokenParam = E.GetToken(1);
					if (TokenParam->GetType() != bil) throw CalculatorException("[syntax error]");

					Bilangan* bilParam = (Bilangan*) TokenParam;
					int showMemParam = int(bilParam->GetValue());

					MemCalculator->ShowMem(showMemParam);
				}
				else
					throw CalculatorException("[syntax error]");
			}
			break;
		case 4 :
			{
				MemCalculator->ShowAll();
			}
			break;
		case 5 :
			{
				MemCalculator->Save();
			}
			break;
	} 
}