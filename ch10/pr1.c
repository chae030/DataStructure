#include <stdio.h>

int binary_search(int A[], int key, int low, int high)
{
    if (low <= high) {
        int mid = (low + high) / 2;
        printf("->%d", A[mid]);
        if (key == A[mid])
        {
            return mid;
        }
        else if (key < A[mid])
        {
            return binary_search(A, key, low, mid - 1);
        }
        else
        {
            return binary_search(A, key, mid + 1, high);
        }
    }
    return -1;
}

int binary_search_iter(int A[], int key, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        printf("->%d", A[mid]);
        if (key == A[mid])
        {
            return mid;
        }
        else if (key < A[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int binary_search_interpolation(int A[], int key, int low, int high)
{
    if (low <= high)
    {
        int mid = (int)((float)(key - A[low]) / (A[high] - A[low]) * (high - low)) + low;
        printf("->%d", A[mid]);
        if (key == A[mid]) 
        {
            return mid;
        }
        else if (key < A[mid])
        {
            return binary_search_interpolation(A, key, low, mid - 1);
        }
        else
        {
            return binary_search_interpolation(A, key, mid + 1, high);
        }
    }
    return -1;
}

void insert(int A[], int key, int dataLen)
{
    A[dataLen] = key;
    for (int i = dataLen; i > 0; i--)
    {
        if (A[i-1] > A[i])
        {
            int temp = A[i-1];
            A[i-1] = A[i];
            A[i] = temp;
        }
    }
}

int main (void)
{
    int list[100] = { 8, 11, 12, 15, 16, 19, 20, 23, 25, 28, 29, 31, 33, 35, 38, 40};
    int key = 28;
    printf("    %d 이진탐색(순환): %d\n", key, binary_search(list, key, 0, 15));
    printf("    %d 이진탐색(반복): %d\n", key, binary_search_iter(list, key, 0, 15));
    printf("    %d 이진탐색(보간): %d\n", key, binary_search_interpolation(list, key, 0, 15));
    printf("\n");
    while(1)
    {
        printf("데이터 입력: ");
        scanf("%d", &key);
        if (binary_search(list, key, 0, 15) != -1)
        {
            printf(" [이미 데이터가 있음!!]\n");
        }
        else
        {
            insert(list, key, 16);
            printf(" [%d 삽입]\n", key);
            break;
        }
    }

    printf("데이터 검색\n");
    printf("    %d 이진탐색(순환): %d\n", key, binary_search(list, key, 0, 16));
    printf("    %d 이진탐색(반복): %d\n", key, binary_search_iter(list, key, 0, 16));
    printf("    %d 이진탐색(보간): %d\n", key, binary_search_interpolation(list, key, 0, 16));
    printf("\n");

    return 0;
}
