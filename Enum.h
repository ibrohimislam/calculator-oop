#ifndef _ENUM_H_
#define _ENUM_H_

enum EnumType{
	bil,
	opr,
	cmd
};
enum EnumBilangan{
	arab,
	romawi
};
enum EnumOperator{
	Plus,
	Minus,
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
};
enum EnumPerintah {
	set,
	undo,
	redo,
	showmem,
	showall,
	save
};
enum EnumSintaks {
	postfix,
	prefix,
	infix
};
enum EnumMathLogic {
	math,
	logic
};

#endif