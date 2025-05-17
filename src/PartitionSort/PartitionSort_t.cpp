#include <iostream>
#include "PartitionSort.h"
using namespace std;

int main() {
    int A[] = { 38, 27, 43, 3, 9, 82, 10 };
    int n = sizeof(A) / sizeof(A[0]);
    int num;

    QuickSort(A, 0, n - 1);
    cout << "집합 : ";
    for (int i = 0; i < n; i++) std::cout << A[i] << " ";

    return 0;
}
