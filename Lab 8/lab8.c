#include "lab8.h"

// -------------------------------- STRUCT DEFINITIONS

typedef struct Node Node;

// suggested implementation
struct Queue {
	int size;
	Node *head;
	Node *tail;
};

struct Node {
	void *data;
	Node *next;
};

//-----------------------------------

/* Queue * initQueue()
    Returns a pointer to an initialized Queue struct. Returns NULL
    if the struct cannot be allocated.
*/

Queue * initQueue()
{
    Queue * q = malloc(sizeof(Queue));
    if(!q)
        return NULL;
    Node * head = malloc(sizeof(Node));
    if(!head)
        return NULL;
    q->head = head;
    q->tail = head;
    head->next = NULL;
    q->size = 0;
    return q;
}

/* int getSize(Queue *q)
    Returns the size of a queue struct. If the queue is NULL, returns 0.

    Parameters:
        Queue * q : A pointer to the queue struct.
*/

int getSize(Queue *q)
{
    if(!q)
        return 0;
    return q->size;
}

/* int enQueue(Queue *q, void *data)
    Enqueues a newly created node into the queue which stores the provided data.
    Returns 0 if successfully accomplished, or 1 if the Queue is NULL or if the new
    Node could not be successfully created.

    Parameters:
        Queue *q : A pointer to the queue struct.
        void *data : A pointer to the data to be inserted into the new node.
*/

int enQueue(Queue *q, void *data)
{
    if(!q)
        return 1;
    if(!q->head)
        return 1;
    Node * newNode = malloc(sizeof(Node));
    if(!newNode)
        return 1;
    newNode->data = data;
    newNode->next = NULL;
    q->tail->next = newNode;
    q->tail = newNode;
    q->size = q->size + 1;
    return 0;
}

/* void * peek(Queue *q)
    Returns the data stored in the front of the queue, without removing it from the queue.
    Returns NULL if the queue is empty or NULL.

    Parameters:
        Queue *q : A pointer to the queue struct.
*/

void * peek(Queue *q)
{
    if(!q)
        return NULL;
    if(!q->head)
        return NULL;
    if(q->head->next)
    {
        return q->head->next->data;
    }
    return NULL;
}

/* void * deQueue(Queue *q)
    Dequeues the node in the front of the queue, and returns its respective data.
    Returns NULL if the queue is empty or NULL.

    Parameters:
        Queue *q : A pointer to the queue struct.
*/

void * deQueue(Queue *q)
{
    if(!q)
        return NULL;
    if(!q->head)
        return NULL;
    if(q->head->next)
    {
        Node * nodeToRemove = q->head->next;
        q->head->next = nodeToRemove->next;
        void * data = nodeToRemove->data;
        free(nodeToRemove);
        q->size = q->size-1;
        if(q->size == 0) //Just removed the tail, so set the tail back to the dummy node
            q->tail = q->head;
        return data;
    }
    return NULL; //The list is empty, nothing to dequeue
}

/* void freeQueue(Queue *q)
    Frees a given queue struct and all its nodes.

    Parameters:
        Queue *q : A pointer to the queue struct.
*/

void freeQueue(Queue *q)
{
    if(!q)
        return;
    if(!q->head)
        return;
    Node * currentNode = q->head;
    for(Node * nextNode; currentNode != NULL; currentNode = nextNode)
    {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = NULL;
    }
    free(q);
}
