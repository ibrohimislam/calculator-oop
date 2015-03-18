#include "Token.h"
#include "Bilangan.h"
#include "Romawi.h"
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <cstring>


void Romawi:: Display(){
	int val = Value;
	char* hasil = (char*) malloc(1000);
	char* res = hasil;
	size_t sz;

	char* MatrixRomawi[6][10] = {
		{(char*)"", (char*)"c", (char*)"cc", (char*)"ccc", (char*)"cd", (char*)"d", (char*)"dc", (char*)"dcc", (char*)"dccc", (char*)"cm"},
		{(char*)"", (char*)"x", (char*)"xx", (char*)"xxx", (char*)"xv", (char*)"v", (char*)"vx", (char*)"vxx", (char*)"vxxx", (char*)"xc"},
		{(char*)"", (char*)"M", (char*)"MM", (char*)"MMM", (char*)"Mv", (char*)"v", (char*)"vM", (char*)"vMM", (char*)"vMMM", (char*)"Mx"},
		{(char*)"", (char*)"C", (char*)"CC", (char*)"CCC", (char*)"CD", (char*)"D", (char*)"DC", (char*)"DCC", (char*)"DCCC", (char*)"CM"},
		{(char*)"", (char*)"X", (char*)"XX", (char*)"XXX", (char*)"XL", (char*)"L", (char*)"LX", (char*)"LXX", (char*)"LXXX", (char*)"XC"},
		{(char*)"", (char*)"I", (char*)"II", (char*)"III", (char*)"IV", (char*)"V", (char*)"VI", (char*)"VII", (char*)"VIII", (char*)"IX"}
	};

   int size[] = { 0, 1, 2, 3, 2,  1,  2,  3,  4, 2};

    // tambah M hingga dibawah 1000

    while (val >= 1000000) {
	    if (sz-- < 1){
        	break;
        }else{
        	*res++ = 'm';
        	val -= 1000;
    	}
    }

     // Add each of the correct elements, adjusting as we go.
    int pembagi = 100;
    for (int i = 0; i < 3; i++){
    	assert(sz >= size[val/pembagi]);
	    sz -= size[val/pembagi];
	    strcpy(res, MatrixRomawi[i][val/pembagi]);
	    res += size[val/pembagi];
	    val = val % pembagi;
	    pembagi /= 10;
    }

    // Finish string off.

    assert (sz >= 1);
    *res = '\0';

    std::cout << hasil;
}

Romawi::Romawi(){
  Value = 1;
}

Romawi::Romawi(const std::string& s){
  int rom_to_int[255];
  memset(rom_to_int, 0, sizeof(rom_to_int));

  rom_to_int['I'] = 1;
  rom_to_int['V'] = 5;
  rom_to_int['X'] = 10;
  rom_to_int['L'] = 50;
  rom_to_int['C'] = 100;
  rom_to_int['D'] = 500;
  rom_to_int['M'] = 1000;
  rom_to_int['v'] = 5000;
  rom_to_int['x'] = 10000;
  rom_to_int['l'] = 50000;
  rom_to_int['c'] = 100000;
  rom_to_int['d'] = 500000;
  rom_to_int['m'] = 1000000;

  int sum=0; char prev='%';
  for(int i=(s.length()-1); i>=0; i--)
  {
  	assert(rom_to_int[s[i]]);

    if(rom_to_int[s[i]]<sum && (s[i]!=prev))
    {       sum -= rom_to_int[s[i]];
            prev = s[i];
    }
    else
    {
            sum += rom_to_int[s[i]];
            prev = s[i];
    }
  }

  Value = sum;
}

long double Romawi:: GetValue(){
	return Value;
}
