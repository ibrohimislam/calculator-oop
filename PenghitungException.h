#ifndef _PENGHITUNGEXCEPTION_H_
#define _PENGHITUNGEXCEPTION_H_

#include <string>
#include <iostream>

/**
 * Class PenghitungException
 *
 * Kelas yang digunakan untuk melakukan proses exception penghitung
 * 
 * @class     PenghitungException PenghitungException.h "PenghitungException.h"
 * @package   Menghitung
 * @brief     Kelas yang digunakan untuk melakukan proses exception penghitungan
 * @author    Afrizal Fikri
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */

class PenghitungException
{
public:
	/**
	 * Konstruktor default
	 * 
	 * Konstruktor tanpa parameter yang menginisiasi
	 * nilai pesan kesalahan dengan string kosong
	 * 
	 * @param none
	 */
	 
	PenghitungException(){
		MsgPenghitungExp = "";
	}
	
	/**
	 * Konstruktor dengan parameter string
	 * 
	 * Konstruktor dengan parameter string yang menginisiasi
	 * nilai pesan kesalahan dengan string masukan
	 * 
	 * @param string
	 */
	 
	PenghitungException(const std::string& s){
		MsgPenghitungExp = s;
	}
	
	/** 
	 * Destruktor
	 */
	 
	~PenghitungException(){}

	/* tidak memerlukan opr= dan cctor */
	
	/**
	 * Prosedur DisplayMsg
	 * 
	 * Mencetak pesan kesalahan dari exception yang dilempar
	 * 
	 * @param none
	 * @return none
	 */
	 
	void DisplayMsg(){
		std::cout << MsgPenghitungExp<<std::endl;
	}
	
private:
	std::string MsgPenghitungExp; 
};

#endif
