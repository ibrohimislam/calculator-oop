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
		div,
		mod,
		and,
		or,
		not,
		xor
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