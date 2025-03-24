#include <stdio.h>

int factorial_iter (int n)
{
    int i, result = 1;
    for ( i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int factorial(int n)
{
    if (n == 1)
        return 1;
    else   
        return n * factorial(n-1);
}

int main(void)
{
    printf("반복 factorial(3) = %d\n", factorial_iter(3));
    printf("순환 factorial(10) = %d\n", factorial(10));

    return 0;
}
