#include "lib.h"

void inputPassengers(Passenger* passengers, int N) {
    for (int i = 0; i < N; ++i) {
        cout << "Пасажир " << i + 1 << ":\n";
        cout << "ПІБ: ";
        cin.ignore();
        cin.getline(passengers[i].fullName, 100);
        cout << "кількісь речей: ";
        cin >> passengers[i].luggageCount;
        cout << "Загальна вага: ";
        cin >> passengers[i].totalLuggageWeight;
        cout << "Номер рейсу: ";
        cin >> passengers[i].flightNumber;
    }
}

void sortPassengersByFlightNumber(Passenger* passengers, int N) {
    Passenger temp;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (passengers[j].flightNumber < passengers[j + 1].flightNumber) {
                temp = passengers[j];
                passengers[j] = passengers[j + 1];
                passengers[j + 1] = temp;
            }
        }
    }
}

void printSortBuFl(Passenger* passengers, int N) {
    cout << endl;
    cout << "#-------------------------------------#\n";
    cout << "Пасажири відсотровані за номером рейсу:\n";
    for (int i = 0; i < N; i++)
    {
        cout << "Пасажир: " << passengers[i].fullName << ", Номер рейсу: " << passengers[i].flightNumber << "\n";
    }
    cout << "#-------------------------------------#\n";
    cout << endl;
}

void displayPassengersWithHeavyLuggage(Passenger* passengers, int N) {

    cout << "Пасажири багаж яких складається із однієї речі вагою понад 30кг:\n";
    for (int i = 0; i < N; ++i) {
        if (passengers[i].totalLuggageWeight > 30 && passengers[i].luggageCount == 1) {
            cout << "Пасажир: " << passengers[i].fullName << ", Номер рейсу: " << passengers[i].flightNumber << "\n";
        }
    }
    cout << "#-------------------------------------#\n";
}