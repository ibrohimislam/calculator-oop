#include "vector.h"
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <cstdio>

using namespace std;

#define _RANDOM_(min, mod) (rand()%mod+min)

int main() {
	vector<int> a[100];

	int size[100];
	int arr[100][10000];

	srand (time(NULL));

	for (int i = 0; i < 100; ++i)
		size[i] = 0;

	for (int i = 0; i < 10000; ++i)
	{
		int idx = _RANDOM_(0,100);
		int elm = _RANDOM_(0,100); 
		a[idx].push_back(elm);

		// add to tester
		arr[idx][size[idx]] = elm;
		size[idx]++;
	}

	for (int i = 0; i < 100; ++i)
		assert(size[i]==a[i].size());

	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < size[i]; ++j)
			assert(arr[i][j] == a[i][j]);

	printf("tes sukses\n");

}