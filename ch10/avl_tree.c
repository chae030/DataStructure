#include <stdio.h> 
#include <stdlib.h> 

typedef int TElem;

typedef struct BinTrNode {
	TElem			data;
	struct BinTrNode*	left;
	struct BinTrNode*	right;
} TNode;

TNode* create_node(TElem val, TNode* l, TNode* r)
{
	TNode* n = (TNode*)malloc(sizeof(TNode));
	n->data = val;
	n->left = l;
	n->right = r;
	return n;
}

void preorder(TNode* n)
{
	if (n != NULL) {
		printf("(");
		printf("%d ", n->data);
		preorder(n->left);
		preorder(n->right);
		printf(")");
	}
    else printf(". ");
}

TNode* search_BST(TNode* root, int key)
{
	if (root == NULL)
		return NULL;

	if (root->data == key)
		return root;
	else if (key < root->data)
		return search_BST(root->left, key);
	else
		return search_BST(root->right, key);
}

int calc_height(TNode* n)
{
    if (n == NULL) return 0;

    int lh = calc_height(n->left);
    int rh = calc_height(n->right);
    return (lh > rh) ? lh + 1 : rh + 1;
}

int calc_balance(TNode* n) {
    if (n == NULL) return 0;
    else return calc_height(n->left) - calc_height(n->right);
}
TNode* rotateLL(TNode* A) {
    TNode* B = A->left;
    A->left = B->right;
    B->right = A;
    return B;
}
TNode* rotateRR(TNode* A) {
    TNode* B = A->right;
    A->right = B->left;
    B->left = A;
    return B;
}
TNode* rotateRL(TNode* A) {
    TNode* B = A->right;
    A->right = rotateLL(B);
    return rotateRR(A);
}
TNode* rotateLR(TNode* A) {
    TNode* B = A->left;
    A->left = rotateRR(B);
    return rotateLL(A);
}

TNode* insert_AVL(TNode* root, int key)
{
    if (root == NULL)
        return create_node(key, NULL, NULL);
    if (key < root->data)
        root->left = insert_AVL(root->left, key);
    else if (key > root->data)
        root->right = insert_AVL(root->right, key);
    else return root;

    int balance = calc_balance(root);

    if (balance > 1) {
        if (key < root->left->data)
            return rotateLL(root);
        else return rotateLR(root);
    }
    else if (balance < -1) {
        if (key < root->right->data)
            return rotateRL(root);
        else return rotateRR(root);
    }
    return root;
}

int main(void)
{
	TNode* root = NULL, * node;
	int keys[] = { 7, 8, 9, 2, 1, 5, 3, 6, 4 };

	for (int i = 0; i < 9; i++) {
		root = insert_AVL(root, keys[i]);
		printf("\n  삽입%2d: ", keys[i]);
		preorder(root);
	}
	printf("\n");
	printf(" 트리의 균형인수 = %d\n", calc_balance(root));

	node = search_BST(root, 9);
	printf(" 9 탐색: %s\n", (node != NULL) ? "성공" : "실패");
	node = search_BST(root, 10);
	printf("10 탐색: %s\n", (node != NULL) ? "성공" : "실패");

    return 0;
}
