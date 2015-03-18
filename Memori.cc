#include "Memori.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <assert.h>

Memori::Memori(){
	head = 0;
	length = 0;
}

Memori::~Memori(){
	int numEx,numToken;
	int len = GetLength();
	for (numEx=0; numEx < len;++numEx){
		Expression& ExKei = this->GetExpression(numEx);
		int lenExKei = ExKei.GetLength();
		for (numToken = 0; numToken < lenExKei; ++numToken){
			delete ExKei.GetToken(numToken);
		}
	}
}
void Memori::AddExpression(const Expression& E){
	if(head < length){
		std::cout << "fail\n";
		int numEx,numToken;
		int len = this->GetLength();
		for (numEx = head + 1; numEx < len;++numEx){
			Expression ExKei = this->GetExpression(numEx);
			int lenExKei = ExKei.GetLength();
			for (numToken = 0; numToken < lenExKei; ++numToken){
				delete ExKei.GetToken(numToken);
			}
		}
	}else{//head = length karena head tidak mungkin lebih besar dari length
		std::cout << "head = length\n";
		++head;
		length = head;
		VectorOfExpression.push_back(E);
	}
}

Expression& Memori::GetExpression(int i){
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
	++head;
	return VectorOfExpression[head];
}

void Memori::Save(){
  string str;
  
  fstream fout;
  fout.open("savedFile.txt");

  	int numEx,numToken;
	int len = GetLength();
	for (numEx=0; numEx < len;++numEx){
		str = "";

		Expression& ExKei = this->GetExpression(numEx);
		int lenExKei = ExKei.GetLength();
		for (numToken = 0; numToken < lenExKei - 1; ++numToken){
			Token* tempT = ExKei.GetToken(numToken);
			str = tempT->Display();
			str = str + " ";
		}
		//Beri enter pada akhir ekspresi
		str = str + ExKei.GetToken(lenExKei - 1)->Display() + "\n";
		//Masukkan ekspresi ke dalam file SaveMemori

		fout << str;
	}

	fout.close();

}


void Memori::ShowMem(int n){
	int numEx,numToken;
	int len = GetLength();
	for (numEx=len-n; numEx < len;++numEx){
		Expression ExKei = this->GetExpression(numEx);
		int lenExKei = ExKei.GetLength();
		for (numToken = 0; numToken < lenExKei; ++numToken){
			Token* tempT = ExKei.GetToken(numToken);
			std::cout << tempT->Display() << " ";
		}
		std::cout << std::endl;
	}
}

void Memori::ShowAll(){
	int len = GetLength();
	this->ShowMem(len);
}