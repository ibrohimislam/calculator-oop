#include "Penghitung.h"
#include "Parser.h"

using namespace std;

int main() {
	Penghitung p;
	p.SetSintaks(postfix);
	p.SetMathLogic(math);

	string s;
	getline(cin, s);
	Parser pars;
	Expression e = pars.Parse(s);
	try {
		cout << p.Calculate( e )<< endl;
	} catch (StackExp& e) {
		e.printMsg();
	};
}