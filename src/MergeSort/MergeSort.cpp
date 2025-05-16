#include "MergeSort.h"

void Merge(dataType A[], int F, int Mid, int L) {
    dataType Temp[MAX];
    int First1 = F, Last1 = Mid;
    int First2 = Mid + 1, Last2 = L;
    int Index = First1;

    while (First1 <= Last1 && First2 <= Last2) {
        Temp[Index++] = (A[First1] < A[First2]) ?
            A[First1++] : A[First2++];
    }

    while (First1 <= Last1) Temp[Index++] = A[First1++];
    while (First2 <= Last2) Temp[Index++] = A[First2++];

    for (Index = F; Index <= L; Index++) {
        A[Index] = Temp[Index];
    }
}

void MergeSort(dataType A[], int First, int Last) {
    if (First < Last) {
        int Middle = (First + Last) / 2;
        MergeSort(A, First, Middle);
        MergeSort(A, Middle + 1, Last);
        Merge(A, First, Middle, Last);
    }
}
