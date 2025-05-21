#include <iostream>
int main() {
	int S[7] = { 1,2,2,1,3,1,1 };
	int count[7] = { 0 };
	int C[7] = { 0 };
	int B[7] = { 0 };

	for (int i = 0; i < 7; i++)count[S[i]]++;
	for (int i = 1; i < 7; i++)C[i] = count[i] + C[i - 1];
	for (int i = 6; i >= 0; i--)B[C[S[i]]-- - 1] = S[i];



	return 0;
}
