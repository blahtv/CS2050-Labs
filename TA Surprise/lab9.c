#include "lab9.h"
#include <time.h>
int linearSearch(int* array, int element);

/* int descendingBinarySearch(int *array, int element)
    Searches an array for a specified element if the array is sorted in descending
    order. Returns -1 if the array is not sorted or if the element does not appear
    in the array, or the index of the element if the array is sorted and it appears
    in the array.

    Parameters:
        int *array : The array to be searched, ideally in descending order
        int element: The element to be searched for in the array.
*/
int descendingBinarySearch(int *array, int element)
{
    if(isSortedDescending(array))
    {
        int first = 0;
        int last = getSize(array) - 1;
        int mid;
        clock_t t = clock();
        while(first<=last)
        {
            mid = (first+last)/2;
            if(element == array[mid])
            {
                t = clock() - t;
                printf("Program Execution took %f seconds\n", (float)t/CLOCKS_PER_SEC);
                return mid;
            }
            else if(element > array[mid])
                last = mid-1;
            else if(element < array[mid])
                first = mid+1;
        }
    }
    return -1;
}

/* int linearSearch(int * array, int element)
    Searches an array for a specified element. Returns -1 if the element does not appear in
    the array, or the index of the element if it appears in the array.

    Parameters:
        int *array : The array to be searched
        int element: The element to be searched for in the array.
*/

int linearSearch(int *array, int element)
{
	int size = getSize(array);
    clock_t t = clock();
    for(int i = 0; i < size -1; i++)
    {
        if(array[i]==element)
        {
            t = clock() - t;
            printf("Program Execution took %f seconds\n", (float)t/CLOCKS_PER_SEC);
            return i;
        }
    }
    return -1;
}


/* int isSortedDescending(int *array)
    Determines whether or not an array is in descending order.
    Returns 1 if so, 0 if not.

    Parameters:
        int *array : The array in question.
*/
int isSortedDescending(int *array)
{
    int size = getSize(array);
    for(int i = 0; i < size - 1; i++)
    {
        if(array[i] < array[i+1])
            return 0;
    }
    return 1;
}




//Starter Code from lab 9
/*int main() {
    int * a = createArray(sizeof(int), 6);
    printf("Size: %d\n", getSize(a));
    a[0] = 5;
    a[1] = 4;
    a[2] = 3;
    a[3] = 2;
    a[4] = 1;
    a[5] = 0;

    printf("Sorted? : %d\n", isSortedDescending(a));
    printf("\nBINARY SEARCH\n");
    for(int i = 0; i < 7; i++)
    {
        printf("Index of %d : %d\n", i, descendingBinarySearch(a, i));
    }

    printf("\nLINEAR SEARCH\n");
    for(int i = 0; i < 7; i++)
    {
        printf("Index of %d : %d\n", i, linearSearch(a, i));
    }

    freeArray(a);
}*/

void * createArray(size_t elementSize, int numElements) {
	int *array = malloc(sizeof(int) + elementSize * numElements);

	if(!array) {
		return NULL;
	}

	*array = numElements;

	return ++array;
}

void freeArray(void *array) {
	int *arr = array;
	free(arr - 1);
}

int getSize(int *array) {
	return array[-1];
}
