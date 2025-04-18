#pragma once
#include <iostream>
using namespace std;

class List {
private:
	int* arr;
	int listMaxSize;
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
	bool IsFull();
};
