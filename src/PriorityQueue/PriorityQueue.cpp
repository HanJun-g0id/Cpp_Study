#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {
    count = 0;
}

void PriorityQueue::push(int value) {
    if (count < MAX_SIZE) {
        arr[count] = value;
        count++;
    }
}

void PriorityQueue::pop() {
    if (count == 0) return;
    int maxIdx = 0;
    for (int i = 1; i < count; i++) {
        if (arr[i] > arr[maxIdx]) maxIdx = i;
    }
    arr[maxIdx] = arr[count - 1];
    count--;
}

int PriorityQueue::top() {
    if (count == 0) return -1;
    int maxIdx = 0;
    for (int i = 1; i < count; i++) {
        if (arr[i] > arr[maxIdx]) maxIdx = i;
    }
    return arr[maxIdx];
}

bool PriorityQueue::empty() {
    return count == 0;
}
