#include <stdio.h>

int has_duplicate_elem(int A[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (A[i] == A[j])
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int a[8] = {4, 5, 9, 11, 14, 17, 23, 32};
    int b[8] = {4, 5, 11, 14, 14, 17, 23, 32};

    printf("A : 중복된 요소 %s\n", has_duplicate_elem(a, 8) ? "있음" : "없음");
    printf("B : 중복된 요소 %s\n", has_duplicate_elem(b, 8) ? "있음" : "없음");
}