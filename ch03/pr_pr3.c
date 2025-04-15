#include <stdio.h>
#include <stdlib.h>

int isPrime (int n, int divisor)
{
    if (n <= 1) return 0;
    else if (divisor == 1) return 1;
    else if (n % divisor == 0) return 0;
    return isPrime(n, divisor - 1);
}

int main(void)
{
    for (int i = 1; i <= 100; i++)
    {
        if (isPrime(i, i/2)) printf("%d ", i);
    }

    return 0;
}
