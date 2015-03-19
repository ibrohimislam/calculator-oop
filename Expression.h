#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

#include "STL/vector.h"
#include "Bilangan.h"
#include "Arab.h"
#include "Romawi.h"
#include "Perintah.h"
#include "Operator.h"
#include "Token.h"

using namespace std;

/**
 * Class Expression
 * 
 * @class     Expression Expression.h "Expression.h"
 * @package   Memori
 * @brief     Kelas yang digunakan untuk merepresentasikan ekspresi,
 *            merupakan pembungkusan vector of (pointer to token).
 * @author    Satria Priambada
 * @version   0.1
 * @date      Maret 2015
 * @warning   semua pointer token yang diberikan dapat ditunjuk oleh lebih dari 1 ekspresi.
 * @warning   destructor tidak bertangung jawab kepada token yang diberikan.
 * 
 */

class Expression
{
public:
	//ctor
	Expression(){}
	Expression(const Expression& E1);
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