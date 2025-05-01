#include <stdio.h>
#include <stdlib.h>

typedef char TElement;
typedef struct BNode {
    TElement data;
    struct BNode* left;
    struct BNode* right;
}TNode;

void preorder (TNode* n)
{
    
}

int count_node (TNode* n)
{

}

int count_leaf(TNode* n)
{

}

int calc_height(TNode* n)
{

}

void reverse(TNode* n)
{

}

calc_level(TNode* n, TNode* key, int level)
{

}

int main (void)
{
    TNode d = { 'D', NULL, NULL };
    TNode e = { 'E', NULL, NULL };
    TNode b = { 'B', &d, &e };
    TNode f = { 'F', NULL, NULL };
    TNode c = { 'C', &f, NULL };
    TNode a = { 'A', &b, &c };
    TNode* root = &a;

    printf(" 트리 : "); preorder(root); printf("\n");
    printf(" 노드의 개수 = %d\n", count_node(root));
    printf(" 단말의 개수 = %d\n", count_leaf(root));
    printf(" 트리의 높이 = %d\n", calc_height(root));
    reverse(root);
    printf(" reverse 트리 : "); preorder(root); printf("\n");
    printf(" D의 레벨 = %D\n", calc_level(root, &d, 1));
    printf(" C의 레벨 = %d\n", calc_level(root, &c, 1));
    printf(" A의 레벨 = %d\n", calc_level(root, &a, 1));

    return 0;
}
