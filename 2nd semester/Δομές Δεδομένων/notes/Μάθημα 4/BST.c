#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int BinTreeElementType;
typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
	BinTreeElementType data;
	BinTreeNode* LChild;
	BinTreeNode* RChild;
} BinTreeNode;

void CreateBinTree(BinTreeNode **root)
{
	*root = NULL;
}

bool EmptyBinTree(BinTreeNode *root)
{
	return (root == NULL); 
}

BinTreeNode *BinTreeSearch(BinTreeNode *node, int elem)
{
	if (node == NULL)
		return NULL;
	else if (node->data == elem)
		return node;
	else if (node->data < elem)
		return BinTreeSearch(node->RChild, elem);
	else if (node->data > elem)
		return BinTreeSearch(node->LChild, elem);
}

BinTreeElementType BinTreeMaxValue(BinTreeNode *node)
{
	if (node == NULL)
		return -1;
	if (node->RChild != NULL)
		return BinTreeMaxValue(node->RChild);
	else
		return node->data;
}

BinTreeElementType BinTreeMinValue(BinTreeNode *node)
{
	if (node == NULL)
		return -1;
	if (node->LChild != NULL)
		return BinTreeMinValue(node->LChild);
	else
		return node->data;
}

BinTreeNode *BinTreeMaxNode(BinTreeNode *node)
{
	if (node == NULL)
		return -1;
	if (node->RChild != NULL)
		return BinTreeMaxNode(node->RChild);
	else
		return node;
}

BinTreeNode *BinTreeMinNode(BinTreeNode *node)
{
	if (node == NULL)
		return -1;
	if (node->LChild != NULL)
		return BinTreeMinNode(node->LChild);
	else
		return node;
}

// Predecessor: Ο μεγαλύτερος κόμβος στο αριστερό υποδέντρο
BinTreeNode *predecessor(BinTreeNode *node)
{
	if (node==NULL)
		return NULL;
	if (node->LChild != NULL)
		return BinTreeMaxNode(node->LChild);
	else
		return NULL;
}

// Successor: Ο μικρότερος κόμβος στο δεξί υποδέντρο
BinTreeNode *successor(BinTreeNode *node)
{
	if (node==NULL)
		return NULL;
	if (node->RChild != NULL)
		return BinTreeMinNode(node->RChild);
	else
		return NULL;
}


void inorder(BinTreeNode *node)
{
	if (node == NULL)
		return;
		
	if (node->LChild != NULL)
		inorder(node->LChild);
	printf("%d ", node->data);
	if (node->RChild != NULL)
		inorder(node->RChild);
}

void preorder(BinTreeNode *node)
{
	if (node!=NULL)
	{
		printf("%d ", node->data);
		if (node->LChild != NULL)
			preorder(node->LChild);
		if (node->RChild != NULL)
			preorder(node->RChild);
	}
}

void postorder(BinTreeNode *node)
{
	if (node == NULL)
		return;
	
	if (node->LChild != NULL)
		postorder(node->LChild);
	if (node->RChild != NULL)
		postorder(node->RChild);
	printf("%d ", node->data);
}

void reverse_order(BinTreeNode *node)
{
	if (node == NULL)
		return;
	
	if (node->RChild != NULL)
		reverse_order(node->RChild);
	printf("%d ", node->data);
	if (node->LChild != NULL)
		reverse_order(node->LChild);
}

int main(void)
{
	BinTreeNode* root;
	CreateBinTree(&root);
	inorder(root);
}

