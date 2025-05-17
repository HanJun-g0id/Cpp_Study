#include "PartitionSort.h"

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int partition(int A[], int first, int last) {
	int low, high, pivotindex, p;
	p = A[last];
	low = first;
	high = last - 1;
	while (low < high) {
		while (p > A[low])low++;
		while (p < A[high])high--;
		if (low <= high) {
			Swap(A[low], A[high]);
			low++;
			high--;
		}
	}
	Swap(A[low], A[last]);
	return (low);
}

void QuickSort(int A[], int First, int Last)
{
	if (First < Last)
	{
		int PivotIndex = partition(A, First, Last);
		QuickSort(A, First, PivotIndex - 1);
		QuickSort(A, PivotIndex + 1, Last);
	}
}
