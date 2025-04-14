#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#include "DbLinkedDeque.h"

void print_deque(char msg[])
{
    printf("이중 연결 덱 %s[%2d]: ", msg, size());
    for(DNode* p = front; p != NULL; p = p -> next)
    {
        printf("%2d ", p -> data); 
    }
    printf("\n");
}

int main (void)
{
    init_deque();
    for (int i = 1; i < 10; i++)
    {
        if (i % 2) add_front(i);
        else add_rear(i);
    }
    print_deque("원형 덱 홀수-짝수");
    printf("\tdelete_front() --> %d\n", delete_front());
    printf("\tdelte_rear  () --> %d\n", delete_rear());
    printf("\tdelete_front() --> %d\n", delete_front());
    print_deque("원형 덱 삭제-홀짝홀");

    return 0;
}
