#include <stdio.h>
#include <stdlib.h>

typedef char TElement;
typedef struct TNode {
    TElement data;
    struct TNode* left;
    struct TNode* right;
} TNode;

#define VisitNode(n) (printf("[%c] ", (n)->data))

void preorder(TNode* n) // 전위순회 (루트, 왼쪽, 오른쪽)
{
    if (n != NULL)
    {
        VisitNode(n);
        preorder(n->left);
        preorder(n->right);
    }
}

void inorder(TNode* n) // 중위순회 (왼쪽, 루트, 오른쪽)
{
    if (n != NULL)
    {
        inorder(n->left);
        VisitNode(n);
        inorder(n->right);
    }
}

void postorder(TNode* n) // 후위순회 (왼쪽, 오른쪽, 루트)
{
    if (n != NULL)
    {
        postorder(n->left);
        postorder(n->right);
        VisitNode(n);
    }
}

#define MAX_SIZE 100
typedef TNode* Element;
#include "CircularQueue.h"

void levelorder(TNode* root) // 레벨 순회
{
    if (root != NULL)
    {
        init_queue();
        enqueue(root);
        while(!is_empty())
        {
            TNode* n = dequeue();
            if (n != NULL)
            {
                VisitNode(n);
                enqueue(n->left);
                enqueue(n->right);
            }
        }
    }
}

int main(void)
{
    TNode d = { 'D', NULL, NULL };
    TNode e = { 'E', NULL, NULL };
    TNode b = { 'B', &d, &e };
    TNode f = { 'F', NULL, NULL };
    TNode c = { 'C', &f, NULL };
    TNode a = { 'A', &b, &c };
    TNode* root = &a;

    printf("\n   In-order : ");
    inorder(root);
    printf("\n  Pre-Order : ");
    preorder(root);
    printf("\n Post-Order : ");
    postorder(root);
    printf("\nLevel-Order : ");
    levelorder(root);

    return 0;
}
