#include <iostream>
#include "BST.h"
using namespace std;

int main()
{
    Nptr BT = NULL;
    int S[10] = {6, 4, 8, 3, 5, 7, 9, 1, 2, 10};

    BT = Create(S);
    cout << "전위 순회" << endl;
    PreOrder(BT);
    cout << endl;

    cout << "중위 순회" << endl;
    InOrder(BT);
    cout << endl;

    cout << "후위 순회" << endl;
    PostOrder(BT);
    cout << endl;

    Delete(BT, 10);
    cout << "10 삭제" << endl;
    cout << "전위 순회" << endl;
    PreOrder(BT);
    cout << endl;

    Delete(BT, 9);
    cout << "9 삭제" << endl;
    cout << "전위 순회" << endl;
    PreOrder(BT);
    cout << endl;

    Delete(BT, 5);
    cout << "5 삭제" << endl;
    cout << "전위 순회" << endl;
    PreOrder(BT);
    cout << endl;

    return 0;
}
