#include "stack.h"
#include <cstdio>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define _RANDOM_(min, mod) (rand()%mod+min)

int main() {
	stack<int> a;
	int asli[100000];
	int head = 0;

	srand(time(NULL));

	for (int i = 0; i < 1000; ++i)
	{
		int x = _RANDOM_(0, 1000);
		a.push(x);
		asli[head++] = x;
	}

	for (int i = 0; i < 10000; ++i)
	{
		if (_RANDOM_(0,2))
		{
			int x = _RANDOM_(0, 1000);
			a.push(x);
			asli[head++] = x;
		}
		else
		{
			int x = a.top();
			assert(x==asli[head-1]);
			a.pop();
			head--;
		}
	}

	printf("tes sukses\n");

}