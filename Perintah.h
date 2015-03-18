#ifndef _PERINTAH_H_
#define _PERINTAH_H_

#include "Token.h"
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
		void Display();
		EnumType GetType();
	private:
		EnumPerintah JenisPerintah;
		static std::string KarakterPerintah[];
};

#endif