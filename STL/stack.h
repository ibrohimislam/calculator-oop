#ifndef _STL_STACK_H
#define _STL_STACK_H

#include <cstdlib>

template<class T>
class stack 
{
	struct node {
		T info;
		node* next;
	};
	typedef node infotype;

public:
	stack();
	stack(const stack&);
	stack& operator= (const stack&);
	~stack();
	void pop();
	void push(T);
	T top();
	int size();
	bool empty();

private:
	int Size;
	infotype* topElmt;
};

template<class T> stack<T>::stack() : Size(0), topElmt(NULL) {}

template<class T> stack<T>::stack(const stack& s) : Size(0), topElmt(NULL) {
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

template<class T> stack<T>& stack<T>::operator= (const stack<T>& s) {
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

template<class T> stack<T>::~stack() {
	while (!empty()) {
		pop();
	}
}

template<class T> void stack<T>::pop() {
	infotype* next = topElmt->next;
	delete topElmt;
	topElmt = next;
	Size--;
}

template<class T> void stack<T>::push(T e) {
	infotype* last = new infotype;
	last->info = e;
	last->next = topElmt;
	topElmt = last;
	Size++;
}

template<class T> T stack<T>::top() { return topElmt->info; }

template<class T> int stack<T>::size() { return Size; }

template<class T> bool stack<T>::empty() { return topElmt == NULL; }

#endif