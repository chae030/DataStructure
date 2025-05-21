#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int Element;
#include "QueueStruct.h"

void printStep(int arr[], int n, int val)
{
    int i;
    printf("  Step %2d = ", val);
    for (i = 0; i < n; i++) printf("%5d", arr[i]);
    printf("\n");
}
void printArray(int arr[], int n, char *str)
{
    int i;
    printf("%s = ", str);
    for (i = 0; i < n; i++) printf("%5d", arr[i]);
    printf("\n");
}

#define BUCKETS 10
#define DIGITS 4
void radix_sort(int A[], int n)
{
    Queue queues[BUCKETS];
    for (int b = 0; b < BUCKETS; b++) {
        init_queue(&queues[b]);
    }
    int factor = 1;
    for (int d = 0; d < DIGITS; d++) {
        for (int i = 0; i < n; i++) {
            int id = (A[i] / factor) % BUCKETS;
            enqueue(&queues[id], A[i]);
        }

        int i = 0;
        for (int b = 0; b < BUCKETS; b++) {
            while (!is_empty(&queues[b])) {
                A[i++] = dequeue(&queues[b]);
            }
        }

        factor *= BUCKETS;
        printStep(A, n, d+1);
    }
}

int main(void)
{
    int list[10] = { 7792, 2104, 7009, 2001, 7116, 6099, 7971, 1912, 4846, 8929 };

    printArray(list, 10, "Original ");
    radix_sort(list, 10);
    printArray(list, 10, "RadixSort");
}
