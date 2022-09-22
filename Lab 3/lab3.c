#include "lab3.h"

/* createCenteredArray

    This function creates an array of a given size, and, if odd, returns a pointer to the middle element 
    of the array. This makes it so half the array elements have a "negative" index, and the other half has
    a "positive" index, with a 0th element in the middle. Returns null if the array cannot be created due
    to the user inputting an even size, a size less than 0, or if malloc fails.

    Parameters:
        int size : An integer provided by the user corresponding to the size of the array that should be created
*/

int * createCenteredArray(int size)
{
    if(size%2 && size > 0)
    {
        int allocSize = sizeof(int) * size;
        int * array = malloc(allocSize);
        printf("Original Pointer: %p\n", array);
        int midpoint = (size/2);
        array+=midpoint;
        return array;
    }
    return NULL;
    
}

/* getAtIndex

    This function takes in an array created by the createCenteredArray function, and allows the user to get the contents of
    an element via its index. Returns the contents of the array if the index is within bounds, and returns 1 otherwise.

    Parameters:
        int *array : An array passed by the user, assumed to have been successfully created by createCenteredArray()
        int size : An integer corresponding to the size of the array
        int index : An integer corresponding to the index of the array the user wishes to obtain the contents of
*/

int getAtIndex(int *array, int size, int index)
{
    int midpoint = size/2;
    if(index >= 0-midpoint && index <= 0+midpoint)
        return array[index];
    return 1;
}

/* averageLowerHalf

    This function takes all the elements indexed 0 and below (within bounds) of an array created by the createCenteredArray
    function, and returns the average value of their respective contents.

    Parameters:
        int *array : An array passed by the user, assumed to have been successfully created by createCenteredArray()
        int size : An integer corresponding to the size of the array
*/
float averageLowerHalf(int *array, int size)
{
    float midpoint = size/2;
    float avg = 0;
    for(int i = 0 - midpoint; i <= 0; i++)
    {
        avg+=getAtIndex(array, size, i);
    }
    avg = avg/(midpoint+1);
    return avg;
}

/* freeCenteredArray

    This function frees an array created by the createCenteredArray function

    Parameters:
        int *array : An array passed by the user, assumed to have been successfully created by createCenteredArray()
        int size : An integer corresponding to the size of the array
*/
void freeCenteredArray(int *array, int size)
{
    int midpoint = size/2;
    array = array - midpoint;
    printf("Pointer that's about to be free'd: %p\n", array);
    free(array);
}