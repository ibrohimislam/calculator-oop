#include "Token.h"

#include "Perintah.h"

static std::string Perintah::KarakterPerintah = {"set",
		"undo",
		"redo",
		"showmem",
		"showall",
		"save"};

Perintah::Perintah(std::string _s) {
	int banyak_perintah = sizeof(KarakterPerintah)/sizeof(string);
	
	bool ditemukan = false;

	for (int i = 0; (i < banyak_perintah) && (!ditemukan); ++i)
		if (_s == KarakterPerintah[i]){
			JenisOperator = i;
			ditemukan = true;
		}

	assert(ditemukan);
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