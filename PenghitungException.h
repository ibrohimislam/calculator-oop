#ifndef _PENGHITUNGEXCEPTION_H_
#define _PENGHITUNGEXCEPTION_H_

#include <string>
#include <iostream>

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