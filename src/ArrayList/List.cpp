#include "List.h"
using namespace std;

//생성자 정의
List::List() {
	arr = nullptr;
	listMaxSize = 0;
	size = 0;
	created = false;
}

//소멸자 정의
List::~List() {
	if (created) delete[] arr;
}

void List::Append(int item) {
	if (!created) {
		cout << "리스트가 존재하지 않습니다." << endl;
		return;
	}
	if (IsFull()) {
		cout << "리스트가 가득 찼습니다." << endl;
		return;
	}

}

//리스트 생성
void List::Create(int listSize, List& list) {
	if (list.created) {
		cout << "리스트가 이미 생성되어있습니다." << endl;
		return;
	}
	list.arr = new int[listSize];
	list.listMaxSize = listSize;
	list.size = 0;
	list.created = true;
	cout << "리스트가 생성되었습니다." << endl;
}

//리스트 파괴
void List::Destroy(List& list) {
	if (!list.created) {
		cout << "리스트가 존재하지 않습니다." << endl;
		return;
	}
	delete[] list.arr;
	list.created = false;
	list.size = 0;
	cout << "리스트가 삭제되었습니다." << endl;
}

//리스트 요소 추가
void List::Insert(int position, int item) {
	if (!created) {
		cout << "리스트가 존재하지 않습니다." << endl;
		return;
	}
	if (IsFull()) {
		cout << "리스트가 가득 찼습니다." << endl;
		return;
	}
	if (position <0 || position > size) {
		cout << "연속되지 않은 위치에 삽입할 수 없습니다." << endl;
		return;
	}
	for (int i = size; i > position; i--)arr[i] = arr[i - 1];
	arr[position] = item; //위치에 요소값 넣기
	size++; //요소 증가
}

//리스트 요소 삭제
void List::Delete(int position) {
	if (!created) {
		cout << "리스트가 존재하지 않습니다." << endl;
		return;
	}
	if (IsEmpty()) {
		cout << "리스트가 비어있습니다." << endl;
		return;
	}
	if (position <0 || position >= size) {
		cout << "올바르지 않은 위치입니다." << endl;
		return;
	}
	for (int i = position; i < size-1; i++)arr[i] = arr[i + 1]; //위치 요소값 삭제
	size--;//요소 개수 감소
}

//요소 검색
int List::Retrieve(int item) {
	for (int i = 0; i < size; i++) if (arr[i] == item) return i;
	return -1;
}

//리스트가 비어있는지 확인
bool List::IsEmpty() {
	return size == 0;
}

//리스트가 꽉 찼는지 확인
bool List::IsFull() {
	return size == listMaxSize;
}

//리스트 출력
void List::PrintList() {
	if (!created) {
		cout << "오류: 리스트가 존재하지 않습니다." << endl;
		return;
	}
	cout << "리스트 내용: ";
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
	cout << endl;
}
