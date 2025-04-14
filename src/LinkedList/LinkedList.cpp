#include <iostream>
#include "LinkedList.h"
using namespace std;

//생성자
LinkedList::LinkedList() {
    head = nullptr; //리스트의 처음 노드를 가리키는 포인터를 null로 초기화 (빈 리스트 상태)
    size = 0; //리스트에 있는 노드의 개수를 0으로 초기화
}

//소멸자
LinkedList::~LinkedList() {
    Node* current = head; //현재 노드를 head부터 시작
    while (current) { //current가 nullptr가 될 때까지 반복 (리스트 끝까지)
        Node* next = current->next; //현재 노드의 다음 노드를 임시로 저장
        delete current; //현재 노드를 메모리에서 해제
        current = next; //다음 노드로 이동
    }
}

//특정 위치에 삽입하는 함수
void LinkedList::Insert(int position, int item) {
    //잘못된 위치 입력 시 경고 메시지 출력
    if (position < 0 || position > size)
        cout << "위치가 올바르지 않습니다" << endl;

    //새로운 노드를 생성하고, item 값을 저장
    Node* newNode = new Node(item);

    if (position == 0) { //맨 앞에 삽입하는 경우
        newNode->next = head; //새 노드가 기존 head를 가리키도록 설정
        head = newNode; //head를 새 노드로 변경
    }
    else {
        Node* current = head;
     
        for (int i = 0; i < position - 1; ++i) current = current->next;
        //삽입하고자 하는 위치의 바로 앞 노드까지 이동

        //새 노드가 현재 노드의 다음 노드를 가리키도록 설정
        newNode->next = current->next;
        //현재 노드의 다음을 새 노드로 변경
        current->next = newNode;
    }

    size++; //리스트 크기 1 증가
}

//특정 위치의 요소를 제거하는 함수
void LinkedList::Delete(int position) {
    //리스트가 비어있는지 여부 판단
    if (IsEmpty())
        cout << "리스트가 비어있습니다" << endl;

    //잘못된 위치 입력 시 경고 메시지 출력
    if (position < 0 || position >= size)
        cout << "위치가 올바르지 않습니다" << endl;

    Node* temp; //메모리 관리용

    if (position == 0) { //맨 앞 노드를 삭제하는 경우
        temp = head; //삭제할 노드를 temp에 저장
        head = head->next; //head를 다음 노드로 변경
    }
    else {
        Node* current = head;
       
        for (int i = 0; i < position - 1; ++i) current = current->next;
        //삭제할 노드의 바로 전 노드까지 이동

        temp = current->next; //삭제할 노드를 temp에 저장
        current->next = temp->next; //삭제할 노드를 리스트에서 분리
    }

    delete temp; //삭제할 노드를 메모리에서 해제
    size--; //리스트 크기 감소
}

//특정 수를 찾아내는 함수
int LinkedList::Retrieve(int item) const {
    Node* current = head;
    int index = 0;

    while (current) {
        if (current->data == item)
            return index;
        current = current->next;
        index++;
    }

    return -1; //못 찾을 경우
}

//비어있는지 여부
bool LinkedList::IsEmpty() const {
    return size == 0;
}

//가득 차 있는지 여부 -> 사실상 필요없음
bool LinkedList::IsFull() const {
    return false; //동적 할당이므로 항상 false
}

//출력용 함수
void LinkedList::Print() const {
    Node* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}
