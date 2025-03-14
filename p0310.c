#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void prime_num ()
{
    int i, j, x;

	for (i = 2; i <= 10000; i++) {
		x = 1;
		for (j = 2; j < i; j++) {
			if (i % j == 0) {
				x = 0;    //소수가 아닌 경우
				break;
			}
		}
		if (x == 1) {
			printf("%d\n", i);
		}
	}
}

int main ()
{
    clock_t start, finish;
    double duration;

    start = clock();
    prime_num();
    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("프로그램을 수행하는데 걸리는 시간 : %f 초\n", duration);

    return 0;
}