#include <iostream>

class List {
private:
	int* arr; //동적 배경
	int listMaxSize; //리스트 최대 크기
	int size; //현재 요소 개수
	bool created; //리스트 생성 여부
public:
    List();
    ~List();

    void Create(int listSize, List &list);
    void Destroy(List &list);
    void Insert(int position, int item);
    void Delete(int position);
    int Retrieve(int item);
    bool IsEmpty();
    bool IsFull();
    void PrintList();

    void Append(int item);
    void Pop();
    void Reverse();
    void Clear();
    void len();

    void sort();
    void extend();
    void copy();
    void sorted();
};
