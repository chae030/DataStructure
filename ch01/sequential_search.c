#include <stdio.h>

int sequential_search(int A[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == key)
        {
            return i;
        }
    }
    return -1;
}


int main()
{
    int arr[10] = {5, 9, 10, 17, 21, 29, 33, 37, 38, 43};
    int index;

    index = sequential_search(arr, 10, 5);
    printf("5의 위치 = %d\n", index);
    index = sequential_search(arr, 10, 43);
    printf("43의 위치 = %d\n", index);
    index = sequential_search(arr, 10, 42);
    printf("42의 위치 = %d\n", index);

    return 0;
}