#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList list;

    list.Insert(0, 10);  //맨 앞 추가
    list.Insert(1, 20);  //맨 끝 추가
    list.Insert(1, 15);  //중간 추가

    list.Print();  // 10 -> 15 -> 20 -> NULL

    cout << "15의 위치: " << list.Retrieve(15) << endl; // 1

    list.Delete(1); //중간 삭제
    list.Print();   //10 -> 20 -> NULL

    list.Delete(0); //맨 앞 삭제
    list.Print();

    list.Insert(0, 23);//맨 앞 추가
    list.Print();

    list.Delete(1); //맨 뒤 삭제
    list.Print();

    //만든김에 만든 비어있는지 여부 출력 -> 무조건 No가 나와야 함
    cout << "IsEmpty? " << (list.IsEmpty() ? "Yes" : "No") << endl;

    return 0;
}
