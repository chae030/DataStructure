#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#include "LinkedList.h"

void print_list(char *msg)
{
    printf("단순연결리스트 %s[%2d]: ", msg, size());
    for (Node* p = head; p != NULL; p = p->link)
    {
        printf("%2d ", p->data);
    }
    printf("\n");
}

int main(void)
{
    init_list();
    insert(0,10);
    insert(0,20);
    insert(1,30);
    insert(size(),40);
    insert(2,50);
    print_list("(삽입x5)");

    delete(2);
    delete(size()-1);
    delete(0);
    print_list("(삭제x3)");
    destroy_list();

    return 0;
}


