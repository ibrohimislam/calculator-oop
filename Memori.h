#ifndef _MEM_H_
#define _MEM_H_ 1

#include "STL/vector.h"
#include "Expression.h"

using namespace std;

class Memori
{
public:
	Memori();
	~Memori();
	// memori bertanggung jawab atas penghapusan token
	void AddExpression(const Expression& E);
	Expression& GetExpression(int i);
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