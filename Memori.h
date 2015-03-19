#ifndef _MEM_H_
#define _MEM_H_ 1

#include "STL/vector.h"
#include "Expression.h"

using namespace std;

/**
 * @package   Memori
 * @brief     Kelas yang digunakan untuk menyimpan list ekspresi,
 *            merupakan pembungkusan vector of ekspression.
 * @author    Ibrohim Kholilul Islam
 * @version   0.1
 * @date      Maret 2015
 * @warning   Pada destructor, semua token yang terdapat pada ekspresi dihapus.
 * 
 */

class Memori
{
public:
	//ctor
	Memori();/*default constructor*/
	//dtor
	~Memori();
	// memori bertanggung jawab atas penghapusan token
	//tidak diperlukan cctor dan opr= karena tidak pernah ada assignmen memori
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