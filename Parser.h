#ifndef _PARSER_H_
#define _PARSER_H_
#include "STL/vector.h"
//#include "expression.h"
#include "Enum.h"
#include <string>

using namespace std;

class Parser{
	public:
		//ctor default arab
		Parser() {ModeB = (EnumBilangan)0;}
		//dtor
		~Parser(){}
		//operator= dan dan cctor tidak diperlukan karena tidak akan ada inisialisasi objek parser ke parser lain
		void SetModeBilangan(EnumBilangan B);
		Expression Parse(const std::string& s);
	private:
		EnumBilangan ModeB;
};

#endif