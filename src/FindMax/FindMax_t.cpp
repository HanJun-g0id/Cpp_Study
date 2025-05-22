#include <iostream>
#include "FindMax.h"
using namespace std;

int main() {
    int arr[] = { 5,1,9,3,7 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxVal = findMax(arr, 0, size - 1);

    cout << "최댓값: " << maxVal << endl;

    return 0;
}
