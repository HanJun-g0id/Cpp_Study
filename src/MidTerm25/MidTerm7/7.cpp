#include "7.h"

List::List() {
	arr = nullptr;
	listMaxSize = 0;
	size = 0;
	created = false;
}

List::~List() {
	if (created) delete[] arr;
}

void List::Create(int listSize, List& list) {
	if (list.created) {
		cout << "리스트가 이미 생성되어 있습니다." << endl;
		return;
	}
	list.arr = new int[listSize];
	list.listMaxSize = listSize;
	list.size = 0;
	list.created = true;
	cout << "리스트가 생성되었습니다." << endl;
}

bool List::IsFull() {
	return size == listMaxSize;
}

bool List::IsEmpty() {
	return size == 0;
}

void List::Insert(int position, int item) {
	if (!created) {
		cout << "리스트가 존재하지 않습니다." << endl;
		return;
	}
	if(IsFull()) {
		cout << "리스트가 가득 찼습니다." << endl;
		return;
	}
	if (position <0 || position > size) {
		cout << "연속되지 않은 위치에 삽입할 수 없습니다." << endl;
		return;
	}
	for (int i = size; i > position; i--) arr[i] = arr[i - 1];
	arr[position] = item;
	size++;
}

void List::Delete(int position) {
	if (!created) {
		cout << "리스트가 존재하지 않습니다." << endl;
		return;
	}
	if (IsFull()) {
		cout << "리스트가 가득 찼습니다." << endl;
		return;
	}
	if (position <0 || position >= size) {
		cout << "연속되지 않은 위치에 삽입할 수 없습니다." << endl;
		return;
	}
	for (int i = position; i < size - 1; i++) arr[i] = arr[i + 1];
	size--;
}

void List::Display() {
	if (!created) {
		cout << "리스트가 존재하지 않습니다." << endl;
		return;
	}
	cout << "리스트 내용 : ";
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
	cout << endl;
}
