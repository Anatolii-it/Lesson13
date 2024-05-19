#ifndef LIB_H
#define LIB_H

#include <iostream>
using namespace std;

struct Passenger {
    char fullName[100];
    int luggageCount;
    double totalLuggageWeight;
    int flightNumber;
};

void inputPassengers(Passenger* passengers, int N);
void sortPassengersByFlightNumber(Passenger* passengers, int N);
void printSortBuFl(Passenger* passengers, int N);
void displayPassengersWithHeavyLuggage(Passenger* passengers, int N);

#endif  LIB_H