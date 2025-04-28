#include <stdio.h>
#include <stdlib.h>

typedef char TElement;
typedef struct TNode {
    TElement data;
    struct TNode* left;
    struct TNode* right;
}TNode;

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

void preorder(TNode* n)
{
	if (n != NULL) {
		printf("( ");
		printf("%c ", n->data);
		preorder(n->left);
		preorder(n->right);
		printf(") ");
	}
	else printf(". ");
}

int main(void)
{

    TNode* d = create_tree('D', NULL, NULL);
    TNode* e = create_tree('E', NULL, NULL);
    TNode* b = create_tree('B', d, e);
    TNode* f = create_tree('F', NULL, NULL);
    TNode* c = create_tree('C', f, NULL);
    TNode* root1 = create_tree('A', b, c);
    preorder(root1); printf("\n");

    TNode* D = create_tree('D', NULL, NULL);
    TNode* C = create_tree('C', D, NULL);
    TNode* B = create_tree('B', C, NULL);
    TNode* root2 = create_tree('A', B, NULL);
    preorder(root2); printf("\n");

    delete_tree(root1);
    delete_tree(root2);

    return 0;
}
