// main.c
#include <stdio.h>
#include "LinkedStruct.h"

int main() {
    List S;
    List_Init(&S); // 구조체 초기화

    List_Create(&S, 100); // 리스트 생성
    List_Insert(&S, 0, 23); // 0번 위치에 23 삽입
    List_Print(&S);

    List_Delete(&S, 0); // 0번 요소 삭제
    List_Print(&S);

    List_Destroy(&S); // 리스트 삭제

    List_Create(&S, 100); // 리스트 다시 생성
    List_Create(&S, 100); // 중복 생성 방지 테스트

    List_Insert(&S, 2, 20); // 이격된 위치 삽입 방지 테스트

    return 0;
}
