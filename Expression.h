#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

#include "STL/vector.h"
#include "Token.h"

using namespace std;

class Expression
{
public:
	//ctor
	Expression(){}
	//dtor tidak bertangung jawab kepada token yang diberikan
	~Expression();
	//tidak diperlukan nilai cctor karena tidak ada assign ekspresi
	//operator=
	Expression& operator= (const Expression& E1);
	Token* GetToken(int i) const;
	int GetLength() const;
	void AddToken(Token* T);
private:
	vector<Token*> VectorOfToken;
};

#endif