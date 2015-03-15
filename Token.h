#include "Enum.h"
#ifndef _TOKEN_H_
#define _TOKEN_H_

class Token{
	public:
		virtual EnumType GetType () = 0;
		virtual Display () = 0;
};

#endif