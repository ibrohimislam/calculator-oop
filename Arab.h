#ifndef _ARAB_H_
#define _ARAB_H_

#include "Token.h"
#include "Bilangan.h"
#include <string.h>

class Arab: public Bilangan{
	public:
		//ctor
		Arab();
		Arab(const std::string& s);
		//dtor
		~Arab(){}
		//cctor dan operator= tidak pernah dipakai karena tidak mungkin instansiasi
		double GetValue();
<<<<<<< HEAD
		void Display();

=======
		std::string Display();
>>>>>>> origin/master
	private:
		double Value;
};

#endif
