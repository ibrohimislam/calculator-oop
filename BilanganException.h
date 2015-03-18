#ifndef _BILANGANEXCEPTION_H_
#define _BILANGANEXCEPTION_H_
#include <string>

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
