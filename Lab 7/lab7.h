#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

struct Node {
	void *data;
	Node *next;
};

Node * initList();
int getSize(Node *list);
int insertAtIndex(Node *list, void *data, int index);
int insertAtTail(Node *list, void *data);
void * getAtIndex(Node *list, int index);
void * removeAtIndex(Node *list, int index);
void freeList(Node **list);
