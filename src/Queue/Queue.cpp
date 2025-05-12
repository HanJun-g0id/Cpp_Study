#include "Queue.h"

using namespace std;

Queue::Queue(int size) {
    capacity = size;
    arr = new int[capacity];
    front = 0;
    rear = -1;
    count = 0;
}

Queue::~Queue() {
    delete[] arr;
}

void Queue::enqueue(int data) {
    if (isFull()) {
        cout << "Queue is full!\n";
        return;
    }
    rear++;
    arr[rear] = data;
    count++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return -1;
    }
    int result = arr[front];
    front++;
    count--;
    return result;
}

bool Queue::search(int value) const {
    for (int i = front; i <= rear; i++) {
        if (arr[i] == value)
            return true;
    }
    return false;
}

bool Queue::isEmpty() const {
    return (count == 0);
}

bool Queue::isFull() const {
    return (count == capacity);
}

void Queue::display() const {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Queue: ";
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
