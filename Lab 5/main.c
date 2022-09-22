#include "lab5.h"

int main()
{
    Car * array = createArray(sizeof(Car), 5);
    Car car1, car2, car3, car4, car5;
    car1.vin = 1;
    car2.vin = 2;
    car3.vin = 3;
    car4.vin = 4;
    car5.vin = 5;

    car1.milesDriven = 100.2;
    car2.milesDriven = 200.3;
    car3.milesDriven = 300.4;
    car4.milesDriven = 400.5;
    car5.milesDriven = 500.6;

    car1.numberOfAccidents = 1;
    car2.numberOfAccidents = 7;
    car3.numberOfAccidents = 7;
    car4.numberOfAccidents = 9;
    car5.numberOfAccidents = 6;

    array[0] = car1;
    array[1] = car2;
    array[2] = car3;
    array[3] = car4;
    array[4] = car5;

    printf("Size: %d\n", getSize(array));
    printCars(array);
    Car * myCar = getCarByVIN(array, 2);
    printf("My car has %d accidents\n", getNumberOfAccidents(myCar));
    incrementNumberOfAccidents(myCar);
    printf("My car now has %d accidents\n", getNumberOfAccidents(myCar));
    updateMilesDriven(myCar, 700.3);
    printf("My car now has %f miles\n", getMilesDriven(myCar));

    Car * myNewCar = getWithLeastAccidents(array);
    printf("My new car has %d accidents and has a VIN of %d\n", getNumberOfAccidents(myNewCar), getVin(myNewCar));

    Car * myNonExistentCar = getCarByVIN(array, 990000000);
    printf("My non-existant car has %d accidents and has a VIN of %d\n", getNumberOfAccidents(myNonExistentCar), getVin(myNonExistentCar));
    freeArray(array);

}