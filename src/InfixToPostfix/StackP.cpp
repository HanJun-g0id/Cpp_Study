#include "StackP.h"
#include <ctype.h>

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
        //printf("POP!\n");
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

char Peek(Nptr Top) {
    return IsEmpty(Top) ? '\0' : Top->Item;
}

int priority(char op) {
    switch (op) {
    case '(': return 0;
    case '+': case '-': return 1;
    case '*': case '/': case '%': return 2;
    default: return -1;
    }
}

void InfixToPostfix(const char* c) {
    Nptr Stack;
    Init(&Stack);
    char ch;

    printf("후위표기식: ");
    for (int i = 0; (ch = c[i]) != '\0'; i++) {
        if (isalpha(ch)) {
            printf("%c", ch); //피연산자 > 그냥 출력
        }
        else if (ch == '(') {
            Push(&Stack, ch); //괄호 push
        }
        else if (ch == ')') {
            while (!IsEmpty(Stack) && Peek(Stack) != '(') {
                printf("%c", Pop(&Stack)); //괄호 닫으면 pop을 진행
            }
            Pop(&Stack); //'('를 만날 때 까지 내부 연산자 출력 후 '('까지 제거
        }
        else { //연산자 계산
            while (!IsEmpty(Stack) && priority(Peek(Stack)) >= priority(ch)) {
                //스택의 연산자 우선순위가 새로운 연산자의 우선순위보다 크거나 같으면 출력
                printf("%c", Pop(&Stack));
            }
            Push(&Stack, ch);
        }
    }

    while (!IsEmpty(Stack)) {
        printf("%c", Pop(&Stack));
    }

    printf("\n");
    FreeList(&Stack);
}
