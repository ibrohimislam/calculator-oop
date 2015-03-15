#ifndef _PERINTAH_H_
#define _PERINTAH_H_

#include "Token.h"
#include <string.h>

class Perintah : public Token{
	public:
		Perintah();
		EnumPerintah GetJenisPerintah();
	private:
		EnumPerintah JenisPerintah;
		static std::string KarakterPerintah[];
};

#endif