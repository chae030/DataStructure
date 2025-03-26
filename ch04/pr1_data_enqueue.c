#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 6
typedef int Element;
Element data[MAX_SIZE];
#include "CircularQueue.h"
int front, rear, size;

int is_size (void)
{
    return size;
}

void print_queue(char msg[])
{
    printf("%s front = %d, rear = %d", msg, front, rear);
    for (int i = front + 1; i <= front + is_size(); i++)
        printf("%2d ", data[i % MAX_SIZE]);
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

    return 0;
}
