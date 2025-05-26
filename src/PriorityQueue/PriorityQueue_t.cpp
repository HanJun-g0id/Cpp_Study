#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main() {
    cout << "우선순위 큐 구현 : 우선순위 = 크기" << endl;
    PriorityQueue pq;
    pq.push(7);
    pq.push(2);
    pq.push(10);
    pq.push(5);

    cout << "현재 큐: ";
    for (int i = 0; i < pq.count; i++) cout << pq.arr[i] << " ";
    cout << endl;

    while (!pq.empty()) {
        cout << "최댓값(top): " << pq.top() << endl;
        pq.pop();
        cout << "pop 후 큐: ";
        for (int i = 0; i < pq.count; i++) cout << pq.arr[i] << " ";
        cout << endl;
    }
    return 0;
}
