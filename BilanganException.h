#ifndef _BILANGANEXCEPTION_H_
#define _BILANGANEXCEPTION_H_

#include <string>

/**
 * Class BilanganException
 * 
 * @class     BilanganException BilanganException.h "BilanganException.h"
 * @package   Token
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
	//ctor
	BilanganException(){
		MsgBilanganExp = "";
	}
	BilanganException(const std::string& s){
		MsgBilanganExp = s;
	}
	//dtor
	~BilanganException(){}

	//tidak memerlukan opr= dan cctor
	void DisplayMsg(){
		std::cout << MsgBilanganExp<<std::endl;
	}
private:
	std::string MsgBilanganExp; 
};

#endif
