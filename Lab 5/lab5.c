#include "lab5.h"
/*  createArray
    Creates an array of a given element size and the number of elements that 
    should be in an array. Works for any data type the user provides. Returns the
    array with its size contained before it on success, or NULL on failure.

    Parameters:
        size_t elementSize : The size of the data type being stored in the array
        int numElements : The amount of elements to be stored in the array
*/
void * createArray(size_t elementSize, int numElements)
{
    int * array = malloc(sizeof(int) + (elementSize * numElements));
    if(!array)
        return NULL;
    array[0] = numElements;
    array++;
    return array;
}
/*  getSize
    Returns the size of an array created by the createArray function. Returns 0
    if the user provides a NULL array.

    Parameters:
        void *array : An array created by the createArray function
*/
int getSize(void *array)
{
    if(!array)
        return 0;
    return *(((int*)array)-1);
}

/*  getVin
    Returns the VIN of a car provided by the user. Returns 0 if the user passes a
    NULL car.

    Parameters:
        Car *car : The pointer to the car to get the VIN of
*/
int getVin(Car *car)
{
    if(!car)
        return 0;
    return car->vin;
}
/*  getMilesDriven
    Returns the miles driven of a car provided by the user. Returns 0 if the user
    passes a NULL car.

    Parameters:
        Car *car : The pointer to the car to get the miles driven of
*/
float getMilesDriven(Car *car)
{
    if(!car)
        return 0;
    return car->milesDriven;
}
/*  getNumberOfAccidents
    Returns the numer of accidents of a car provided by the user. Returns 0 if the
    user passes a NULL car.

    Parameters:
        Car *car : The pointer to the car to the get the number of accidents of
*/
int getNumberOfAccidents(Car *car)
{
    if(!car)
        return 0;
    return car->numberOfAccidents;
}
/*  updateMilesDriven
    Adds miles to a car's "miles driven" stat, if the car is not NULL.

    Parameters:
        Car *car : The pointer to the car whose miles is being updated.
        float milesToAdd : The number of miles to add to the car's stat.
*/
void updateMilesDriven(Car *car, float milesToAdd)
{
    if(!car)
        return;
    float currentMiles = getMilesDriven(car);
    float newMiles = currentMiles + milesToAdd;
    car->milesDriven = newMiles;
}
/*  incrementNumberOfAccidents
    Adds 1 to a car's number of accidents, if the car is not NULL.

    Parameters:
        Car *car : The pointer to the car to add one accident to.
*/
void incrementNumberOfAccidents(Car *car)
{
    if(!car)
        return;
    car->numberOfAccidents++;
}

/*  getCarByVIN
    Searches an array of Cars for a car that matches the users VIN, and returns
    a pointer to said car. Returns NULL if the array is empty or if no matches
    are found.

    Parameters:
        Car *array : An array of cars, assumed to have been created by the createArray function.
        int VIN : The VIN to search for in the array
*/
Car * getCarByVIN(Car *array, int VIN)
{
    if(!array)
        return NULL;
    int size = getSize(array);
    for(int i = 0; i < size; i++)
    {
        int currentVIN = getVin(&(array[i]));
        if(currentVIN == VIN)
            return &(array[i]);
    }
    return NULL;
}

/*  getWithLeastAccidents
    Returns the car with the least amount of accidents in an array of cars.
    Returns NULL if the array is empty, and, if multiple cars have the least
    number of accidents, returns the first car to appear with that number of
    accidents.

    Parameters:
        Car * array : The array to search through, assumed to have been created by the createArray function.
*/
Car * getWithLeastAccidents(Car *array)
{
    if(!array)
        return NULL;
    int size = getSize(array);
    int leastAccidents = getNumberOfAccidents(&(array[0]));
    Car * carWithLeastAccidents = &(array[0]);
    for(int i = 0; i < size; i++)
    {
        int currentAccidents = getNumberOfAccidents(&(array[i]));
        if(currentAccidents < leastAccidents)
        {
            leastAccidents = currentAccidents;
            carWithLeastAccidents = &(array[i]);
        }
    }
    return carWithLeastAccidents;
}

/*  printCars
    Prints out the VIN, Miles Driven, and Number of Accidents of each car in an array of cars.

    Parameters:
        Car *array : An array of cars to print, assumed to have been created by the createArray function
*/
void printCars(Car *array)
{
    if(!array)
        return;
    int size = getSize(array);
    for(int i = 0; i < size; i++)
    {
        int VIN = getVin(&(array[i]));
        float milesDriven = getMilesDriven(&(array[i]));
        int numberOfAccidents = getNumberOfAccidents(&(array[i]));
        printf("VIN: %d Miles Driven: %f Number of Accidents: %d\n", VIN, milesDriven, numberOfAccidents);
    }
}

/*  freeArray
    Frees an array created by the createArray function.

    Parameters:
        void *array : An array created by the createArray function.
*/
void freeArray(void *array)
{
    free(((int*)array)-1);
}
