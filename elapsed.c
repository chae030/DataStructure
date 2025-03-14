#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int clac_sum(int n)
{
    int i, sum = 0;
    for (i = 1; i < n; i++)
    {
        sum = sum + i;
    }
    return sum;
}

void main ()
{
    clock_t start, finish;
    double duration;

    printf("1부터 10까지의 합은 %d 입니다.\n", clac_sum(10));

    start = clock();
    clac_sum(100000000);
    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("1부터 1억까지의 합을 구하는데 걸리는 시간 : %f 초\n", duration);
}