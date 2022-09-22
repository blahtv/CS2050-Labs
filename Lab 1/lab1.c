#include "lab1.h"
/*avgOdd
    This function takes in an array, the size of the array, and the pointer of a float
    to where the calculated average is to be stored. Searches the array for all odd
    values, and averages them. Returns 1 on a successful average, and returns 0 if
    no odd numbers are found in the array.

    Parameters:
    int *array : The array of integer values provided by the user (assumed to have at least 1 element)
    int size : The size of said array represented as an int
    float *result : The pointer to where the calculated average is to be stored as a float
*/


int avgOdd(int *array, int size, float *result)
{
    float runningTotal = 0; //The running summation of all odd numbers found in the array
    int numberOfOdds = 0; //The number of odd numbers found in the array

    for(int i = 0; i < size; i++) //Loops through every element in the array
    {
        if((*array)%2==1) //Determines if the current element in the array is odd
        {
            runningTotal += *array;
            numberOfOdds++;
        }
        array++;
    }
    
    if(result && numberOfOdds != 0) //Determines if any odd numbers were encountered (prevents a divide by 0)
    {
        *result = (runningTotal/numberOfOdds); //Computes the average of all odd numbers and stores it in the float pointer
        return 1;
    }
    return 0; //No odd numbers in the array, return 0
}
