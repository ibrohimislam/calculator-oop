#ifndef _PERINTAH_H_
#define _PERINTAH_H_

#include "Token.h"
#include <iostream>
#include <assert.h>
#include <string>
/**
 * Class Perintah
 *
 * Kelas yang digunakan untuk merepresentasikan token perintah
 * 
 * @class     Perintah Perintah.h "Perintah.h"
 * @package   Parser
 * @brief     Kelas yang digunakan untuk merepresentasikan token perintah
 * @author    Satria Priambada
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */

class Perintah : public Token{
public:
	/**
	 * Konstruktor default
	 * 
	 * Konstuktor tanpa parameter
	 */
	 
	Perintah(){} /*default constructor*/
	
	/** 
	 * Konstruktor dengan parameter string
	 * 
	 * Konstruktor yang mengubah string masukan menjadi
	 * perintah yang sesuai
	 * 
	 * @param string
	 */
	 
	Perintah(std::string _s); /*constructor with parameter string*/
	
	/**
	 * Destruktor
	 * 
	 */
	
	~Perintah(){}
	
	/* cctor dan operator= tidak dibutuhkan karena tidak akan dilakukan assignment antar operator */
	
	/**
	 * Fungsi GetJenisPerintah 
	 * 
	 * Mendapatkan tipe perintah dari kelas Perintah yang sudah ada
	 * 
	 * @param none
	 * @return EnumPerintah
	 */

	EnumPerintah GetJenisPerintah();
	
	/**
	 * Fungsi Display
	 * 
	 * Fungsi bantunan untuk mencetak Perintah
	 * Berfungsi menmbuat string dari Perintah
	 * 
	 * @param none
	 * @return string
	 */
	 
	std::string Display();
	
	/** Fungsi GetType
	 * 
	 * Fungsi yang mendapatkan tipe Token, yaitu Perintah
	 * 
	 * @param none
	 * @return EnumType 
	 */
	 
	EnumType GetType();
	
	/** 
	 * KarakterPerintah
	 * 
	 * Daftar perintah yang tersedia
	 * 
	 * @enum string
	 */
	 
	static std::string KarakterPerintah[];
	static int BanyakPerintah;
	
private:
	EnumPerintah JenisPerintah;
};

#endif
