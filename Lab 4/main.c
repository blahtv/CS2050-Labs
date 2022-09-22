#include "lab4.h"

int main()
{
    size_t size = 9;
    int * myArray = createIntArray(size);
    printf("Size: %ld\n", getSize(myArray));
    for(int i = 0; i < size; i++)
    {
        myArray[i] = i+5;
    }
    printArray(myArray);
    printf("Sum of even indexes: %d\n", sumEvenIndices(myArray));
    freeArray(myArray);
}