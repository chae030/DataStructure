#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef int Element;
typedef struct 
{
    Element data[MAX_SIZE];
    int size;
} ArrayList;

void error (char str[])
{
    printf("%s\n", str);
    exit(1);
}

void init_list(ArrayList *pList) {pList -> size = 0;}
int is_empty(ArrayList list) {return list.size == 0;}
int is_full(ArrayList list) {return list.size == MAX_SIZE;}

void insert(ArrayList *pList, int pos, Element e)
{
    if (is_full(*pList))
    {
        error("Overflow Error!");
    }
    
    if (pos < 0 || pos > pList->size)
    {
        error("Invalid Position Error!");
    }

    for (int i = pList->size-1; i >= pos; i--)
    {
        pList->data[i+1] = pList->data[i];
    }

    pList->data[pos] = e;
    pList->size+=1;
}

void print_list (char* msg, ArrayList list)
{
    printf("배열구조리스트 %s[%2d]: ", msg, list.size);
    for (int i = 0; i <list.size; i++)
    {
        printf("%2d ", list.data[i]);
    }
    printf("\n");
}

void concat(ArrayList listA, ArrayList listB, ArrayList *result)
{
    for (int i = 0; i < listA.size; i++)
    {
        insert(result, i, listA.data[i]);
    }
    for (int i = 0; i <listB.size; i++)
    {
        insert(result, listA.size+i, listB.data[i]);
    }
}

int main(void)
{
    ArrayList listA, listB, listC;
    init_list(&listA);
    init_list(&listB);
    init_list(&listC);

    insert(&listA, 0, 1);
    insert(&listA, 0, 2);
    print_list("ListA:", listA);
    insert(&listB, 0, 10);
    insert(&listB, 1, 20);
    print_list("ListB:", listB);
    concat(listA, listB, &listC);
    print_list("ListC:", listC);
    
    return 0;
}


