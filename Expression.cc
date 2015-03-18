#include "Expression.h"

Token Expression::GetToken(int i){
	return VectorOfToken[i];
}
int Expression::GetLength(){
	return VectorOfToken.size();

}
void Expression::AddToken(Token T){
	VectorOfToken.push_back(T);
}
