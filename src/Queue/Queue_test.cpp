#include "Queue.h"

using namespace std;

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    cout << "Search 20: " << (q.search(20) ? "Found" : "Not Found") << endl;
    cout << "Search 50: " << (q.search(50) ? "Found" : "Not Found") << endl;

    return 0;
}
