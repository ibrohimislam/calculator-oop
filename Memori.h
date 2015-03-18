#ifndef _MEM_H_
#define _MEM_H_ 1

#include "vector.h"
#include "Expression.h"

using namespace std;

class Memori
{
public:
	Memori();
	~Memori();
	void AddExpression(const Expression& E);
	Expression& GetExpression(int);
	vector<Expression>& GetAllExpression();
	int GetLength();
	bool Undo(int n);
	Expression& Redo();
	void Save();
	void ShowMem(int n);
	void ShowAll();
private:
	vector<Expression> VectorOfExpression;
	int head;
	int length;
};

#endif