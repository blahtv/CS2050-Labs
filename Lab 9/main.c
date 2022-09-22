#include "lab9.h"

int main() {
    int * a = createArray(sizeof(int), 6);
    printf("Size: %d\n", getSize(a));
    a[0] = 5;
    a[1] = 4;
    a[2] = 3;
    a[3] = 2;
    a[4] = 1;
    a[5] = 0;

    printf("Sorted? : %d\n", isSortedDescending(a));
    for(int i = 0; i < 7; i++)
    {
        printf("Address of %d : %d\n", i, descendingBinarySearch(a, i));
    }
    freeArray(a);
}

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
