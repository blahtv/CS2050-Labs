#include "lab3.h"

int main()
{
    int size = 5;
    int * array = createCenteredArray(size);
    for(int i = -8; i < 8; i++)
    {
        if(i >= 0-(size/2) && i <= 0+(size/2))
            array[i]=i;
        printf("%d\n",getAtIndex(array,size,i));
    }
    printf("Avg of lower half: %f\n", averageLowerHalf(array, size));
    freeCenteredArray(array, size);

}