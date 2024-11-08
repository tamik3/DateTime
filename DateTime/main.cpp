#include "ManagementTrips.h"
#include "Trip.h"
#include "Date.h"
#include <ostream>
using namespace std;


void deleteTrips(ManagementTrips* mts);
void AddTrip(ManagementTrips* mts);

void main() {
    ManagementTrips mts;
    int option;
    do {
        cout << "Please Select an option: \n1.Print Trips\n2.Delete Trips\n3.Add Trip\n4.Exit" << endl;
        cin >> option;
        switch (option) {
        case 1:
            cout << mts << endl;
            break;
        case 2:
            deleteTrips(&mts);
            break;
        case 3:
            AddTrip(&mts);
            break;
        case 4:
            cout << "bye bye!" << endl;
            break;
        default:
            cout << "invalid option" << endl;
            break;
        }
    } while (option != 4);
}

void deleteTrips(ManagementTrips* mts) {
    int day, month, year;
    cout << "enter year" << endl;
    cin >> year;
    cout << "enter month" << endl;
    cin >> month;
    cout << "enter day" << endl;
    cin >> day;

    Date date = Date(day, month, year);
    char destination[30];
    Trip trip = Trip(destination, date);

    (*mts) -= trip;
}

void AddTrip(ManagementTrips* mts) {
    int day, month, year;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter day: ";
    cin >> day;

    Date date(day, month, year);
    char destination[30];

    cout << "Enter destination: ";
    cin >> destination;

    Trip trip(destination, date);

    (*mts) += trip;
}
