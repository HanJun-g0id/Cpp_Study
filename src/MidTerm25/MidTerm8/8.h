#pragma once
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class List {
private:
	Node* head;
	int size;
	bool created;
public:
	List();
	~List();

	void Create(int listSize, List& list);
	void Insert(int position, int item);
	void Delete(int position);
	void Display();
	bool IsEmpty();
	bool IsFull(); //연결리스트에선 항상 false
};
