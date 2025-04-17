#include "2.h"
#include <algorithm>

Rank::Rank() {
	cout << "입력 : ";
	for (int i = 0; i < 10; i++) { cout << A[i] << " "; }
	cout << endl;
	cout << "총점 : ";
	for (int i = 0; i < 10; i++) { cout << A[i] << " "; }
	cout << endl;
}

void Rank::print() {
	cout << "석차 : ";
	for (int i = 0; i < 10; i++) {
		int rank = 1;
		for (int j = 0; j < 10; j++) {
			if (A[i] < A[j]) rank++; //이렇게해야 중복 등수 처리 가능
		}
		cout << rank << " ";
	}
	cout << endl;
}
