// List.c
#include <stdio.h>
#include <stdlib.h>
#include "LinkedStruct.h"

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

// 리스트 파괴
void List_Destroy(List* list) {
    if (!list->created) {
        printf("리스트가 존재하지 않습니다.\n");
        return;
    }
    free(list->arr);
    list->arr = NULL;
    list->listMaxSize = 0;
    list->size = 0;
    list->created = 0;
    printf("리스트가 삭제되었습니다.\n");
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

// 요소 삭제
void List_Delete(List* list, int pos) {
    if (!list->created) {
        printf("리스트가 존재하지 않습니다.\n");
        return;
    }
    if (List_IsEmpty(list)) {
        printf("리스트가 비어있습니다.\n");
        return;
    }
    if (pos < 0 || pos >= list->size) {
        printf("올바르지 않은 위치입니다.\n");
        return;
    }
    for (int i = pos; i < list->size - 1; i++)
        list->arr[i] = list->arr[i + 1];
    list->size--;
}

// 요소 탐색
int List_Retrieve(List* list, int item) {
    for (int i = 0; i < list->size; i++) {
        if (list->arr[i] == item) return i;
    }
    return -1;
}

int List_IsEmpty(List* list) {
    return list->size == 0;
}

int List_IsFull(List* list) {
    return list->size == list->listMaxSize;
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

// (아직 구현되지 않은 함수들 – 템플릿 형태)
void List_Append(List* list, int item) {}
void List_Pop(List* list) {}
void List_Reverse(List* list) {}
void List_Clear(List* list) {}
void List_Len(List* list) {}
void List_Sort(List* list) {}
void List_Extend(List* list) {}
void List_Copy(List* list) {}
void List_Sorted(List* list) {}
