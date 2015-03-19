#ifndef _PENGHITUNG_H_
#define _PENGHITUNG_H_

#include "Arab.h"
#include "Enum.h"
#include "Expression.h"
#include "Operator.h"
#include "STL/stack.h"

/**
 * Class Penghitung
 *
 * Kelas yang digunakan untuk melakukan proses menghitung token
 * 
 * @class     Penghitung Penghitung.h "Penghitung.h"
 * @package   Menghitung
 * @brief     Kelas yang digunakan untuk melakukan proses menghitung token
 * @author    Afrizal Fikri
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */

class Penghitung {
public:
	/** 
	 * Konstruktor default
	 * 
	 * Menciptakan obyek Penghitung yang akan digunakan
	 * dalam proses penghitungan
	 * 
	 * @param none
	 */ 
	 
	Penghitung();/*default constructor*/
	
	/** 
	 * Copy konstruktor
	 * 
	 * Menggandakan obyek Penghitung dari suatu
	 * obyek Penghitung yang sudah diciptakan dahulu
	 * 
	 * @param Penghitung&
	 * @pre p terdefinisi
	 */ 
	 
	Penghitung(const Penghitung& p);/*cctor*/
	
	/** 
	 * Destruktor
	 */
	 
	~Penghitung(); /* dtor */
	
	/* operator= tidak diperlukan karena tidak ada pointer */

	/**
	 * Fungsi Calculate
	 * 
	 * Melakukan proses penghitungan ekspresi dan 
	 * mendapatkan nilai hasil perhitungan
	 * 
	 * @param Expression
	 * @return double
	 * @pre ekspresi tidak kosong
	 */
	 
	double Calculate(Expression);
	
	/**
	 * Prosedur SetSintaks
	 * 
	 * Mengatur mode ekspresi yang ingin dihitung
	 * (infix, postfix, prefix)
	 * 
	 * @param EnumSintaks
	 */
	 
	void SetSintaks(EnumSintaks);
	
	/** Prosedur SetMathLogic
	 * 
	 * Mengatur mode perhitungan yang digunakan
	 * yaitu aritmatika atau logika
	 * 
	 * @param EnumMathLogic
	 */
	 
	void SetMathLogic(EnumMathLogic);
	
	/**
	 * Fungsi CalculatePostfix
	 * 
	 * Menghitung ekspresi yang terformat secara postfix
	 * dan mengembalikan hasil perhitungan
	 * 
	 * @param Expression
	 * @return double
	 */
	 
	double CalculatePostfix(Expression&);
	
	/**
	 * Prosedur ParseInfix
	 * 
	 * Mengubah ekspresi dalam infix menjadi ekspresi
	 * dalam bentuk postfix
	 * 
	 * @param Expression&
	 */
	 
	void ParseInfix(Expression&);
	
	/**
	 * Prosedur ParsePrefix
	 * 
	 * Mengubah ekspresi dalam prefix menjadi ekspresi
	 * dalam bentuk postfix
	 * 
	 * @param Expression&
	 */
	 
	void ParsePrefix(Expression&);
	
	/**
	 * Fungsi CalculateAtom
	 * 
	 * Melakukan pengecekan operasi atomik (uner atau biner)
	 * dan menghitung hasilnya
	 * 
	 * @param double double Operator*
	 * @return double
	 */
	double CalculateAtom(double, double, Operator*);

private:
	EnumSintaks ModeSintaks;
	EnumMathLogic ModeMathLogic;
};

#endif
