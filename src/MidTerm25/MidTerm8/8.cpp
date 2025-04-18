#include "8.h"

List::List() {
	head = nullptr;
	size = 0;
	created = false;
}

List::~List() {
	if (created) {
		Node* current = head;
		while (current) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}
}

void List::Create(int listSize, List& list) {
	if (list.created) {
		cout << "리스트가 이미 생성되어 있습니다." << endl;
		return;
	}
	list.head = nullptr;
	list.size = 0;
	list.created = true;
	cout << "리스트가 생성되었습니다." << endl;
}

bool List::IsFull() {
	return false;
}

bool List::IsEmpty() {
	return size == 0;
}

void List::Insert(int position, int item) {
	if (!created) {
		cout << "리스트가 존재하지 않습니다." << endl;
		return;
	}
	if (position <0 || position > size) {
		cout << "연속되지 않은 위치에 삽입할 수 없습니다." << endl;
		return;
	}
	Node* newNode = new Node{ item, nullptr };

	if (position == 0) {
		newNode->next = head;
		head = newNode;
	}
	else {
		Node* prev = head;
		for (int i = 0; i < position - 1; i++) prev = prev->next;
		newNode->next = prev->next;
		prev->next = newNode;
	}

	size++;
}

void List::Delete(int position) {
	if (!created) {
		cout << "리스트가 존재하지 않습니다." << endl;
		return;
	}
	if (IsEmpty()) {
		cout << "리스트가 비어있습니다." << endl;
		return;
	}
	if (position < 0 || position >= size) {
		cout << "연속되지 않은 위치에 삽입할 수 없습니다." << endl;
		return;
	}

	Node* toDelete;

	if (position == 0) {
		toDelete = head;
		head = head->next;
	}
	else {
		Node* prev = head;
		for (int i = 0; i < position - 1; i++) prev = prev->next;
		toDelete = prev->next;
		prev->next = toDelete->next;
	}

	delete toDelete;
	size--;
}

void List::Display() {
	if (!created) {
		cout << "리스트가 존재하지 않습니다." << endl;
		return;
	}
	cout << "리스트 내용 : ";
	Node* current = head;
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
