#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
typedef double Element;
#include "ArrayStack.h"

double eval_postfix(char * str) // 후위 계산 : 2 3 + 4 * 9 +
{
    int i = 0;
    while (str[i] != '\0')
    {
        char c = str[i++];
        if (c >= '0' && c <= '9')
        {
            double num = (double)c - '0';
            push(num);
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            double num2 = pop();
            double num1 = pop();
            switch (c)
            {
                case '+': push(num1+num2); break;
                case '-': push(num1-num2); break;
                case '*': push(num1*num2); break;
                case '/': push(num1/num2); break;
            }
        }
    }
    return pop();
}

int precedence(char c) // 우선순위 계산
{
    switch (c)
    {
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

char* infix_to_postfix(char str[]) // 중위 -> 후위 변환
{
    init_stack();
    int i = 0;
    int j = 0;
    char* result = (char*)malloc(sizeof(char) * MAX_SIZE);
    while (str[i] != '\0')
    {
        char c = str[i++];
        if (c >= '0' && c <= '9')
        {
            result[j++] = c;
            result[j++] = ' ';
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while(is_empty() == 0)
            {
                char p = pop();
                if (p == '(') break;
                else {
                    result[j++] = p;
                    result[j++] = ' ';
                }
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            while(is_empty() == 0)
            {
                char p = peek();
                if (precedence(p) >= precedence(c))
                {
                    result[j++] = p;
                    result[j++] = ' ';
                    pop();
                }
                else break;
            }
            push(c);
        }
    }
    while (is_empty() == 0)
    {
        result[j++] = pop();
        result[j++] = ' ';
    }
    result[j] = '\0';
    int k = 0;
    while (result[k]!= '\0')
    {
        printf("%c", result[k++]);
    }
    printf("\n");
    return result;
}

int main (void)
{
    printf("결과: %f", eval_postfix(infix_to_postfix("(2+3)*4+9")));

    return 0;
}
