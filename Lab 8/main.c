#include "lab8.h"

typedef struct Node {
	void *data;
	struct Node *next;
} Node;

struct Queue {
	int size;
	Node *head;
	Node *tail;
};


int main()
{
    Queue * q = initQueue();
    printf("Size (Should be 0): %d\n", getSize(q));
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;

    enQueue(q, &a);
    printf("Size (Should be 1): %d\n", getSize(q));
    deQueue(q);
    printf("Size (Should be 0): %d\n", getSize(q));
    enQueue(q, &a);
    enQueue(q, &b);
    enQueue(q, &c);
    enQueue(q, &d);
    enQueue(q, &e);
    printf("Size (Should be 5): %d\n", getSize(q));
    printf("First queued: %d\n", *((int*)peek(q)));
    printf("First dequeued: %d\n", *((int*)deQueue(q)));
    printf("Second dequeued: %d\n", *((int*)deQueue(q)));
    printf("Third dequeued: %d\n", *((int*)deQueue(q)));
    printf("Fourth dequeued: %d\n", *((int*)deQueue(q)));
    printf("Fifth dequeued: %d\n", *((int*)deQueue(q)));
    printf("Size (Should be 0): %d\n", getSize(q));

    enQueue(q, &d);
    printf("Peek (Should be 4): %d\n", *((int*)peek(q)));
    deQueue(q);

    printf("Peek (Should be nil): %p\n", peek(q));
    printf("Dequeue (Should be nil): %p\n", deQueue(q));

    freeQueue(q);
    //printf("Empty q (should be nil): %p\n", q->head);

    //enQueue(q, &a); //Everything past here should do nothing
    //deQueue(q);
    //peek(q);
}
