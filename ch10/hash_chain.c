#include <stdio.h>
#include <stdlib.h>

typedef int Entry;
typedef struct HNode {
    Entry key;
    struct HNode* link;
} Node;
#define M 13
Node* table[M];
int hashFn(Entry key) { return key % M; }

void init_chain(void) {
    for (int i=0; i<M; i++) {
        table[i] = NULL;
    }
}
void print_chain(char* msg) {
    printf("%s: ", msg);
    for (int i = 0; i < M; i++) {
        printf("->");
        for (Node* n = table[i]; n != NULL; n = n->link) {
            printf("%2d ", n->key);
        }
        printf(" ");
    }
    printf("\n");
}

void insert_chain(Entry key) {
    int i = hashFn(key);
    Node* n = (Node*)malloc(sizeof(Node));
    n->key = key;
    n->link = table[i];
    table[i] = n;
}

Node* search_chain(Entry key) {
    int i = hashFn(key);
    for (Node* n = table[i]; n != NULL; n = n->link) {
        if (key == n->key) {
            return n;
        }
    }
    return NULL;
}

void delete_chain(Entry key) {
    int i = hashFn(key);
    Node* n = table[i];

    if (n == NULL) return;
    if (key == n->key) {
        table[i] = n->link;
        free(n);
    }
    else {
        for (; n->link != NULL; n = n->link) {
            if (key == n->link->key) {
                Node* p = n->link;
                n->link = p->link;
                free(p);
                return;
            }
        }
    }
}

int main(void)
{
    Entry data[9] = { 45, 27, 88, 9, 71, 60, 46, 38, 24 };

    init_chain();
    print_chain("삽입전");

    for (int i = 0; i < 9; i++) {
        insert_chain(data[i]);
        print_chain("      ");
    }

    printf("46탐색: %p\n", search_chain(46));
    printf("39탐색: %p\n", search_chain(39));

    delete_chain(60);	print_chain("60삭제");
    delete_chain(45);	print_chain("45삭제");

    return 0;
}
