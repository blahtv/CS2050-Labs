#include "lab6.h"

int main()
{
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

    Node * myList = initList();
    printf("Initial Size: %d\n", getSize(myList));
    int ec = insertAtHead(&myList, &car1);
    printf("%d New Size: %d\n", ec, getSize(myList));
    ec = insertAtHead(&myList, &car2);
    ec = insertAtHead(&myList, &car3);
    ec = insertAtHead(&myList, &car4);
    ec = insertAtHead(&myList, &car5);
    printf("%d New Size: %d\n", ec, getSize(myList));
    printCars(myList);

    Car * carThatICrashed = removeFromHead(&myList);
    printf("Car I crashed: %d\n", carThatICrashed->vin);
    printf("%d New Size: %d\n", ec, getSize(myList));
    printCars(myList);

    Car * myNewCarAfterICrashedMyLastOne = getWithMostMilesDriven(myList);
    printf("Car I bought: %d\n", myNewCarAfterICrashedMyLastOne->vin);

    freeList(&myList);

    printf("get size: %d\n", getSize(myList));    
    removeFromHead(&myList);
    freeList(&myList);
    getWithMostMilesDriven(myList);
    printCars(myList);
}