#include "lab4.h"

/* createIntArray
    Creates an int array with a size provided by the calling function. Stores the size of the 
    created array before the array. Returns the array on success, and NULL on failure. 

    Parameters: 
        size_t size - The size of the array to be created

*/
int * createIntArray(size_t size)
{
    size_t * array = malloc(sizeof(size_t)+(sizeof(int)*size));
    if(array)
    {
        array[0] = size;
        array++;
        return (int*)array;
    }
    return NULL;
}

/* getSize
    Returns the size of an int array as a size_t.

    Parameters:
        int* array - The array to determine the size of. Assumed to have been successfully 
                     created by createIntArray
*/
size_t getSize(int *array)
{
    size_t * tempArray = (size_t*)array;
    return tempArray[-1];
}

/* printArray
    Prints the contents of an int array, on a single line.

    Parameters:
        int* array - The array to print. Assumed to have been successfully created by createIntArray

*/
void printArray(int *array)
{
    int size = getSize(array);
    for(int i = 0; i < size; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}

/* sumEvenIndices
    Returns the sum of the elements at even indexes in an int array.

    Parameters:
        int* array - The array used to find the even indices. Assumed to have been successfully created 
                     by createIntArray
*/
int sumEvenIndices(int *array)
{
    int sum = 0;
    int size = getSize(array);
    for(int i = 0; i < size; i+=2)
    {
        sum+= array[i];
    }
    return sum;
}

/* freeArray
    Frees an array created by the createIntArray function.

    Parameters:
        int* array - The array to be freed. Assumed to have been successfully created by createIntArray.
*/
void freeArray(int *array)
{
    size_t * tempArray = (size_t*) array;
    tempArray--;
    free(tempArray);
}