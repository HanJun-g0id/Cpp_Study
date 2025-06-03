#include "ReverseStack.h"

int main() {
    char str[100];

    printf("문자열 입력 : ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    Reverse(str);

    printf("뒤집힌 문자열 : %s\n", str);

    return 0;
}
