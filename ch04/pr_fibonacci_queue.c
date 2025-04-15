// 피보나치 수열 구하기 문제 0, 1, 1, 2, 3, 5, 8, 13, 21,...
// F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 7
typedef int Element;
#include "CircularQueue.h"

int fibonacci(int n)
{
    init_queue();
    enqueue(0);
    enqueue(1);
    if (n <= 1) return n;
    for (int i = 2; i <= n; i++)
    {
        int n1 = dequeue(); // 큐는 선입선출이므로 먼저 넣은 것이 먼저 나옴
        int n2 = peek();
        enqueue(n2 + n1);
    }
    dequeue();
    return dequeue();
}

int main(void)
{
    printf("숫자 입력 : ");
    int n;
    scanf("%d", &n);
    printf("\n피보나치 수열 : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", fibonacci(i));
        if (i != n - 1) printf(", ");
    }
    printf("\n");

    return 0;
}
