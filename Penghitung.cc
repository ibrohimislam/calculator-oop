#include "Penghitung.h"
#include "STL/stack.h"

Penghitung::Penghitung() {}

Penghitung::Penghitung(const Penghitung& p) {
	ModeSintaks = p.ModeSintaks;
	ModeMathLogic = p.ModeMathLogic;
}

Penghitung::~Penghitung() {}

// operator= tidak diperlukan karena tidak ada assignment

double Penghitung::Calculate(Expression E) {
	if(ModeMathLogic = logic) {
		ParseInfix(E);
	} else {
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

double Penghitung::CalculateAtom(double a, double b, Operator o) {
	if (o.GetJenisOperator() == plus) 
		return a + b;
	else if (o.GetJenisOperator() == minus) 
		return a - b;
	else if (o.GetJenisOperator() == bagi) 
		return a / b;
	else if (o.GetJenisOperator() == kali) 
		return a * b;
	else if (o.GetJenisOperator() == Div) 
		return int(a / b);
	else if (o.GetJenisOperator() == Mod) 
		return a - int(a / b) * b;
	else if (o.GetJenisOperator() == And) 
		return int(a) & int(b);
	else if (o.GetJenisOperator() == Or) 
		return int(a) | int(b);
	else if (o.GetJenisOperator() == Xor) 
		return int(a) ^ int(b);
}

double Penghitung::CalculatePostfix(Expression& E) {
	stack<double> s;
	for (int i = 0; i < E.GetLength(); ++i) {
		Token* cur = E.GetToken(i);
		if (cur->GetType() == opr) {
			double b1 = s.top(); s.pop();
			double b2 = s.top(); s.pop();
			s.push(CalculateAtom(b1, b2, (Operator)*cur));
		} else {
			s.push((Bilangan*)cur->GetValue());
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
			s2.AddToken(bil&);
		} else {
			if (cur->GetJenisOperator() == kurungBuka) {
				s1.push(cur&);
			}
			else if (cur->GetJenisOperator() == kurungTutup) {
				while (s1.top().GetJenisOperator() != kurungBuka) {
					s2.AddToken(s1.top());
					s1.pop();
				}
				s1.pop();	// pop kurungBuka
			}
			else if (cur->GetJenisOperator() == Not) {		// Not x = x - 2x + 1
				i++;
				if (i == E.GetLength()) throw // Expression incomplete

				cur = E.GetToken(i);
				s2.AddToken(cur&);
				cur = Arab(cur->GetValue() == 0 ? "0" : "1");
				s2.AddToken(cur&);
				cur = Operator("-");
				s2.AddToken(cur&);
				cur = Arab("1");
				s2.AddToken(cur&);
				cur = Operator("+");
				s2.AddToken(cur&);
			} else {

			}
		}
	}
	E = s2;
	/*
	for(int i = 0; i < E.GetLength(); ++i) {
		Token cur = E.GetToken(i);
		if (cur->GetType() != opr || cur.GetJenisOperator() == kurungBuka) 
			o = Operator("+");
			continue;
		else {
			o = cur;
		}
		if (cur.GetType() == opr && cur.GetJenisOperator() == kurungBuka) {
			int parenthesesBalance = 1;
			Expression Ee;
			while (i < (E.GetLength() - 1) && parenthesesBalance != 0) {
				++i;
				if (cur.GetType() == opr) {
					parenthesesBalance +=
						(cur.GetJenisOperator() == kurungBuka ? 1
						: cur.GetJenisOperator() == kurungBuka ? -1
						: 0);
				}
				if (parenthesesBalance) Ee.AddToken(&cur);
			}
			if (parenthesesBalance != 0) throw //Expression wrong
			else {
				bef = Calculate(Ee);
			}
		}
		else if (cur.GetType() == opr && cur.GetJenisOperator() == kurungTutup)
			throw //Expression wrong
		else
			bef = cur.GetValue();
		ans = CalculateAtom(ans, bef, o);
	}
	*/
}