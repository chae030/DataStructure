#include <stdio.h>
#include <string.h>

typedef char TElement;
typedef struct TNode {
    TElement data;
    struct TNode* left;
    struct TNode* right;
} TNode;

// 이진 트리의 노드 수 구하기
int count_node(TNode* n)
{
    if (n == NULL)
        return 0;
    else return 1 + count_node(n->left) + count_node(n->right);
}

// 이진 트리의 높이 구하기
#define MAX(a,b)    ((a)>(b) ? (a):(b))
int calc_height(TNode* n)
{
    if(n == NULL) return 0;
    else return 1 + MAX(calc_height(n->left), calc_height(n->right));
}

// 트리를 좌우로 대칭시키기
void reverse(TNode* p)
{
    if (p != NULL)
    {
        TNode* tmp = p->left;
        p->left = p->right;
        p->right = tmp;

        reverse(p->left);
        reverse(p->right);
    }
}

// 노드의 레벨 구하기
int calc_level(TNode* n, TNode* key, int level)
{
    if (n == NULL) return 0;
    if (n == key) return level;

    int lev = calc_level(n->left, key, level+1);
    if (lev > 0) return lev;
    return calc_level(n->right, key, level + 1);
}
