#include "Transducer.h"

void Init(Nptr* Top) {
    *Top = NULL;
}

bool IsEmpty(Nptr Top) {
    return Top == NULL;
}

void Push(Nptr* Top, int Item) {
    Nptr Temp = (Nptr)malloc(sizeof(node));
    Temp->Item = Item;
    Temp->Next = *Top;
    *Top = Temp;
}

int Pop(Nptr* Top) {
    if (*Top == NULL) {
        printf("스택이 비어있습니다.\n");
        return -1;
    }
    else {
        Nptr Temp = *Top;
        int Item = Temp->Item;
        *Top = Temp->Next;
        free(Temp);
        return Item;
    }
}

void FreeList(Nptr* Top) {
    Nptr Temp;
    while (*Top != NULL) {
        Temp = *Top;
        *Top = (*Top)->Next;
        free(Temp);
    }
}

void PrintStack(Nptr Top) {
    printf("현재 스택 : ");
    if (IsEmpty(Top)) {
        printf("스택이 비어 있습니다.\n");
        return;
    }

    Nptr temp = Top;
    while (temp != NULL) {
        printf("%d ", temp->Item);
        temp = temp->Next;
    }
    printf("\n");
}

//10진수 > 2진수 변환기
void Calculator(Nptr* Top, int input) {
    if (input == 0) Push(Top, 0);

    while (input > 0) {
        Push(Top, input % 2);
        input /= 2;
    }
}
