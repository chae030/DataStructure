#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef int Element;
#include "ArrayList.h"

void print_list (char *msg)
{
    printf("배열구조리스트 %s[%2d]: ", msg, size);
    for (int i = 0; i < size; i++)
    {
        printf("%2d ", data[i]);
    }
    printf("\n");
}

int main(void)
{
    init_list();

    insert(0, 10);
    insert(0, 20);
    insert(1, 30);
    insert(size, 40);
    insert(2, 50);
    print_list("(삽입x5)");
    
    delete(2);
    delete(size - 1);
    delete(0);
    print_list("(삭제x3)");

    return 0;
}

