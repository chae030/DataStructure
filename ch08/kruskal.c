#include <stdio.h>
#include <stdlib.h>

#define MAX_HSIZE 100
struct HeapNode {
    int key;
    int v1;
    int v2;
};
typedef struct HeapNode HNode;
#define Compare(n1, n2)  ((n2.key) - (n1.key))

#define Parent(i) (heap[i/2])
#define Left(i) (heap[i*2])
#define Right(i) (heap[i*2+1])

HNode heap[MAX_HSIZE];
int heap_size = 0;

void error(char str[])
{
    printf("%s\n", str);
    exit(1);
}

void init_heap() {heap_size = 0;}
int is_empty_heap() {return heap_size == 0;}
int is_full_heap() {return (heap_size == MAX_HSIZE - 1);}

HNode heap_peek() {return heap[1];}

void heap_push(HNode n)
{
    if (is_full_heap()) {
        error("Overflow Error!");
    }

    heap_size += 1;
    int i = heap_size;

    while(i != 1 && Compare(n, Parent(i)) > 0) {
        heap[i] = Parent(i);
        i /= 2;
    }
    heap[i] = n;
}

HNode heap_pop(void)
{
    if (is_empty_heap() != 0) {
        error("Underflow Error!");
    }

    HNode root = heap[1];
    HNode last = heap[heap_size];
    int pid = 1, cid = 2;

    heap_size -= 1;
    while (cid <= heap_size) {
        if (cid < heap_size && Compare(Left(pid), Right(pid)) < 0) {
            cid++;
        }
        if (Compare(last, heap[cid]) >= 0) break;

        heap[pid] = heap[cid];
        pid = cid;
        cid *= 2;
    }
    heap[pid] = last;

    return root;
}

#define MAX_VSIZE 100
typedef char VElement;
#define PrintVtx(i)     (printf("%c  ", vdata[i]))
#define INF 9999

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

int parent[MAX_VSIZE];
int set_size;
void init_set(int nSets)
{
    set_size = nSets;
    for (int i = 0; i < nSets; i++) {
        parent[i] = -1;
    }
}

int find_set(int id)
{
    while (parent[id] >= 0) id = parent[id];
    return id;
}

void union_set(int s1, int s2)
{
    parent[s1] = s2;
    set_size--;
}

void Kruskal(void)
{
    init_set(vsize);

    init_heap();
    for (int i = 0; i < vsize; i++) {
        for (int j = i + 1; j < vsize; j++) {
            if (adj[i][j] > 0 && adj[i][j] < INF) {
                HNode e;
                e.key = adj[i][j];
                e.v1 = i;
                e.v2 = j;
                heap_push(e);
            }
        }
    }

    while (set_size > 1) {
        HNode e = heap_pop();
        int uset = find_set(e.v1);
        int vset = find_set(e.v2);

        if (uset != vset) {
            printf("간선 추가 : %c = %c (비용:%d)\n", vdata[e.v1], vdata[e.v2], e.key);
            union_set(uset, vset);
        }
        else printf("간선 무시 : %c = %c\n", vdata[e.v1], vdata[e.v2]);
    }
}

int main(void)
{
    printf("MST By Kruskal's Algorithm\n");
    Kruskal();

    return 0;
}
