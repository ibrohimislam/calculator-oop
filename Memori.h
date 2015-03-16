#ifndef _MEM_H_
#define _MEM_H_ 1

//#include "vector.h"
//#include "Expression.h"
#include <vector>

using namespace std;

class Memori
{
public:
	Memori();
	~Memori();
	Expression GetExpression(int);
	Expression GetAllExpression();
	int GetLength();
	void Undo();
	void Redo();
	void Save();
	void ShowMem();
	void ShowAll();
	
private:
	vector<Expression> VectorOfExpression;
};

#endif