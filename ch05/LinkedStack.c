#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#include "LinkedStack.h"

void print_stack(void)
{
    for (Node* p = top; p != NULL; p = p->link) {
        printf("%3d", p->data);
    }
}

void print_recur(Node* p)
{
    if (p != NULL) {
        print_recur(p->link);
        printf("%3d", p->data);
    }
}

int main(void)
{
    int A[7] = { 0, 1, 1, 2, 3, 5, 8 };

    init_stack();
    printf("스택 테스트\n 입력 데이터: ");
    for (int i = 0; i < 7; i++) {
        printf("%3d", A[i]);
        push(A[i]);
    }

    printf("\n 출력 데이터: ");
    while (!is_empty())
        printf("%3d", pop());
    printf("\n");

    destroy_stack();

    return 0;
}
