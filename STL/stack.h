#ifndef _STL_STACK_H_
#define _STL_STACK_H_

#include <cstdlib>
#include <cstdio>

/**
 * Class StackExp
 * 
 * @class     StackExp stack.h "STL/stack.h"
 * @package   STL
 * @brief     Kelas exception spesifik class stack
 * @author    Afrizal Fikri
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */

class StackExp
{
public:
	StackExp(int e) { errCode = e; }
	void printMsg() { printf("Error : %s\n", msg[errCode]); }
	
private:
	char msg[2][32] = {"stack empty", "allocation fail"};
	int errCode;
};

/**
 * Class stack
 * 
 * @class     stack stack.h "STL/stack.h"
 * @package   STL
 * @brief     Kelas stack yang diimplementasi berdasarkan STL C++
 * @author    Afrizal Fikri
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */

template<class T>
class stack 
{
	struct node {
		T info;
		node* next;
	};
	typedef node infotype;

public:
	stack() : Size(0), topElmt(NULL) {}
	stack(const stack& s) : Size(0), topElmt(NULL) {
		T* temp = new T[Size];
		int topTmp = 0;
		infotype* last = s.topElmt;

		while (last != NULL) {
			temp[topTmp++] = last->info;
			last = last->next;
		}

		while (--topTmp >= 0) {
			push(temp[topTmp]);
		}

		delete[] temp;
	}

	stack& operator= (const stack<T>& s) {
		T* temp = new T[Size];
		int topTmp = 0;
		infotype* last = s.topElmt;

		while (!empty()) {
			pop();
		}

		while (last != NULL) {
			temp[topTmp++] = last->info;
			last = last->next;
		}

		while (--topTmp >= 0) {
			push(temp[topTmp]);
		}

		delete[] temp;
		return *this;
	}

	~stack() {
		while (!empty()) {
			pop();
		}
	}

	void pop() {
		if (empty()) throw StackExp(0);

		infotype* next = topElmt->next;
		delete topElmt;
		topElmt = next;
		Size--;
	}

	void push(T e) {
		infotype* last = new infotype;
		if (last == NULL) throw StackExp(1);

		last->info = e;
		last->next = topElmt;
		topElmt = last;
		Size++;
	}

	T top() { 
		if (empty()) throw StackExp(0);
		return topElmt->info; 
	}
	int size() { return Size; }
	bool empty() { return topElmt == NULL; }

private:
	int Size;
	infotype* topElmt;
};

#endif