#include <stdio.h>
#include <stdlib.h>
#define MAX_VSIZE 100
typedef char VElement;

int vsize = 5;
VElement vdata[MAX_VSIZE] = {'U', 'V', 'W', 'X', 'Y'};
int adj[MAX_VSIZE][MAX_VSIZE] = {
    {0,1,1,0,0},
    {1,0,1,1,0},
    {1,1,0,0,1},
    {0,1,0,0,0},
    {0,0,1,0,0},
};

int degree(int v)
{
    int count = 0;
    for (int i = 0; i < vsize; i++)
    {
        if (adj[v][i] == 1) count++;
    }
    return count;
}

int main(void)
{
    printf("그래프의 인접행렬 표현\n");
    for(int i = 0; i < vsize; i++)
    {
        printf("정점 %c(차수=%d): ", vdata[i], degree(i));
        for (int j = 0; j < vsize; j++)
        {
            printf("%2d", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
