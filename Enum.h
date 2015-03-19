#ifndef _ENUM_H_
#define _ENUM_H_

/**
 * EnumType
 *
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
 * Enum EnumBilangan
 * 
 * @enum EnumBilangan
 * 
 * Enumerasi yang digunakan untuk mengidentifikasi jenis bilangan
 */
enum EnumBilangan{
	arab,
	romawi
};

/**
 * Enum EnumOperator
 * 
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
 * Enum EnumPerintah
 * 
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
 * Enum EnumSintaks
 * 
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
 * Enum EnumMathLogic
 * 
 * @enum EnumMathLogic
 * 
 * Enumerasi yang digunakan untuk mengidentifikasi jenis perhitungan (matematika atau logika)
 */
enum EnumMathLogic {
	math,
	logic
};

#endif