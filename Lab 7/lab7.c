#include "lab7.h"

/* Node * initList()
    Returns a pointer to an empty list containing a dummy node, which holds the size of the list.
    Returns NULL if not enough memory is available for the node or the data it holds.
*/
Node * initList()
{
    Node * dummy = malloc(sizeof(Node));
	if(!dummy)
		return NULL;
    dummy->data = malloc(sizeof(void*));
    if(!dummy->data)
    {
        free(dummy);
        return NULL;
    }
	int size = 0;
	*((int*)(dummy->data)) = size;
	return dummy;
}

/* int getSize(Node * list)
    Returns the size of the linked list stored in the dummy node, or 0 if the list
    is NULL.

    Parameters:
        Node *list : The head of the linked list
*/
int getSize(Node *list)
{
    if(!list)
        return 0;
    return *((int*)(list->data));
}

/* int insertAtIndex(Node *list, void *data, int index)
    Creates a new node and stores the given data at an index provided by the user.
    Returns 0 if the node is successfully created and inserted, or 1 if the node can't
    be created, the list is NULL, or if the index is invalid. If the index is equal to the list size, the node
    is inserted at the tail of the list.

    Parameters:
        Node *list : The head of the linked list
        void *data : The data to be stored in the newly created node.
        int index : The index at which to insert the node, expected to be between 0 and the list's size.
*/
int insertAtIndex(Node *list, void *data, int index)
{
    if(!list)
        return 1;
    int size = getSize(list);
	if(index > size || index < 0)
		return 1;
	if(index == size)
		return insertAtTail(list, data); //Inserts the node at the tail if the index given is the size
	Node * node = malloc(sizeof(Node));
	if(!node)
		return 1;
	node->data = data;
	Node * currentNode;
	int i = 0;
    for(currentNode = list; currentNode->next != NULL; currentNode = currentNode->next)
	{
		if(i == index)
		{
			node->next = currentNode->next;
			currentNode->next = node;
            *((int*)(list->data)) = getSize(list)+1;
            return 0;
		}
		i++;
	}
	return 1;
}

/* int insertAtTail(Node *list, void *data)
    Creates a new node and stores the given data at the tail of the list provided by the user.
    Returns 0 if the node is successfully created and stores, or 1 if the node couldn't be created
    or if the list is NULL.

    Parameters:
        Node * list : The head of the linked list
        void * data : The data to be stored in the newly created node.
*/
int insertAtTail(Node *list, void *data)
{
    if(!list)
        return 1;
    Node * node = malloc(sizeof(Node));
    if(!node)
        return 1;
    Node * currentNode;
    for(currentNode = list; currentNode->next != NULL; currentNode = currentNode->next){}
    currentNode->next = node;
    node->data = data;
    node->next = NULL;
    *((int*)(list->data)) = getSize(list)+1;
    return 0;
}

/*void getAtIndex(Node *list, int index)
    Returns the value of a node stored at a specific index.
    Returns NULL if the index is invalid or if the list is NULL.

    Parameters:
        Node * list : The head of the linked list
        int index : The index of the node to be accessed.
*/
void * getAtIndex(Node *list, int index)
{
    if(!list)
        return NULL;
    int size = getSize(list);
    if(index > size-1 || index < 0)
        return NULL;
    int i = 0;
    Node * currentNode;
    for(currentNode = list->next; currentNode != NULL; currentNode = currentNode->next)
    {
        if(i == index)
            return currentNode->data;
        i++;
    }
    return NULL;
    
}

/* void * removeAtIndex(Node * list, int index)
    Removes and frees a node located at a specific index provided by the user. Returns NULL
    if the index is invalid or if the list is NULL. Returns the data stored in the removed node
    if the removal is successful.

    Parameters:
        Node * list : The head of the linked list
        int index : The index of the node to be removed.
*/
void * removeAtIndex(Node *list, int index)
{
    if(!list)
        return NULL;
    int size = getSize(list);
    if(index > size-1 || index < 0)
        return NULL;
    Node * nodeBefore;
    int i = -1;
    for(nodeBefore = list; nodeBefore->next!=NULL; nodeBefore = nodeBefore->next)
    {
        if(i+1 == index)
        {
            Node * nodeToRemove = nodeBefore->next;
            nodeBefore->next = nodeToRemove->next;
            void * data = nodeToRemove->data;
            free(nodeToRemove);
            *((int*)(list->data)) = getSize(list)-1;
            return data;
        }
        i++;
    }
    return NULL;
}

/* void freeList(Node **list)
    Frees a linked list and sets it to NULL.

    Parameters:
        Node **list : A pointer to the head of the list.
*/
void freeList(Node **list)
{
    Node * currentNode = *list;
    if(currentNode)
    {
        free(currentNode->data);
        currentNode->data = NULL;
    }
    for(Node * nextNode; currentNode!=NULL; currentNode = nextNode)
    {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = NULL;
    }
    *list = NULL;
}