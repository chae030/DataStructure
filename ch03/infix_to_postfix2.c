#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
typedef double Element;
#include "ArrayStack.h"

char postfix[100] = "";

void print(char data)
{
    char str[3] = {data, ' ', '\0'};
    strcat(postfix, str);
}

int precedence(char op)
{
    switch (op) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

char* infix_to_postfix(char expr[])
{
    init_stack();

    int i = 0;
    while (expr[i] != '\0') {
        char c = expr[i++];
        if ((c >= '0' && c <= '9')) {
            print(c);
        }
        else if (c == '(')
            push(c);
        else if (c == ')') {
            while (is_empty() == 0) {
                char op = (char)pop();
                if (op == '(') break;
                else print(op);
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (is_empty() == 0) {
                char op = (char)peek();
                if (precedence(c) <= precedence(op)) {
                    print(op);
                    pop();
                }
                else break;
            }
            push(c);
        }
    }
    while(is_empty() == 0) 
        print(pop());
    printf("\n");

    return postfix;
}

double eval_postfix(char expr[])
{
    int i = 0;

    init_stack();
    while (expr[i] != '\0') {
        char c = expr[i++];
        if (c >= '0' && c <= '9') {
            double num = (double)c - '0';
            push(num);
        }
        else if (c=='+' || c=='-' || c=='*' || c=='/') {
            double val2 = pop();
            double val1 = pop();
            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}

int main (void)
{
    printf("%s\n", infix_to_postfix("(2+3)*4+9"));
    printf("결과: %f", eval_postfix(infix_to_postfix("(2+3)*4+9")));

    return 0;
}
