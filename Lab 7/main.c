#include "lab7.h"

void printList(Node * list, int size)
{
    printf("My List:\n");
    for(int i = 0; i < size; i++)
    {
        int value = *((int*)(getAtIndex(list, i)));
        printf("%d\n", value);
    }
}

int main()
{
    Node * myList = initList();
    printList(myList, getSize(myList));
    printf("Size: %d\n\n", getSize(myList)); //Prints nothing
    int w = 8;
    int x = 2;
    int y = 3;
    int z = 4;

    printf("Empty List:\n");
    insertAtIndex(myList, &x, 1);
    printList(myList, getSize(myList));
    printf("Size: %d\n\n", getSize(myList));

    printf("Should print 2:\n");
    insertAtIndex(myList, &x, 0); //Adds x to the empty list
    printList(myList, getSize(myList));
    printf("Size: %d\n\n", getSize(myList));

    printf("Should print 2:\n");
    insertAtIndex(myList, &y, -1); //Does nothing
    printList(myList, getSize(myList));
    printf("Size: %d\n\n", getSize(myList));

    printf("Should print 2, then 3:\n");
    insertAtIndex(myList, &y, 1); //Adds y to the tail of the list
    printList(myList, getSize(myList));
    printf("Size: %d\n\n", getSize(myList));

    printf("Should print 2, then 4, then 3\n");
    insertAtIndex(myList, &z, 1); //Adds z to the middle of the list
    printList(myList, getSize(myList));
    printf("Size: %d\n\n", getSize(myList));

    printf("Should print 2, then 4, then 8, then 3\n");
    insertAtIndex(myList, &w, 2); //Adds w to the third term of the list
    printList(myList, getSize(myList));
    printf("Size: %d\n\n", getSize(myList));

    printf("Should print 2, then 4, then 3\n");
    removeAtIndex(myList, 2); //Removes w
    printList(myList, getSize(myList));
    printf("Size: %d\n\n", getSize(myList));

    printf("Should print 2, then 4, then 2, then 3\n");
    insertAtIndex(myList, &x, 2); //Adds x to the third term of the list
    printList(myList, getSize(myList));
    printf("Size: %d\n\n", getSize(myList));

    freeList(&myList);
}
