#include "Power.h"

int Pow(int base, int exp) {
	if (exp == 0) return 1;
	if (exp == 1)return base;

	int half = Pow(base, exp / 2);

	if (exp % 2 == 0) return half * half;
	else return half * half * base;
}
