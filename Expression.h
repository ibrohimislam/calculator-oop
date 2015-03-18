#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

#include "STL/vector.h"
#include "Token.h"
//#include <vector>

using namespace std;

class Expression
{
public:
	//ctor
	Expression(){}
	//dtor pada saat dtor semua token yang diberikan kepada expression akan dihancurkan
	~Expression();
	//tidak diperlukan nilai cctor dan operator= karena tidak ada assign ekspresi
	Token* GetToken(int i);
	int GetLength();
	void AddToken(Token* T);
private:
	vector<Token*> VectorOfToken;
};

#endif