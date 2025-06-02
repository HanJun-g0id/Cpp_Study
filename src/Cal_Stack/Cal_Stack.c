#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1; // top의 인덱스가 0부터 시작할 수 있게

// Push 기능
void push(int x)
{
    if (top >= MAX - 1)
    {                               // 만약 탑이 스택 범위를 벗어나면
        printf("Stack Overflow\n"); // 오버플로우
        return;
    }
    stack[++top] = x; // 아닌경우 탑 값 증가 시키고 해당 위치에 값 삽입
}
// Pop 기능
int pop()
{
    if (top < 0)
    {                                // 만약 탑이 0보다 작으면
        printf("Stack Underflow\n"); // 언더플로우
        return -1;
    }
    return stack[top--]; // 아니라면 탑 값을 1 감소 시킴(값 자체를 지우지 않아도 다시 못 쓰게 되니까)
}
// 연산자 필터 : 입력을 정수로 받아서 중간 문자(연산자)를 걸러줌
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int evaluatePostfix(char *exp)
{
    int i, op1, op2, result;
    for (i = 0; exp[i] != '\0'; i++) //들어온 문자열 끝까지 한 글자씩 진행함
    {
        if(exp[i]==' ') continue; //만약 공백이면 그냥 이어서 진행하세요
        if(isdigit(exp[i])){ //만약 현재 문자가 숫자라면
            int num = 0; //숫자 저장 변수 초기화
            while (isdigit(exp[i])) //연속 숫자 처리용
            {
                num = num * 10 + (exp[i] - '0'); //숫자로 변환해서 num에 누적계산
                i++; //다음 문자로 이동
            }
            i--; //숫자 끝났는데 한칸 이동해 있으니까 그것만 다시 돌아오게 하기
            push(num); //변환숫자 스택에 저장
        } else if (isOperator(exp[i])) { //숫자 아니고 문자(연산자)라면
            op2 = pop(); //스택에서 하나 꺼내서 저장
            op1 = pop(); //하나 더 꺼내서 저장
            switch (exp[i]) //입력된 문자에 따라
            { //연산 실행
            case '+' : result = op1 + op2; break;
            case '-' : result = op1 - op2; break;
            case '*' : result = op1 * op2; break;
            case '/' : result = op1 / op2; break;
            default: printf("Invalid operator\n"); return -1;
            }
            push(result); //계산 결과 다시 스택에 저장
        }
    }
    return pop();
}

int main() {
    char exp[MAX];
    printf("후위 연산 입력 : ");
    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = '\0';

    int result = evaluatePostfix(exp);
    printf("결과 : %d\n", result);

    return 0;
}
