#include "ReverseStack.h"

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
    printf("스택 출력 : ");
    if (IsEmpty(Top)) {
        printf("스택이 비어있습니다.\n");
        return;
    }

    Nptr temp = Top;
    while (temp != NULL) {
        printf("%d ", temp->Item);
        temp = temp->Next;
    }
    printf("\n");
}

void Reverse(char* str) {
    Nptr Stack;
    Init(&Stack);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        Push(&Stack, (int)str[i]);
    }

    for (int i = 0; i < len; i++) {
        str[i] = (char)Pop(&Stack);
    }
    str[len] = '\0'; 

    FreeList(&Stack);
}
