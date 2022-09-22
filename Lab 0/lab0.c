#include "lab0.h"

/* countOccurrences
        This function takes in an array, the size of said array 
        represented by an int, and a query number as parameters.
        The function goes through each element of the array,
        and returns a count of the amount of times the query
        integer appears as a member of the array.

        Parameters:
        int size --> The size of the array being passed (param 2)
        int data[] --> The array to be searched
        int query --> The number to be searched for in the array
*/

int countOccurrences(int size, int data[], int query)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if(data[i]==query)
            count++;
    }
    return count;
}