#include "FindSum.h"

int findSum(int arr[], int left, int right) {
    if (left == right) {
        return arr[left];
    }

    if (right - left == 1) return arr[right] + arr[left];

    int mid = (left + right) / 2;

    int Left = findSum(arr, left, mid);
    int Right = findSum(arr, mid + 1, right);

    return Left + Right;
}
