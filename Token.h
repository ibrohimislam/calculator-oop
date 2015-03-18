#ifndef _TOKEN_H_
#define _TOKEN_H_

#include "Enum.h"

class Token{
	public:
		virtual EnumType GetType () = 0;
		virtual void Display () = 0;
};

#endif