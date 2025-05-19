#include <stdio.h>
#include <stdlib.h>
#define MAX_VSIZE 100
typedef char VElement;
#define INF 999

int vsize = 7;
VElement vdata[MAX_VSIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
int adj[MAX_VSIZE][MAX_VSIZE] = {
    {0,25,INF,12,INF,INF,INF},
    {25,0,10,INF,15,INF,INF},
    {INF,10,0,INF,INF,INF,16},
    {12,INF,INF,0,17,37,INF},
    {INF,15,INF,17,0,19,14},
    {INF,INF,INF,37,19,0,42},
    {INF,INF,16,INF,14,42,0}
};

int A[MAX_VSIZE][MAX_VSIZE];
void printA(void)
{
    printf("===================================\n");
    for (int i = 0; i < vsize; i++) {
        for (int j = 0; j < vsize; j++) {
            if (A[i][j] == INF) printf(" INF ");
            else printf("%4d ", A[i][j]);
        }
        printf("\n");
    }
}

void Floyd(void)
{
    for (int i = 0; i<vsize; i++) {
        for (int j = 0; j <vsize; j++) {
            A[i][j] = adj[i][j];
        }
    }

    for (int k = 0; k < vsize; k++) {
        for (int i = 0; i < vsize; i++) {
            for (int j= 0; j < vsize; j++) {
                if (A[i][k] + A[k][j] < A[i][j]) A[i][j] = A[i][k] + A[k][j];
            }
        }
        printA();
    }
}

int main(void)
{
    Floyd();

    return 0;
}
