#include "Token.h"

#include "Perintah.h"

static std::string Perintah::KarakterPerintah = {"+", "-", "/", "*", "div", "mod", "&&", "||", "!", "^"};

Perintah::Perintah(std::string _s) {
	if (_s=="+")
	{
		JenisPerintah = plus;
	}
	else if (_s=="-")
	{
		JenisPerintah = minus;
	}
	else if (_s=="/")
	{
		JenisPerintah = bagi;
	}
	else if (_s=="*")
	{
		JenisPerintah = kali;
	}
	else if (_s=="div")
	{
		JenisPerintah = div;
	}
	else if (_s=="mod")
	{
		JenisPerintah = mod;
	}
	else if (_s=="&&")
	{
		JenisPerintah = and;
	}
	else if (_s=="||")
	{
		JenisPerintah = or;
	}
	else if (_s=="!")
	{
		JenisPerintah = not;
	}
	else if (_s=="^"	)
	{
		JenisPerintah = xor;
	}
}

EnumType Perintah::GetType (){
	return Perintah;
}

void Perintah::Display(){
	cout << Perintah::KarakterPerintah[JenisPerintah];
}

EnumPerintah Perintah:: GetJenisPerintah(){
	return JenisPerintah;
}