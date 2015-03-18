#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

#include "vector.h"
#include <vector>

using namespace std;

class Expression
{
public:
	//ctor
	Expression(){}
	//dtor
	~Expression(){}
	//tidak diperlukan nilai cctor dan operator= karena tidak ada assign ekspresi
	Token GetToken(int i);
	int GetLength();
	void AddToken(Token T);
private:
	vector<Token> VectorOfToken;
};

#endif