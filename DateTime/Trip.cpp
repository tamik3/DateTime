#include <iostream>
#include <cstring>
#include "Date.h"
#include "Trip.h"
#pragma warning(disable:4996)
using namespace std;


int Trip::counter = 0;

void Trip::setDestination(char destination[30]) {
	bool problem = false;
	for (int i = 0; i < strlen(destination) && !problem; i++) {
		if (!((destination[i] >= 'a' && destination[i] <= 'z') || (destination[i] >= 'A' && destination[i] <= 'Z'))) {
			strcpy(destination, "Jerusalem");
			problem = true;
		}
	}

	this->destination = new char[strlen(destination) + 1];
	strcpy(this->destination, destination);
}

void Trip::setDate(Date date) {
	this->date = Date(date.getDay(), date.getMonth(), date.getYear());
}

Trip::Trip(char destination[30], Date date) {
    setDestination(destination);
    setDate(date);
    counter++;
    id = counter;
}

Trip::Trip() {
    destination = new char[strlen("Jerusalem") + 1];
    strcpy(destination, "Jerusalem");
    date = Date();
    counter++;
    id = counter;
}

Trip::Trip(const Trip& other) {
    setDestination(other.destination);
    setDate(other.date);
    counter++;
    id = counter;
}

const Trip& Trip::operator=(const Trip& other) {
    if (this != &other) {
        id = other.id;
        date = other.date;

        if (destination) {
            delete[] destination;
        }

        destination = new char[strlen(other.destination) + 1];
        strcpy(destination, other.destination);
    }
    return *this;
}



Trip:: ~Trip() {
	delete[]destination;
}

ostream& operator<<(ostream& out, const Trip& trip) {
	out << "trip id: " << trip.getId() << endl;
	out << "trip destination: " << trip.getDestination() << endl;
	out << "trip date: " << trip.getDate();
	return out;
}