#ifndef _STL_STACK_H_
#define _STL_STACK_H_

#include <cstdlib>
#include <cstdio>

/**
 * Class StackExp
 * 
 * Kelas exception spesifik class stack
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
 * Kelas stack yang diimplementasi berdasarkan STL C++
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
	/**
	 * Constructor default
	 *
	 * Konstruktor yang digunakan untuk membuat Objek stack
	 *
	 */

	stack() : Size(0), topElmt(NULL) {}

	/**
	 * Copy Constructor
	 *
	 * Konstruktor yang digunakan untuk membuat objek stack salinan dari objek stack
	 *
	 */

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

	/**
	 * Operator assignment
	 *
	 * Fungsi yang digunakan untuk menyalin objek stack dari objek stack
	 *
	 */

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

	/**
	 * Destructor
	 *
	 * @param none
	 */
	~stack() {
		while (!empty()) {
			pop();
		}
	}

	/**
	 * Prosedur Pop
	 *
	 * Prosedur yang digunakan untuk mengeluarkan elemen teratas dari stack.
	 *
	 * @param none
	 * @pre stack tidak kosong 
	 * @post elemen teratas dikeluarkan dari stack
	 *
	 */

	void pop() {
		if (empty()) throw StackExp(0);

		infotype* next = topElmt->next;
		delete topElmt;
		topElmt = next;
		Size--;
	}

	/**
	 * Prosedur Push
	 *
	 * Prosedur yang digunakan untuk menambahkan elemen ke elemen teratas stack.
	 *
	 * @param T e
	 * @pre stack tidak penuh 
	 * @post e ditambahkan sebagai elemen teratas stack
	 *
	 */

	void push(T e) {
		infotype* last = new infotype;
		if (last == NULL) throw StackExp(1);

		last->info = e;
		last->next = topElmt;
		topElmt = last;
		Size++;
	}

	/**
	 * Fungsi Top
	 *
	 * Fungsi yang digunakan untuk mengembalikan elemen teratas stack.
	 *
	 * @param none
	 * @pre stack tidak kosong 
	 * @return T
	 *
	 */

	T top() { 
		if (empty()) throw StackExp(0);
		return topElmt->info; 
	}

	/**
	 * Fungsi Size
	 *
	 * Fungsi yang digunakan untuk mengembalikan ukuran stack.
	 *
	 * @param none
	 * @return integer
	 *
	 */

	int size() { return Size; }

	/**
	 * Fungsi Empty
	 *
	 * Fungsi yang digunakan untuk mengembalikan apakah stack kosong.
	 *
	 * @param none
	 * @return bool
	 *
	 */
	 
	bool empty() { return topElmt == NULL; }

private:
	int Size;
	infotype* topElmt;
};

#endif