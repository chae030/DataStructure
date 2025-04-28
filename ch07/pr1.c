#include <stdio.h>
#include <stdlib.h>

typedef char TElement;
#define MAX_SIZE 100
TElement tree[MAX_SIZE] = {0, '1', '2', '3', 0, '4', '5'};

void preorder(int index)
{
	if (tree[index] != 0) {
		printf("( ");
		printf("%c ", tree[index]);
		preorder(index*2);
		preorder(index*2 + 1);
		printf(") ");
	}
	else printf(". ");
}

int main(void)
{
    preorder(1);
    printf("\n");
    
    return 0;
}
