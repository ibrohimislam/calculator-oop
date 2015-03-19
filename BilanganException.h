#ifndef _BILANGANEXCEPTION_H_
#define _BILANGANEXCEPTION_H_

#include <string>

/**
 * Class BilanganException
 * 
 * @class     BilanganException BilanganException.h "BilanganException.h"
 * @package   Parser
 * @brief     Kelas exception spesifik class Bilangan
 * @author    Satria Priambada
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */

class BilanganException
{
public:

	/**
	 * Constructor default
	 *
	 * Konstruktor yang digunakan untuk membuat Objek exception dengan pesan kosong
	 *
	 */
	BilanganException(){
		MsgBilanganExp = "";
	}

	/**
	 * Constructor default
	 *
	 * Konstruktor yang digunakan untuk membuat Objek exception dengan pesan s
	 *
	 * @param s std::string
	 *
	 */
	BilanganException(const std::string& s){
		MsgBilanganExp = s;
	}

	/**
	 * Destructor
	 *
	 * @param none
	 */

	~BilanganException(){}

	//tidak memerlukan opr= dan cctor

	/**
	 * Prosedur DisplayMsg
	 *
	 * Prosedur yang digunakan untuk menampilkan pesan kesalahan
	 *
	 * @param none
	 *
	 */
	void DisplayMsg(){
		std::cout << MsgBilanganExp<<std::endl;
	}
private:
	std::string MsgBilanganExp; 
};

#endif
