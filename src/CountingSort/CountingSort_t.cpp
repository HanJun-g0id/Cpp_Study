#include "CountingSort.h"
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 1, 3, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int maxValue = 3;

    cout << "정렬 전: ";
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << endl;

    countingSort(arr, size, maxValue);

    cout << "정렬 후: ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
