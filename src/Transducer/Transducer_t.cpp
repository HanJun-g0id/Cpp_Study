#include "Transducer.h"

int main() {
    Nptr Stack;
    int input;

    Init(&Stack);

    printf("10진수 입력: ");
    scanf_s("%d", &input);

    Calculator(&Stack, input);

    printf("2진수 변환 결과: ");
    while (!IsEmpty(Stack)) {
        printf("%d", Pop(&Stack));
    }
    printf("\n");

    FreeList(&Stack);
    return 0;
}
