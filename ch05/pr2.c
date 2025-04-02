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
    for (int i = 0; i < 7; i++)
    {
        push(A[i]);
    }

    printf("스택 출력(크기: %d)", size());

    printf("\n입력된 순서");
    print_recur(top);
    printf("\n입력의 역순");
    print_stack();
    printf("\n");

    destroy_stack();

    return 0;
}
