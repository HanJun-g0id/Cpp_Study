#include <iostream>
#include "FindSum.h"
using namespace std;

int main() {
    int arr[] = { 1,2,3,4,5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int Sum = findSum(arr, 0, size - 1);

    cout << "총합: " << Sum << endl;

    return 0;
}
