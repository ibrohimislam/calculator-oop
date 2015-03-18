#include "Memori.h"
#include <iostream>

Memori::Memori(){
}

Memori::~Memori(){
}

Expression Memori::GetExpression(int){
	return VectorOfExpression[i];
}
Expression Memori::GetAllExpression(){
	return VectorOfExpression;
}

int Memori::GetLength(){
	return VectorOfExpression.size();
}

void Memori::Undo(){

}

void Memori::Redo(){

}

void Memori::Save(){

}

void Memori::ShowMem(){
	int numEx,numToken;
	for (numEx=0; numEx < this.GetLength();++numEx){
		for (numToken = 0; numToken < this.GetExpression(numEx).GetLength;++numToken){
			Token tempT = this.GetExpression(numEx).GetToken(numToken);
			tempT.Display(); std::cout << " ";
		}
		std::cout << std::endl;
	}
}
void Memori::ShowAll(){

}