#include "Enum.h"
#include "Penghitung.h"
#include "PenghitungException.h"

Penghitung::Penghitung() {}

Penghitung::Penghitung(const Penghitung& p) {
	ModeSintaks = p.ModeSintaks;
	ModeMathLogic = p.ModeMathLogic;
}

Penghitung::~Penghitung() {}

// operator= tidak diperlukan karena tidak ada assignment

double Penghitung::Calculate(Expression E) {
	std::cout << ModeSintaks << std::endl;
	if(ModeMathLogic == logic) {
		std::cout << "Logic" << std::endl;
		ParseInfix(E);
	} else {
		std::cout << "Math" << std::endl;

		switch (ModeSintaks) {
			infix : ParseInfix(E); break;
			prefix : E.InvertExpression(); break;
			postfix : break;
		}
	}
	return CalculatePostfix(E);
}

void Penghitung::SetSintaks(EnumSintaks Mode) {
	ModeSintaks = Mode;
}

void Penghitung::SetMathLogic(EnumMathLogic Mode) {
	ModeMathLogic = Mode;
}

double Penghitung::CalculateAtom(double a, double b, Operator* o) {
	if (ModeMathLogic == math)
	{
		if (o->GetJenisOperator() == Plus) 
			return a + b;
		else if (o->GetJenisOperator() == Minus) 
			return a - b;
		else if (o->GetJenisOperator() == bagi) 
			return a / b;
		else if (o->GetJenisOperator() == kali) 
			return a * b;
		else if (o->GetJenisOperator() == Div) 
			return int(a / b);
		else if (o->GetJenisOperator() == Mod) 
			return a - int(a / b) * b;
		else
			throw PenghitungException("Terdapat kesalahan pada ekspresi.");
			
	}
	else
	{
		if (o->GetJenisOperator() == And) 
			return int(a) & int(b);
		else if (o->GetJenisOperator() == Or) 
			return int(a) | int(b);
		else if (o->GetJenisOperator() == Xor) 
			return int(a) ^ int(b);
		else
			throw PenghitungException("Terdapat kesalahan pada ekspresi.");
	}

}
	
double Penghitung::CalculatePostfix(Expression& E) {
	stack<double> s;
	for (int i = 0; i < E.GetLength(); ++i) {
		Token* cur = E.GetToken(i);
		if (cur->GetType() == opr) {
			double b2 = s.top(); s.pop();
			double b1 = s.top(); s.pop();
			Operator *op = (Operator *) cur;
			s.push(CalculateAtom(b1, b2, op));
		} else {
			if (cur->GetType()!=bil) throw PenghitungException("Terdapat kesalahan pada sintaks.");
			Bilangan *op = (Bilangan*) cur;
			s.push(op->GetValue());
		}
	}
	return s.top();
}

void Penghitung::ParseInfix(Expression& E) {
	stack<Token*> s1;
	Expression s2;

	for(int i = 0; i < E.GetLength(); ++i) {
		Token* cur = E.GetToken(i);
		if (cur->GetType() == bil) {
			s2.AddToken(cur);
		} else {
			Operator op(cur->Display());
			if (op.GetJenisOperator() == kurungBuka) {
				s1.push(cur);
			}
			else if (op.GetJenisOperator() == kurungTutup) {
				while ( ( op = Operator( s1.top()->Display() ) ).GetJenisOperator() 
					!= kurungBuka) {
					s2.AddToken(s1.top());
					s1.pop();
				}
				s1.pop();	// pop kurungBuka
			}
			else if (op.GetJenisOperator() == Not) {		// Not x = x - 2x + 1
				i++;
				if (i == E.GetLength()) throw // Expression incomplete
				cur = E.GetToken(i);
				s2.AddToken(cur);
				cur = new Arab(cur->Display());
				s2.AddToken(cur);
				cur = new Operator("-");
				s2.AddToken(cur);
				cur = new Arab("1");
				s2.AddToken(cur);
				cur = new Operator("+");
				s2.AddToken(cur);
			} else {
				if (op.GetJenisOperator() == kali || op.GetJenisOperator() == bagi)
					s1.push(cur);
				else {
					Operator op2;
					try {
						while ( (op2 = Operator(s1.top()->Display())).GetType() == opr
							&& (op2.GetJenisOperator() == kali || op2.GetJenisOperator() == bagi)
						) {
							s2.AddToken(&op2);
							s1.pop();
						}
					} catch (StackExp& e) {}

					s1.push(cur);
				}
			}
		}
	}
	while (!s1.empty()) {
		s2.AddToken(s1.top());
		s1.pop();
	}
	E = s2;
}