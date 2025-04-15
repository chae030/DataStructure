#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef char Element;
#include "ArrayStack.h"

int precedence (char op)
{
    switch (op)
    {
    case '(' :
    case ')' :
        return 0;
    case '+' :
    case '-' :
        return 1;
    case '*' :
    case '/' :
        return 2;
    }
    return -1;
}

void infix_to_postfix (char expr[])
{
    init_stack();
    int i = 0;

    while (expr[i] != '\0')
    {
        char c = expr[i++];
        if (c >= '0' && c <= '9')
        {
            printf("%c ", c);
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (is_empty() == 0)
            {
                char op = pop();
                if (op == '(') break;
                else printf("%c ", op);
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            while (is_empty() == 0)
            {
                char op = peek();
                if (precedence(c) <= precedence(op)) // 스택에 들어있는 연산자(op)가 현재 연산자(c)보다 우선순위가 크거나 같을 때
                {
                    printf("%c ", op);
                    pop(); // 스택에 들어있는 연산자 출력, 스택에서 삭제
                }
                else break; // 스택에 들어있는 연산자(op)가 현재 연산자(c)보다 우선순위가 작을 때 break
            }
            push(c); // 현재 연산자 스택에 삽입
        }
    }
    while (is_empty() == 0) // 스택이 비었을 때까지
    {
        printf("%c ", pop());
    }
    printf("\n");
}

int main(void)
{
    char expr[2][80] = { "8 / 2 - 3 + (3 * 2)", "1 / 2 * 4 * (1 / 4)" };

    printf("중위수식 : %s ==> 후위수식 : ", expr[0]);
    infix_to_postfix(expr[0]);
    printf("중위수식 : %s ==> 후위수식 : ", expr[1]);
    infix_to_postfix(expr[1]);

    return 0;
}
