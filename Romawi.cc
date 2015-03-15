#include "Token.h"
#include "Bilangan.h"
#include "Romawi.h"

EnumType Romawi:: GetType(){
	return Bilangan;
}

void Romawi:: Display(){
	int val = Value;
	char* hasil = (char*) malloc(1000);
	char* res = hasil;
	size_t sz;

	char* MatrixRomawi[3][10] = {
		{"", "c", "cc", "ccc", "cd", "d", "dc", "dcc", "dccc", "cm"},
		{"", "x", "xx", "xxx", "xv", "v", "vx", "vxx", "vxxx", "xc"},
		{"", "M", "MM", "MMM", "Mv", "v", "vM", "vMM", "vMMM", "Mx"},
		{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
		{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
		{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
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
    	if (sz < size[val/pembagi]) return 0;
	    sz -= size[val/pembagi];
	    strcpy (res, MatrixRomawi[i][val/pembagi]);
	    res += size[val/pembagi];
	    val = val % pembagi;
	    pembagi /= 10;
    }

    // Finish string off.

    if (sz < 1) return 0;
    *res = '\0';

    cout << hasil;
}

void Romawi:: Display(EnumBilangan T){
	cout << Value;
}

Romawi:: Romawi(){
	Value = 1;
}

Romawi:: Romawi(const string& s){
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

int Romawi:: GetValue(){
	return Value;
}
