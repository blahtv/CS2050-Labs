#include "lab2.h"

int main() {
    FILE *file = fopen("numbers.txt", "r");
    if(!file)
        printf("something happened");
    else
    {
        int size = 0;
        int * array = createIntArrayFromFile(file, &size);
        /*for(int i =0; i< size; i++)
        {
            printf("%d\n",array[i]);
        }*/
        int * myAddress = NULL;
        printf("Success?: %d\n", firstAddressOf(array, size, &myAddress, 3));
        if(myAddress)
        printf("Value: %d", *myAddress);

        free(array);
        printf("%d",array[0]);
        fclose(file);
    }
}

