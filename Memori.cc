#include "Memori.h"
#include <iostream>
#include <stdlib.h>
#include <string>

Memori::Memori(){

}

Memori::~Memori(){

}

Expression& Memori::GetExpression(int){
	return VectorOfExpression[i];
}

vector<Expression>& Memori::GetAllExpression(){
	return VectorOfExpression;
}

int Memori::GetLength(){
	return length;
}

bool Memori::Undo(int n){
	if (head >= n)
	{
		head = head - n;
		return 1;
	}
	else
	{
		return 0;
	}
}

Expression& Memori::Redo(){
//Prekondisi head harus lebih kecil dari length	
	
	assert (head < length);
	Expression Etemp;
	++head;
	Etemp = VectorOfExpression[head];
	return Etemp;
}

void Memori::Save(){
  char str[100];
  FILE *fp;

  if((fp = fopen("SaveMemori", "w"))==NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }
else{

}
}


}

void Memori::ShowMem(int n){
	int numEx,numToken;
	int len = GetLength();
	for (numEx=len-n; numEx < len;++numEx){
		Expression ExKei = this->GetExpression(numEx);
		int lenExKei = ExKei.GetLength();
		for (numToken = 0; numToken < lenExpr; ++numToken){
			Token tempT = ExKei.GetToken(numToken);
			tempT.Display(); std::cout << " ";
		}
		std::cout << std::endl;
	}
}

void Memori::ShowAll(){
	int len = GetLength();
	this->ShowMem(len);
}