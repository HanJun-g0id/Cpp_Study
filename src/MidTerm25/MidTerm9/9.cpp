#include "9.h"

reused::reused() {
	cout << "Factorial(" << N << ")------>"<<Factorial(N)<< endl;
}
int reused::Factorial(int num) {
	if (num == 1)
		return 1;
	else
		return num * Factorial(num - 1);
}
