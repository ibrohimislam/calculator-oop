#ifndef _ENUM_H_
#define _ENUM_H_
	enum EnumType{
		Bilangan,
		Operator,
		Perintah
	}
	enum EnumBilangan{
		arab,
		romawi,
	}
	enum EnumOperator{
		plus,
		minus,
		bagi,
		kali,
		Div,
		Mod,
		And,
		Or,
		Not,
		Xor,
		kurungBuka,
		kurungTutup
	}
	enum EnumPerintah {
		set,
		undo,
		redo,
		showmem,
		showall,
		save
	}
#endif