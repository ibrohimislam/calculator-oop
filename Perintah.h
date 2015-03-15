#include "Token.h"
#ifndef _PERINTAH_H_
#define _PERINTAH_H_

class Perintah : public Token{
	public:
		EnumPerintah GetJenisPerintah();
	private:
		EnumPerintah JenisPerintah;
};

#endif