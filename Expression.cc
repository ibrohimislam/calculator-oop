#include "Expression.h"

//dtor pada saat dtor semua token yang diberikan kepada expression akan dihancurkan
Expression::~Expression(){
	int PanjangExpresi = GetLength();
	for (int i = 0; i < PanjangExpresi; ++i)
	{
		delete VectorOfToken[i];
	}
}
Token* Expression::GetToken(int i){
	return VectorOfToken[i];
}
int Expression::GetLength(){
	return VectorOfToken.size();

}
void Expression::AddToken(Token* T){
	VectorOfToken.push_back(T);
}
