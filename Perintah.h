#ifndef _PERINTAH_H_
#define _PERINTAH_H_

#include "Token.h"
#include <string.h>

class Perintah : public Token{
	public:
		//ctor
		Perintah(){}
		//dtor
		~Perintah(){}
		//cctor dan operator= tidak dibutuhkan karena tidak akan dilakukan assignment antar operator
		EnumPerintah GetJenisPerintah();
	private:
		EnumPerintah JenisPerintah;
		static std::string KarakterPerintah[];
};

#endif