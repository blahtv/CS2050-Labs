#include "lab2.h"

/*  CreateIntArrayFromFile

    This function creates a dyanmic array via reading from a file containing only integers. 
    The size of the array is assumed to be the first number in the file and is saved
    to a pointer for future use.
    All subsequent integers are saved in sequential order to a newly created array,
    returning NULL if the array is not able to be created, or the array itself on a success.

    Parameters:
    FILE *file : The file pointer to be read from
    int *size : An integer pointer to be returned to the calling function containing the array size.

*/

int * createIntArrayFromFile(FILE *file, int *size)
{
    fscanf(file, "%d", size);
    int * array = malloc(sizeof(int) * *size);
    if(!array)
        return NULL;
    for(int i = 0; i < *size; i++)
    {
        fscanf(file, "%d", array);
        array++;
    }
    array-=*size; //Reset the pointer back to element 0
    return array;
}

/*  firstAddressOf

    This function searches an array for a target number, and, if found, saves
    the address of the target to another pointer. If the element is found, returns 1. 
    Else, returns 0.

    Parameters:
    int *array : The array to be searched
    int size : The size of said array, assumed to be accurate
    int **result : The pointer of an address, to be set to the first address of the found element
    int element : The target query to be searched for in the array; may or may not be in the array

*/

int firstAddressOf(int *array, int size, int **result, int element)
{
    int found = 0;
    for(int i = 0; i < size; i++)
    {
        if(array[i]==element)
        {
            found = 1;
            *result = &array[i];
            return found; //Must return immediately to keep the first time element is found
        }
    }
    return found;
}

/* freeArray

    This function frees the memory of a given int array

    Parameters:
    int *array : The int array to be freed

*/

void freeArray(int *array)
{
    free(array);
}

