#include <stdio.h>
#include <stdlib.h>

// 리스트 구조체 정의
typedef struct {
    int* arr;          // 동적 배열
    int listMaxSize;   // 최대 크기
    int size;          // 현재 크기
    int created;       // 생성 여부 (bool 대신 int)
} List;

// 함수 선언
void List_Init(List* list);
void List_Create(List* list, int maxSize);
void List_Insert(List* list, int pos, int item);
void List_Print(List* list);
void List_Append(List* list, int item);
int  List_IsEmpty(List* list);
int  List_IsFull(List* list);
// 함수 선언 추가
void List_Display(List* list); // 디스플레이 함수 (List_Print와 동일 기능)
