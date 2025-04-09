#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
struct CallInfo
{
    char name[32];
    int param;
};
typedef struct CallInfo Element;
#include "ArrayStack.h"

int main(void) 
{
    Element calls[4] = {
        { "main()", 0 },
        { "factorial()", 3 },
        { "factorial()", 2 },
        { "factorial()", 1 } };
    
    init_stack();
    printf("함수 호출 순서: \n");
    for (int i = 0; i < 4; i++)
    {
        push(calls[i]);
        printf("\t%s %d\n", calls[i].name, calls[i].param);
    } // 함수 호출 정보를 순서대로 스택에 삽입하고 화면에 출력

    printf("함수 변환 순서: \n");
    while(!is_empty())
    {
        Element call = pop();
        printf("\t%s %d\n", call.name, call.param);
    }

    return 0;
}
