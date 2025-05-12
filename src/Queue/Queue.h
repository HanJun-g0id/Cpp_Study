#pragma once
#include <iostream>

class Queue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int size = 100);
    ~Queue();

    void enqueue(int data);
    int dequeue();
    bool search(int value) const;
    bool isEmpty() const;
    bool isFull() const;
    void display() const;
};
