#include "6.h"

// 리스트 구조체 초기화
void List_Init(List* list) {
    list->arr = NULL;
    list->listMaxSize = 0;
    list->size = 0;
    list->created = 0;
}

// 리스트 생성
void List_Create(List* list, int maxSize) {
    if (list->created) {
        printf("리스트가 이미 생성되어 있습니다.\n");
        return;
    }
    list->arr = (int*)malloc(sizeof(int) * maxSize);
    list->listMaxSize = maxSize;
    list->size = 0;
    list->created = 1;
    printf("리스트가 생성되었습니다.\n");
}

// 요소 삽입
void List_Insert(List* list, int pos, int item) {
    if (!list->created) {
        printf("리스트가 존재하지 않습니다.\n");
        return;
    }
    if (List_IsFull(list)) {
        printf("리스트가 가득 찼습니다.\n");
        return;
    }
    if (pos < 0 || pos > list->size) {
        printf("연속되지 않은 위치에 삽입할 수 없습니다.\n");
        return;
    }
    for (int i = list->size; i > pos; i--)
        list->arr[i] = list->arr[i - 1];
    list->arr[pos] = item;
    list->size++;
}

// 리스트 비어있는지 여부
int List_IsEmpty(List* list) {
    return list->size == 0;
}

// 리스트 가득 차 있는지 여부
int List_IsFull(List* list) {
    return list->size == list->listMaxSize;
}

// 맨 끝에 요소 추가
void List_Append(List* list, int item) {
    if (!list->created) {
        printf("리스트가 존재하지 않습니다.\n");
        return;
    }
    if (List_IsFull(list)) {
        printf("리스트가 가득 찼습니다.\n");
        return;
    }
    list->arr[list->size++] = item;
}

// 리스트 출력
void List_Print(List* list) {
    if (!list->created) {
        printf("오류: 리스트가 존재하지 않습니다.\n");
        return;
    }
    printf("리스트 내용: ");
    for (int i = 0; i < list->size; i++)
        printf("%d ", list->arr[i]);
    printf("\n");
}

// 리스트 디스플레이 함수 (List_Print와 동일하지만 별도 이름)
void List_Display(List* list) {
    if (!list->created) {
        printf("오류: 리스트가 존재하지 않습니다.\n");
        return;
    }
    printf("디스플레이: ");
    for (int i = 0; i < list->size; i++)
        printf("%d ", list->arr[i]);
    printf("\n");
}
//List_Display()는 List_Print()와 거의 같은 기능을 수행하지만, 
//함수 이름만 다르게 하여 출력 표현을 명확히 분리할 수 있게 함.
//향후 Print와 Display의 기능을 분리하고 싶을 때도 유연하게 대처 가능.
