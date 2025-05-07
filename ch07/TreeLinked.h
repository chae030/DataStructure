#include <stdio.h>
#include <stdlib.h>

typedef struct TNode {
	TElement        data; 
	struct TNode*   left;  
	struct TNode*   right;
} TNode;

TNode* create_tree(TElement data, TNode* left, TNode* right)
{
    TNode* n = (TNode*)malloc(sizeof(TNode));
    n->data = data;
    n->left = left;
    n->right = right;
    return n;
}
void delete_tree(TNode* n)
{
    if (n != NULL) {
        delete_tree(n->left);
        delete_tree(n->right);  
        free(n);              
    }
}
