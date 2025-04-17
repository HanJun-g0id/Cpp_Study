#include "4.h"

using namespace std;

Sum_Matrix::Sum_Matrix() : N(3), M(4), total(0) {
	cout << "배열의 값 :" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << A[i][j] << " ";
		}
		Sum_row(i);
	}
	for (int k = 0; k < M; k++) {
		Sum_col(k);
	}
	cout << total;
}

void Sum_Matrix::Sum_col(int b) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i][b]; //배열 내부의 수를 다 더함
	}
	cout << sum << " ";
}

void Sum_Matrix::Sum_row(int a) {
	int sum = 0;
	for (int i = 0; i < M; i++) {
		sum += A[a][i]; //배열 내부의 수를 다 더함
	}
	total += sum;
	cout << sum << endl;
}
