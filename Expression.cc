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
	int PanjangExpresi = E1.GetLength();
	
	for (int i = 0; i < PanjangExpresi; ++i)
	{
		VectorOfToken.push_back(E1.GetToken(i));
	}

	std::cout << "assign expr" << VectorOfToken.size() << std::endl;

	return *this;
}

Expression::Expression(const Expression& E1){
	
	int PanjangExpresi= E1.GetLength();
	for (int i = 0; i < PanjangExpresi; ++i)
	{
		VectorOfToken.push_back(E1.GetToken(i));
	}

	std::cout << "cctor expr" << VectorOfToken.size() << std::endl;

}
Token* Expression::GetToken(int i) const{
	return VectorOfToken[i];
}

int Expression::GetLength() const {
	return VectorOfToken.size();
}

void Expression::AddToken(Token* T){
	VectorOfToken.push_back(*T);
}

void Expression::InvertExpression() {
	for (int i = 0; i <= VectorOfToken.size() / 2; ++i)
		int j = VectorOfToken.size() - i - 1;
		Token tmp = VectorOfToken[i];
		VectorOfToken[i] = VectorOfToken[j];
		VectorOfToken[j] = tmp;
	}
}
