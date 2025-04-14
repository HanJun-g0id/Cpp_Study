#pragma once
class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}//초기화용
    };

    Node* head;
    int size; 

public:
    LinkedList(); //생성자
    ~LinkedList(); //소멸자
    void Insert(int position, int item); //요소추가
    void Delete(int position); //요소삭제
    int Retrieve(int item) const; //요소검색

    bool IsEmpty() const; //비어있어?
    bool IsFull() const; //가득찼어?

    void Print() const; //출력용
};
