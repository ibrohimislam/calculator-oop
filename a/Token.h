#ifndef _TOKEN_H_
#define _TOKEN_H_

#include "Enum.h"
#include <string>

class Token{
	public:
		virtual EnumType GetType () = 0;
		virtual std::string Display () = 0;
};

#endif