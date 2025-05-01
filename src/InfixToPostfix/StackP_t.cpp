#include "StackP.h"

int main() {

    char expr[100];
    printf("중위표기식을 입력하세요 (예: a*(b+c)/d): ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0;

    InfixToPostfix(expr);

    return 0;
}
