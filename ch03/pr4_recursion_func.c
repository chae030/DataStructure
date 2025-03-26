#include <stdio.h>

void number_print(int n) 
{
    printf("%d%s", n, (n == 0 ? "" : ", "));
    if (n <= 0) return;
    number_print(n - 1);
    printf(", %d", n);
}

int main (void)
{
    int n;

    while(1) {
        printf("\n입력 : ");
        scanf("%d", &n);
        if (n < 0) break;
        number_print(n);
    }

    return 0;
}
