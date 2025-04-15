#include <stdio.h>
#include <stdlib.h>

int factorial (int f)
{
    // 팩토리얼 함수, 입력받은 숫자에서 하나씩 내려서 그 숫자가 1이 될때까지 곱한 뒤 반환
    if (f == 1)
        return 1;
    else
        return (f * factorial(f - 1));
}

int main(void)
{
    int x;
    printf("숫자 입력 : ");
    scanf("%d", &x);
    printf("%d\n", factorial(x));

    return 0;
}
