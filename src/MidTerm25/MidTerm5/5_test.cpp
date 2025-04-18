#include "5.h"

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
    List_Print(&S);
    
    List_Insert(&S, 3, 8);
    printf("삽입 후 ");
    List_Print(&S);

    return 0;
}
