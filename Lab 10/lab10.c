#include "lab10.h"

// suggested implementation
typedef struct Node Node;

struct Node {
	int data;
	Node *left;
	Node *right;
};

struct BST{
	Node *root;
	int size;
};

/* BST * initBST()   
	Initalizes an empty binary search tree pointer. Returns NULL on failure.
*/
BST * initBST()
{
	BST * tree = malloc(sizeof(BST));
	if(!tree)
		return NULL;
	tree->size = 0;
	tree->root = NULL;
	return tree;
}

/* int insertNode(Node * parentNode, Node * newNode)
	Helper function for insertBST that handles recursion.
	Determines the 'branch' of the binary search tree to go down,
	and inserts the node in its correct location. Returns 0 on
	success, and 1 on failure.

	Parameters: 
		Node * parentNode : The node to compare to
		Node * newNode : The node to be inserted

*/
int insertNode(Node * parentNode, Node * newNode)
{
	int parentData = parentNode->data;
	int newData = newNode->data;
	if(newData < parentData)
    {
        if(parentNode->left)
            insertNode(parentNode->left, newNode);
        else
            parentNode->left = newNode;
        return 0;
    }
    if(newData > parentData)
    {
        if(parentNode->right)
            insertNode(parentNode->right, newNode);
        else
            parentNode->right = newNode;
        return 0;
    }
	return 1;
}

/* int insertBST(BST *tree, int data)
	Inserts a new node into a binary search tree with the
	given data. Returns 0 on a success, or a 1 on failure.
	Duplicates do not get inserted and returns 1.

	Parameters:
		BST *tree : The binary search tree object
		int data : The integer data to be stored in the new node.
*/
int insertBST(BST *tree, int data)
{
	if(!tree)
		return 1;
	Node * node = malloc(sizeof(Node));
	if(!node)
		return 1;
	node->data = data;
	node->left = node->right = NULL;
	if(!(tree->root))
	{
		tree->root = node;
		tree->size = tree->size +  1;
		return 0;
	}
	int inserted = insertNode(tree->root, node);
	if(inserted == 0)
		tree->size = tree->size + 1;
	return inserted;
}

/* int BSTContains(BST *tree, int data)
	Determines whether the given data is contained within the
	given binary search tree. Returns 1 if found, 0 if not.

	Parameters:
		BST *tree : The binary search tree to be searched
		int data : The ineteger data to be searched for
*/
int BSTContains(BST *tree, int data)
{
	if(tree)
    {
        Node * top = tree->root;
        while(top)
        {
            if(data < top->data)
                top = top->left;
            else if(data > top->data)
                top = top->right;
            else
                return 1;
        }
        return 0;
    }
    return 0;
}

/* void freeNodes(Node * node)
	Helper function for freeTree that handles recursion.
	Frees all the child nodes of a parent node, and then
	the parent node itself.

	Parameters: Node * node : The parent node
*/
void freeNodes(Node * node)
{
	if(!node)
		return;
	freeNodes(node->left);
	freeNodes(node->right);
	free(node);
}

/* void freeTree(BST *tree)
	Frees a binary search tree and all the node within.

	Parameters: BST *tree : The binary search tree to be freed.
*/
void freeTree(BST *tree)
{
	freeNodes(tree->root);
	free(tree);
}

/* void printNodes(Node * node)
	Helper function for printInOrder that handles recursion.
	Prints all the nodes of a BST in ascending order.

	Parameters: Node * node : A parent node
*/
void printNodes(Node * node)
{
	if(!node)
		return;
	printNodes(node->left);
	printf("%d\n", node->data);
	printNodes(node->right);
}

/* void printInOrder(BST *tree)
	Prints all the elements of a binary search tree in ascending order.

	Parameters: BST *tree : The binary search tree to print
*/
void printInOrder(BST *tree)
{
	if((!tree) || !(tree->root))
		return;
	printNodes(tree->root);
}

/* int getMax(BST *tree)
	Returns the largest element in a binary search tree. Assumes that the tree
	is not empty.

	Parameters: BST *tree : The binary search tree
*/
int getMax(BST *tree)
{
	Node * node = tree->root;
	while(node->right)
	{
		node = node->right;
	}
	return node->data;
}