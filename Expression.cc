#include "Expression.h"
#include "Bilangan.h"
#include "Arab.h"
#include "Romawi.h"
#include "Perintah.h"
#include "Operator.h"

//dtor tidak bertangung jawab kepada token yang diberikan

Expression::~Expression(){
}

Expression& Expression::operator=(const Expression& E1){
	VectorOfToken.clear();
	int PanjangExpresi= E1.GetLength();
	
	for (int i = 0; i < PanjangExpresi; ++i)
	{
		VectorOfToken.push_back(E1.GetToken(i));
	}

	return *this;
}
Expression::Expression(const Expression& E1){
	int PanjangExpresi= E1.GetLength();
	
	for (int i = 0; i < PanjangExpresi; ++i)
	{
		VectorOfToken.push_back(E1.GetToken(i));
	}

}
Token* Expression::GetToken(int i) const{
	return VectorOfToken[i];
}

int Expression::GetLength() const {
	return VectorOfToken.size();
}

void Expression::AddToken(Token* T){
	VectorOfToken.push_back(T);
}
