#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef char Element;
#include "ArrayStack.h"

int check_matching(char * expr)
{
    int i = 0, prev;

    init_stack();
    
    while(expr[i] != '\0')
    {
        char ch = expr[i++];
        if (ch == '{' || ch == '(' || ch == '[')
        {
            push(ch);
        }
        else if (ch == '}' || ch == ')' || ch == ']')
        {
            if (is_empty())
            {
                return 2;
            }

            prev = pop();
            if ((ch == '}' && prev != '{') || (ch == ')' && prev != '(') || (ch == ']' && prev != '['))
            {
                return 3;
            }
        }
    }
    if (!is_empty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    char expr[4][80] = {
        "{A[(i+1)]=0;}",
        "if((i==0) && (j==0)",
        "while(n<8)){n++;}",
        "arr[(i+1]) = 0;"
    };

    for (int i = 0; i < 4; i++)
    {
        int errCode = check_matching(expr[i]);
        if (errCode == 0)
        {
            printf("%-20s -> 정상\n", expr[i]);
        }
        else
        {
            printf("%-20s -> 오류(조건%d 위반)\n", expr[i], errCode);
        }
    }

    return 0;
}
