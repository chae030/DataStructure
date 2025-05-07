#include <stdio.h>
#include <stdlib.h>

#define MAX_HSIZE 100
#define PARENT(i) (i/2)
#define LEFT(i)   (i*2)
#define RIGHT(i)  (i*2+1)

typedef int HNode;
HNode A[MAX_HSIZE];
int heap_size = 0;
#define KEY(i)  (A[i])

void init_heap()    { heap_size = 0; }
int is_empty_heap() { return heap_size == 0; }
int is_full_heap()  { return (heap_size == MAX_HSIZE - 1); }
HNode heap_peek()   { return A[1]; }

void heap_push(HNode n)
{
    if (is_full_heap())
    {
        return;
    }

    heap_size += 1;
    A[heap_size] = n;
    int i = heap_size;

    while (i != 1)
    {
        if (KEY(i) > KEY(PARENT(i)))
        {
            A[i] = A[PARENT(i)];
            A[PARENT(i)] = n;
            i = PARENT(i);
        }
        else break;
    }
}

HNode heap_pop(void)
{
    if (is_empty_heap())
    {
        return -1;
    }

    HNode root = A[1];
    HNode last = A[heap_size];
    A[1] = last;
    heap_size -= 1;
    int i = 1;

    while (LEFT(i) <= heap_size)
    {
        int child = (LEFT(i) < heap_size && KEY(LEFT(i)) > KEY(RIGHT(i)))? LEFT(i) : RIGHT(i);

        if (KEY(i) > KEY(child)) break;
        A[i] = A[child];
        A[child] = last;
        i = child;
    }
    return root;
}

void print_heap(void)
{
    for (int i = 1; i <= heap_size; i++)
    {
        printf("%2d", A[i]);
    }
    printf("\n");
}

int main(void)
{
    int data[] = {2, 5, 4, 8, 9, 3, 7, 3};
    init_heap();

    printf("\n최대 힙 삽입 연산 테스트\n");
    for (int i = 0; i < 8; i++)
    {
        heap_push(data[i]);
        printf("%2d ---> ", data[i]);
        print_heap();
    }
    printf("\n최대 힙 삭제 연산 테스트\n");
    while(!is_empty_heap())
    {
        printf("%2d <--- ", heap_pop());
        print_heap();
    }
    printf("\n");

    return 0;
}
