#ifndef _STL_STACK_H
#define _STL_STACK_H 1

#include <cstdlib>

template<class T>
class stack {
	struct node {
		T info;
		node* next;
	};
	typedef node infotype;

public :
	stack();
	stack(const stack&);
	stack& operator= (const stack&);
	~stack();
	void pop();
	void push(T);
	T top();
	int size();
	bool empty();

private :
	int Size;
	infotype* topElmt;
};

#endif