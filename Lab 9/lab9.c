#include "lab9.h"

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
        while(first<=last)
        {
            mid = (first+last)/2;
            if(element == array[mid])
                return mid;
            else if(element > array[mid])
                last = mid-1;
            else if(element < array[mid])
                first = mid+1;
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