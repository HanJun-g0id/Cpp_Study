#include "List.h"

int main() {

	List S;

	S.Create(100, S); //리스트 생성
	S.Insert(0, 23); //0번에 23이라는 값 추가
	S.PrintList();
	S.Delete(0); // 0번 요소 삭제
	S.PrintList();
	S.Destroy(S); //리스트 삭제

	S.Create(100, S);
	S.Create(100, S); //중복 생성 방지 테스트

	S.Insert(2, 20); //이격된 위치에 삽입 불가 테스트

	return 0;
}
