#include <iostream>
#include "MergeSort.h"
using namespace std;

int main() {
    dataType A[] = { 38, 27, 43, 3, 9, 82, 10 };
    int n = sizeof(A) / sizeof(A[0]);
    int num;

    MergeSort(A, 0, n - 1);
    cout << "몇 번째로 큰 수를 찾을까 : ";
    cin >> num;
    cout << "집합 : ";
    for (int i = 0; i < n; i++) std::cout << A[i] << " ";
    cout << "\n출력 : " << A[n - num];

    return 0;
}
