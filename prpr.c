#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef int Element;
#include "ArrayStack.h"

int recur2(int n) {
	printf("recur2(%d)\n", n);
	return n*recur2(n-1);
}

int sum(int n)
{
    printf("호출! %d ", n);
    if (n < 1) return 0;
    else return ( n + sum(n-1) );
}

void asterisk(int i)
{
    if (i > 1)
    {
        asterisk(i/2);
        asterisk(i/2);
    }
    printf("*");
}

int main (void)
{
    init_stack();
    int n = 4096;
    while (n > 0)
    {
        push(n % 2);
        n /= 2;
    }
    while (!is_empty())
    {
        printf("%d", pop());
    }
    
    return 0;
}
