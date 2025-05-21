#include "CountingSort.h"

void countingSort(int arr[], int size, int maxValue) {
    int* count = new int[maxValue + 1] {0};
    int* output = new int[size];

    for (int i = 0; i < size; i++)
        ++count[arr[i]];

    for (int i = 1; i <= maxValue; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
        output[--count[arr[i]]] = arr[i];

    for (int i = 0; i < size; ++i)
        arr[i] = output[i];
}
