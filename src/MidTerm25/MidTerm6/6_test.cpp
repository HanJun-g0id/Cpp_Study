#include "6.h"

int main() {
    List S;
    List_Init(&S); // 구조체 초기화

    List_Create(&S, 100); // 리스트 생성
    List_Append(&S, 1);
    List_Append(&S, 4);
    List_Append(&S, 7);
    List_Append(&S, 9);
    List_Append(&S, 12);

    printf("기존 ");
    List_Display(&S);  // 기존 Print 대신 Display 사용

    List_Insert(&S, 3, 8); // 7과 9 사이에 8 삽입

    printf("삽입 후 ");
    List_Display(&S);  // 변경된 리스트 출력

    return 0;
}
