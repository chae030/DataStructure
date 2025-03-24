#include <stdio.h>

int isPrime (int n, int divisor)
{
    if (n <= 1) return 0;
    if (divisor == 1) return 1;
    if (n % divisor == 0) return 0;
    return isPrime(n, divisor - 1);
}

int main (void)
{
    for (int i = 1; i <= 100; i++) {
        if (isPrime(i, i-1)) printf("%d ", i);
    }

    return 0;
}