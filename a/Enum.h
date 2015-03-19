#ifndef _ENUM_H_
#define _ENUM_H_

/**
 * @enum EnumType
 * 
 * Enumerasi yang digunakan untuk mengidentifikasi tipe polimorf suatu token
 */

enum EnumType{
	bil,
	opr,
	cmd
};

/**
 * @enum EnumBilangan
 * 
 * Enumerasi yang digunakan untuk mengidentifikasi jenis bilangan
 */
enum EnumBilangan{
	arab,
	romawi
};

/**
 * @enum EnumOperator
 * 
 * Enumerasi yang digunakan untuk mengidentifikasi jenis operator
 */
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

/**
 * @enum EnumPerintah
 * 
 * Enumerasi yang digunakan untuk mengidentifikasi jenis perintah
 */
enum EnumPerintah {
	set,
	undo,
	redo,
	showmem,
	showall,
	save
};

/**
 * @enum EnumSintaks
 * 
 * Enumerasi yang digunakan untuk mengidentifikasi jenis sintaks
 */
enum EnumSintaks {
	postfix,
	prefix,
	infix
};

/**
 * @enum EnumMathLogic
 * 
 * Enumerasi yang digunakan untuk mengidentifikasi jenis perhitungan (matematika atau logika)
 */
enum EnumMathLogic {
	math,
	logic
};

#endif