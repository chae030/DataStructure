#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#define MAX_SIZE 100
#include "pr_pr1.h"

int main(void)
{
    int A[7] = { 0, 1, 1, 2, 3, 5, 8 };
    Stack S1, S2;
    init_stack(&S1);
    init_stack(&S2);
    printf(" 입력 데이터 : ");
    for (int i = 0; i < 7; i++)
    {
        printf(" %d", A[i]);
        push(&S1, A[i]);
    }
    printf("\n S1 출력 데이터 : ");
    while (!is_empty(&S1)) {
        printf(" %d", peek(&S1));
        push(&S2, pop(&S1));
    }
    printf("\n S2 출력 데이터 : ");
    while (!is_empty(&S2)) {
        printf(" %d", pop(&S2));
    }
    printf("\n");

    return 0;
}
