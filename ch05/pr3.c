typedef int Element;
#include "LinkedQueue.h"
#include <stdio.h>
#include <stdlib.h>

void print_queue(char* msg)
{
    printf("(큐 크기:%d)%s= ", size(), msg);
    if (front != NULL) {
        for (Node* p = front; p != NULL; p = p->link)
            printf("%2d ", p->data);
    }
    printf("\n");
}

int main(void)
{
    init_queue();
    for (int i = 1; i < 7; i++) enqueue(i);
    print_queue("enqueue 1~6: ");

    for (int i = 0; i < 4; i++) dequeue();
    print_queue("dequeue 4회: ");

    for (int i = 7; i < 10; i++) enqueue(i);
    print_queue("enqueue 7~9: ");
    destroy_queue();

    return 0;
}
