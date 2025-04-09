#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 2000
typedef char Element;
#include "ArrayStack.h"

int main(void)
{
    char str[200];
    
    init_stack();
    printf("문자열 입력: ");
    fgets(str, 200, stdin); // get_s : 문자열 입력받음 (\n 나올때까지)
    for (int i = 0; str[i] != '\0'; i++)
    {
        push(str[i]);
    }

    printf("문자열 출력: ");
    while(!is_empty())
    {
        putchar(pop()); // putchar : 문자 하나 출력
    }
    printf("\n");

    return 0;
}
