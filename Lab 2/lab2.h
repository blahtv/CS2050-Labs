#include <stdio.h>
#include <stdlib.h>

int * createIntArrayFromFile(FILE *file, int *size);
int firstAddressOf(int *array, int size, int **result, int element);
void freeArray(int *array);
