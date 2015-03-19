#ifndef _PERINTAH_H_
#define _PERINTAH_H_

#include "Token.h"
#include <iostream>
#include <assert.h>
#include <string>

class Perintah : public Token{
	public:
		//ctor
		Perintah(){}
		Perintah(std::string _s);
		//dtor
		~Perintah(){}
		//cctor dan operator= tidak dibutuhkan karena tidak akan dilakukan assignment antar operator
		EnumPerintah GetJenisPerintah();
		std::string Display();
		EnumType GetType();
		static std::string KarakterPerintah[];
		static int BanyakPerintah;
	private:
		EnumPerintah JenisPerintah;
};

#endif