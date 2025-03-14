#include <stdio.h>

int find_max(int a, int b, int c)
{
    int max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    return max;
}

int main()
{
    int max;
    max = find_max(32, 14, 5);
    printf("최댓값 = %d\n", max);
    max = find_max(5 ,17, 23);
    printf("최댓값 = %d\n", max);
    return 0;
}