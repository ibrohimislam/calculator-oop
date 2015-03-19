#include "Perintah.h"

std::string Perintah::KarakterPerintah[] = {"set",
		"undo",
		"redo",
		"showmem",
		"showall",
		"save"};

int Perintah::BanyakPerintah = 6;


Perintah::Perintah(std::string _s) {
	int banyak_perintah = sizeof(KarakterPerintah)/sizeof(std::string);
	
	bool ditemukan = false;

	for (int i = 0; (i < banyak_perintah) && (!ditemukan); ++i)
		if (_s == KarakterPerintah[i]){
			JenisPerintah = (EnumPerintah)i;
			ditemukan = true;
		}

	assert(ditemukan);
}


EnumType Perintah::GetType (){
	return cmd;
}

std::string Perintah::Display(){
	return Perintah::KarakterPerintah[JenisPerintah];
}

EnumPerintah Perintah:: GetJenisPerintah(){
	return JenisPerintah;
}