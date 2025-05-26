#define MAX_SIZE 100

class PriorityQueue {
public:
    int arr[MAX_SIZE];
    int count;
    PriorityQueue();
    void push(int value);
    void pop();
    int top();
    bool empty();
};
