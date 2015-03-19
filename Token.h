#ifndef _TOKEN_H_
#define _TOKEN_H_

#include "Enum.h"
#include <string>

/**
 * Class Token
 *
 * Kelas abstrak yang digunakan untuk merepresentasikan token
 * 
 * @class     Token Token.h "Token.h"
 * @package   Parser
 * @brief     Kelas abstrak yang digunakan untuk merepresentasikan token
 * @author    Satria Priambada
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */

class Token{
	public:
		virtual EnumType GetType () = 0;//virtual function untuk mendapatkan tipe token
		virtual std::string Display () = 0;//virtual function untuk menampilkan di layar
};

#endif