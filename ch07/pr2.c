#include <stdio.h>
#include <stdlib.h>

typedef char Element;
#define MAX_SIZE 100
Element tree[MAX_SIZE] = {0, '1', '2', '3', 0, '4', '5'};
#include "CircularQueue.h"

void preorder(int index)
{
    if (tree[index] != 0)
    {
        printf("[%c] ", tree[index]);
        preorder(index*2);
        preorder(index*2 + 1);
    }
}

void inorder(int index)
{
    if (tree[index] != 0)
    {
        inorder(index*2);
        printf("[%c] ", tree[index]);
        inorder(index*2 + 1);
    }
}

void postorder(int index)
{
    if (tree[index] != 0)
    {
        postorder(index*2);
        postorder(index*2 + 1);
        printf("[%c] ", tree[index]);
    }
}

void levelorder(int index)
{
    if (tree[index] != 0)
    {
        init_queue();
        enqueue(index);
        while(!is_empty())
        {
            int n = dequeue();
            if(tree[n] != 0)
            {
                printf("[%c] ", tree[n]);
                enqueue(n * 2);
                enqueue(n * 2 + 1);
            }
        }
    }
}

int main(void)
{
    printf(" Pre-Order: ");
    preorder(1);
    printf("\n  In-Order: ");
    inorder(1);
    printf("\nPost-Order: ");
    postorder(1);
    printf("\nLevel-Order: ");
    levelorder(1);
    printf("\n");

    return 0;
}