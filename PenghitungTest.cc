#include "Penghitung.h"
#include "Parser.h"
#include "Memori.h"
#include "Enum.h"

using namespace std;

void run();

int main() {
	run();
}

void JalankanPerintah(Expression& E) {

}

void run(){
	Penghitung p;
	Parser pars;
	Memori mem;

	p.SetSintaks(postfix);
	p.SetMathLogic(math);

	string s;

	while (1) {
		
		getline(cin, s);

		Expression e = pars.Parse(s);
		Token* firstToken = e.GetToken(0);
		
		if (firstToken->GetType() == cmd) {
			JalankanPerintah(e);
		}
		else {
			try {
				cout << p.Calculate( e )<< endl;
			} catch (StackExp& e) {
				e.printMsg();
			};
		}

	}
}
