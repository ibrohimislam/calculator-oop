#ifndef _PENGHITUNGEXCEPTION_H_
#define _PENGHITUNGEXCEPTION_H_

#include <string>
#include <iostream>

/**
 * Class PenghitungException
 * 
 * @class     PenghitungException PenghitungException.h "PenghitungException.h"
 * @package   Menghitung
 * @brief     Kelas yang digunakan untuk melakukan proses exception penghitung
 * @author    Afrizal Fikri
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */

class PenghitungException
{
public:
	//ctor
	PenghitungException(){
		MsgPenghitungExp = "";
	}
	PenghitungException(const std::string& s){
		MsgPenghitungExp = s;
	}
	//dtor
	~PenghitungException(){}

	//tidak memerlukan opr= dan cctor
	void DisplayMsg(){
		std::cout << MsgPenghitungExp<<std::endl;
	}
private:
	std::string MsgPenghitungExp; 
};

#endif