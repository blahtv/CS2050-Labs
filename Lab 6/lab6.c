#include "lab6.h"

/*  Node * initList()
    Returns a pointer to an empty list. 
*/
Node * initList()
{
    Node * list = NULL;
    return list;
}

/* int getSize(Node *list)
    Returns the size of a list. Returns 0 if empty.

    Parameters:
        Node *list : The head of the list
*/
int getSize(Node *list)
{
    int count = 0;
    if(list)
    {
        count++;
        for(Node * currentNode = list->next; currentNode!=NULL; currentNode = currentNode->next)
            count++;
    }
    return count;
}

/* int insertAtHead(Node **list, void *data)
    Inserts a newly created node at the head of the provided list, which stores
    the provided data. Returns 0 on success and a 1 on failure.

    Parameters:
        Node **list : Pointer to the head of the list
        void *data : Data to be stored in the newly created node
*/
int insertAtHead(Node **list, void *data)
{
    Node * node;
    if((node = malloc(sizeof(Node))))
    {
        node->data = data;
        node->next = *list;
        *list = node;
        return 0;
    }
    return 1;
}

/* void * removeFromHead(Node **list)
    Removes the current head of the list provided, if the list is not empty.
    Returns the data stored in the removed node, or NULL if the list is empty.

    Parameters:
        Node **list : Pointer to the head of the list
*/
void * removeFromHead(Node **list)
{
    if(*list)
    {
        Node * newHead = (*list)->next;
        void * data = (*list)->data;
        free(*list);
        *list = newHead;
        return data;
    }
    return NULL;
}

/* void freeList(Node **list)
    Frees memory allocated for the entirity of the list provided. Sets the value
    of the pointer provided to NULL.

    Parameters:
        Node **list : Pointer to the head of the list
*/
void freeList(Node **list)
{
    Node * currentNode = *list;
    for(Node * nextNode; currentNode!=NULL; currentNode = nextNode)
    {
        nextNode = currentNode->next;
        free(currentNode);
    }
    *list = NULL;
}


/* Car * getWithMostMilesDriven(Node *list)
    Returns a pointer to the car with the most miles driven in a provided list. If multiple have
    the most, returns the first occurance. Returns NULL if the list is empty.

    Parameters:
        Node *list : The head of the list, assumed to contain Car pointers
*/
Car * getWithMostMilesDriven(Node *list)
{
    if(!list)
        return NULL;
    Car * firstCar = (Car*)list->data;
    int mostMiles = firstCar->milesDriven;
    Car * carWithMostMiles = firstCar;
    for(Node * currentNode = list; currentNode!=NULL; currentNode = currentNode->next)
    {
        Car * currentCar = currentNode->data;
        int currentMiles = currentCar->milesDriven;
        if(currentMiles > mostMiles)
        {
            mostMiles = currentMiles;
            carWithMostMiles = currentCar;
        }
    }
    return carWithMostMiles;
}

/* void printCars
    Prints out the VIN, miles driven, and the number of accidents of each car in a provided list.

    Parameters:
        Node *list : The head of the list, assumed to contain Car pointers
*/
void printCars(Node *list)
{
    if(list)
    {
        for(Node * currentNode = list; currentNode!=NULL; currentNode = currentNode->next)
        {
            Car * currentCar = currentNode->data;
            int VIN = currentCar->vin;
            float milesDriven = currentCar->milesDriven;
            int numberOfAccidents = currentCar->numberOfAccidents;
            printf("VIN: %d Miles Driven: %f Number of Accidents: %d\n", VIN, milesDriven, numberOfAccidents);
        }
    }
}