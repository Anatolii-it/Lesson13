#include "lib.h"

void inputPassengers(Passenger* passengers, int N) {
    for (int i = 0; i < N; ++i) {
        cout << "������� " << i + 1 << ":\n";
        cout << "ϲ�: ";
        cin.ignore();
        cin.getline(passengers[i].fullName, 100);
        cout << "������ �����: ";
        cin >> passengers[i].luggageCount;
        cout << "�������� ����: ";
        cin >> passengers[i].totalLuggageWeight;
        cout << "����� �����: ";
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
    cout << "�������� ���������� �� ������� �����:\n";
    for (int i = 0; i < N; i++)
    {
        cout << "�������: " << passengers[i].fullName << ", ����� �����: " << passengers[i].flightNumber << "\n";
    }
    cout << "#-------------------------------------#\n";
    cout << endl;
}

void displayPassengersWithHeavyLuggage(Passenger* passengers, int N) {

    cout << "�������� ����� ���� ���������� �� ���� ���� ����� ����� 30��:\n";
    for (int i = 0; i < N; ++i) {
        if (passengers[i].totalLuggageWeight > 30 && passengers[i].luggageCount == 1) {
            cout << "�������: " << passengers[i].fullName << ", ����� �����: " << passengers[i].flightNumber << "\n";
        }
    }
    cout << "#-------------------------------------#\n";
}