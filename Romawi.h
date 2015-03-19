#ifndef _ROMAWI_H_
#define _ROMAWI_H_


#include <iostream>
#include <cstdlib>
#include <cassert>
#include "Token.h"
#include "Bilangan.h"
#include "BilanganException.h"
#include <string>
#include <cstring>

/**
 * Class Romawi
 *
 * Kelas yang digunakan untuk merepresentasikan bilangan romawi
 * 
 * @class     Romawi Romawi.h "Romawi.h"
 * @package   Parser
 * @brief     Kelas yang digunakan untuk merepresentasikan bilangan romawi
 * @author    Satria Priambada
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */
class Romawi: public Bilangan{
	public:
		/**
		 * Konstruktor default
		 * 
		 * Konstruktor tanpa parameter
		 */
		 
		Romawi();
		
		/** 
		 * Konstruktor dengan parameter nilai
		 * 
		 * Konstruktor dengan masukan nilai yang akan dibuat Bilangan Romawinya
		 * 
		 * @param const double
		 * @pre d terdefinisi
		 */
		 
		Romawi(const double d);	
		
		/**
		 * Konstruktor dengan parameter string
		 * 
		 * Konstruktor dengan masukan string dari Romawi terkait
		 * 
		 * @param string&
		 */
		 
		Romawi(const std::string& s);	
		
		/**
		 * Destruktor
		 * 
		 * @param none
		 */
		 
		~Romawi(){}
		
		/* cctor dan operator= tidak pernah dipakai karena tidak mungkin instansiasi */
		
		/**
		 * Fungsi GetValue
		 * 
		 * Fungsi untuk mendapat nilai dari Romawi
		 * 
		 * @param none
		 * @return double
		 */
		 
		double GetValue();
		
		/**
		 * Fungsi Display
		 * 
		 * Fungsi bantunan untuk mencetak Romawi
		 * Berfungsi menmbuat string dari Romawi
		 * 
		 * @param none
		 * @return string
		 */
		 
		std::string Display();
		
		
	private:
		int Value;
};

#endif
