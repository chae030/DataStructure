#include <stdio.h>
#include <stdlib.h>
#define MAX_VSIZE 100
typedef char VElement;
#define INF 9999

int vsize = 7;
VElement vdata[MAX_VSIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };

int adj[MAX_VSIZE][MAX_VSIZE] = {
    { 0, 25, INF, 12, INF, INF, INF },
    { 25, 0, 10, INF, 15, INF, INF },
    { INF, 10, 0, INF, INF, INF, 16 },
    { 12, INF, INF, 0, 17, 37, INF },
    { INF, 15, INF, 17, 0, 19, 14 },
    { INF, INF, INF, 37, 19, 0, 42 },
    { INF, INF, 16, INF, 14, 42, 0 }
};

int selected[MAX_VSIZE]; 
int dist[MAX_VSIZE]; 

int getMinVertex(void)
{
    int minv = 0, mindist = INF;
    for (int v = 0; v < vsize; v++)
        if (!selected[v] && dist[v] < mindist) {
            mindist = dist[v];
            minv = v;
        }
    return minv;
}

int parent[MAX_VSIZE];
void InsertVtx(int v)
{
    if (parent[v] == -1) {
        printf("시작:%c\n", vdata[v]);
    }
    else {
        printf("%c -> %c\n", vdata[parent[v]], vdata[v]);
    }
}

void Prim(void)
{
    for (int i = 0; i < vsize; i++) {
        dist[i] = INF;
        selected[i] = 0;
        parent[i] = -1;
    }
    dist[0] = 0;
    for (int i = 0; i < vsize; i++) { 
        int v = getMinVertex();
        selected[v] = 1;
        if (dist[v] == INF)               
            return;
        InsertVtx(v);   
        for (int w = 0; w < vsize; w++)   
            if (!selected[w])          
                if (adj[v][w] < dist[w]) {  
                    dist[w] = adj[v][w];
                    parent[w] = v;
                }
    }
    printf("\n");
}

int main(void)
{
    printf("MST By Prim's Algorithm\n");
    Prim();

    return 0;
}