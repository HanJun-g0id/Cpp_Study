#include "Cal_Stack.h"

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
/*------기존 스택 코드------ */

//연산자 비교용
char Peek(Nptr Top) {
    return IsEmpty(Top) ? '\0' : Top->Item;
}

//연산자 우선순위
int priority(char op) {
    switch (op) {
    case '(': return 0;
    case '+': case '-': return 1;
    case '*': case '/': case '%': return 2;
    default: return -1;
    }
}

//계산기
int Calculator(int a, int b, char ch) {
    switch (ch)
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '%': return a % b;
    default: return -1;
    }
}

//후위 계산용 함수
int EvaluatePostfix(const char* postfix) {
    Nptr CalcStack;
    Init(&CalcStack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) { //숫자 처리
            Push(&CalcStack, ch - '0'); //문자를 정수로 변환
        }
        else {  //연산자 처리
            int a = Pop(&CalcStack);
            int b = Pop(&CalcStack);
            Push(&CalcStack, Calculator(b, a, ch));
        }
    }
    int result = Pop(&CalcStack);
    FreeList(&CalcStack);
    return result;
}

//후위 표기용 함수
void InfixToPostfix(const char* c) {
    Nptr Stack;
    Init(&Stack);
    char ch;
    char postfix[100] = "";  //후위 표기식 저장용

    printf("후위표기식: ");
    for (int i = 0; (ch = c[i]) != '\0'; i++) {
        if (isdigit(ch)) {  //숫자 처리 (변수 대신 숫자 입력)
            printf("%c", ch);
            strncat_s(postfix, &ch, 1);
        }
        else if (ch == '(') {
            Push(&Stack, ch);
        }
        else if (ch == ')') {
            while (!IsEmpty(Stack) && Peek(Stack) != '(') {
                char op = Pop(&Stack);
                printf("%c", op);
                strncat_s(postfix, &op, 1);
            }
            Pop(&Stack);  //'(' 제거
        }
        else {  //연산자 처리
            while (!IsEmpty(Stack) && priority(Peek(Stack)) >= priority(ch)) {
                char op = Pop(&Stack);
                printf("%c", op);
                strncat_s(postfix, &op, 1);
            }
            Push(&Stack, ch);
        }
    }

    //스택에 남은 연산자 출력
    while (!IsEmpty(Stack)) {
        char op = Pop(&Stack);
        printf("%c", op);
        strncat_s(postfix, &op, 1);
    }

    //후위 표기식 계산 실행
    printf("\n계산 값 : %d\n", EvaluatePostfix(postfix));
    FreeList(&Stack);
}
