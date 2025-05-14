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
    {INF,15,0,INF,INF,INF,16},
    {12,INF,INF,0,17,37,INF},
    {INF,15,INF,17,0,19,14},
    {INF,INF,INF,37,19,0,42},
    {INF,INF,16,INF,14,42,0}
};

int selected[MAX_VSIZE];
int dist[MAX_VSIZE];
int prev[MAX_VSIZE];

int getMinVertex(void)
{
    int minv = 0, mindist = INF;
    for (int v = 0; v < vsize; v++) {
        if (!selected[v] && dist[v] < mindist) {
            mindist = dist[v];
            minv = v;
        }
    }
    return minv;
}

void print_path_sub(int v)
{
    if (prev[v] == -1) printf(" %c", vdata[v]);
    else {
        print_path_sub(prev[v]);
        printf(" --> %c", vdata[v]);
    }
}

void print_path(int start, int end)
{
    int v = start;

    printf("Start %c, End %c(%i):", vdata[start], vdata[end], dist[end]);
    print_path_sub(end);
    printf("\n");
}

void Dijkstra(int start, int end)
{
    for (int i = 0; i < vsize; i++) {
        selected[i] = 0;
        prev[i] = -1;
        dist[i] = INF;
    }
    dist[start] = 0;

    for (int i = 0; i < vsize; i++) {
        int v = getMinVertex();
        selected[v] = 1;
        for (int w = 0; w < vsize; w++) {
            if (selected[w] == 0) {
                if (dist[v] + adj[v][w] < dist[w]) {
                    dist[w] = dist[v] + adj[v][w];
                    prev[w] = v;
                }
            }
        }
        if (selected[end] == 1) break;
    }
    print_path(start, end);
}

int main(void)
{
    for (int start = 0; start < vsize; start++) {
        for (int end = 0; end < vsize; end++) {
            Dijkstra(start, end);
        }
    }
}
