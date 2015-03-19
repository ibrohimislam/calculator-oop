#include "Calculator.h"
#include "CalculatorException.h"
#include "PenghitungException.h"
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

	while (1) {
		
		getline(cin, s);

		Expression e = ParserCalculator.Parse(s);
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
				cout << "MAIN:: len" << e.GetLength() << endl;
				cout << PenghitungCalculator.Calculate( e )<< endl;
				MemCalculator->AddExpression(e);
			} catch (PenghitungException& e) {
				e.DisplayMsg();
			} catch (StackExp& e) {
				e.printMsg();
			}
		}

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
			break;
		case 1 : 
			{
				Token* TokenParam = E.GetToken(1);
				if (TokenParam->GetType() != bil) throw CalculatorException("[syntax error]");

				Bilangan* bilParam = (Bilangan*) TokenParam;
				int undoParam = int(bilParam->GetValue());

				if (MemCalculator->Undo(undoParam)){
					std::cout << "[berhasil]\n";
				}else{
					std::cout << "[syntax error]\n";
				}
			}
			break;
		case 2 :
			{
				Token* TokenParam = E.GetToken(1);
				if (TokenParam->GetType() != bil) throw CalculatorException("[syntax error]");

				Bilangan* bilParam = (Bilangan*) TokenParam;
				int redoParam = int(bilParam->GetValue());

				for (int i = 0; i < redoParam; ++i) {
					MemCalculator->Redo();
				}
			}
			break;
		case 3 :
			{
				Token* TokenParam = E.GetToken(1);
				if (TokenParam->GetType() != bil) throw CalculatorException("[syntax error]");

				Bilangan* bilParam = (Bilangan*) TokenParam;
				int showMemParam = int(bilParam->GetValue());

				MemCalculator->ShowMem(showMemParam);
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