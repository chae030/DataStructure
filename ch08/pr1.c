#include <stdio.h>
#include <stdlib.h>

#define MAX_VSIZE 100
typedef char VElement;
typedef struct GNode {
    int id;
    struct GNode* link;
} GNode;

int vsize = 0;
VElement vdata[MAX_VSIZE];
GNode* adj[MAX_VSIZE];

void init_graph(void)
{
    vsize = 0;
    for (int i = 0; i < MAX_VSIZE; i++) {
        adj[i] = NULL;
    }
}

void append_vtx(VElement e)
{
    vdata[vsize] = e;
    adj[vsize] = NULL;
    vsize += 1;
}

GNode* prepend_node(GNode* head, int v)
{
    GNode* n = (GNode*)malloc(sizeof(GNode));
    n->id = v;
    n->link = head;
    return n;
}

#define PrintVtx(i) (printf("%c  ", vdata[i]))

int visited[MAX_VSIZE];
void reset_visited(void)
{
    for (int i = 0; i < vsize; i++) {
        visited[i] = 0;
    }
}

void DFS(int v)
{
    visited[v] = 1;
    PrintVtx(v);
    for (GNode* p = adj[v]; p != NULL; p = p->link) {
        if (visited[p->id] == 0) {
            DFS(p->id);
        }
    }
}

#define MAX_SIZE 100
typedef int Element;
#include "CircularQueue.h"

void BFS(int v)
{
    init_queue();

    enqueue(v);
    visited[v] = 1;
    PrintVtx(v);
    while(!is_empty()) {
        v = dequeue();
        for (GNode* w = adj[v]; w != NULL; w = w->link) {
            if (!visited[w->id]) {
                enqueue(w->id);
                visited[w->id] = 1;
                PrintVtx(w->id);
            }
        }
    }
}

void insert_edge(int u, int v)
{
    adj[u] = prepend_node(adj[u], v);
    adj[v] = prepend_node(adj[v], u);
}

int main (void)
{
    VElement vtx[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int am[MAX_VSIZE][MAX_VSIZE] = {
        {0,1,1,0,0,0,0,0},
        {1,0,0,1,0,0,0,0},
        {1,0,0,1,1,0,0,0},
        {0,1,1,0,0,1,0,0},
        {0,0,1,0,0,0,1,1},
        {0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,1,0,1,0}
    };

    init_graph();
    for (int i = 0; i < 8; i++) {
        append_vtx(vtx[i]);
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (am[i][j]) {
                insert_edge(i, j);
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        reset_visited();
        printf("DFS(%c출발) ==> ", vdata[i]);
        DFS(i);
        printf("\n");

        reset_visited();
        printf("BFS(%c출발) ==> ", vdata[i]);
        BFS(i);
        printf("\n\n");
    }

    return 0;
}