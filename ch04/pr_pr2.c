#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10
typedef char Element;
#include "pr_pr2.h"

int check(char str[])
{
    init_deque();
    for (int i = 0; i < strlen(str); i++)
    {
        add_rear(str[i]);
    }
    while(!is_empty())
    {
        char a, b;
        if (!is_empty()) a = delete_front();
        else return 0;
        if (!is_empty()) b = delete_rear();
        else return 0;
        if (a != b) return 0;
    }
    return 1;
}

int main(void)
{
    char input[100];
    while (1)
    {
        printf("\n입력 : ");
        scanf("%s", input);
        if (strcmp(input, "0") == 0) break;
        printf("결과 : %s", check(input) ? "회문" : "비회문");
    }

    return 0;
}
