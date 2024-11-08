#include <iostream>
#include "ManagementTrips.h"
#include "Trip.h"
#include "Date.h"
#pragma warning(disable:4996)
using namespace std;

ManagementTrips::ManagementTrips(const ManagementTrips& o)
{
	i = o.i;
	trips = new Trip * [i];
	for (int j = 0; j < i; j++) {
		trips[j] = new Trip(*o.trips[j]);
	}
}

const ManagementTrips& ManagementTrips::operator=(const ManagementTrips& o)
{
	if (this == &o) return *this;

	for (int j = 0; j < i; ++j) {
		delete trips[j];
	}
	delete[] trips;

	i = o.i;
	trips = new Trip * [i];
	for (int j = 0; j < i; j++) {
		trips[j] = new Trip(*o.trips[j]);
	}
	return *this;
}

void ManagementTrips::operator+=(const Trip& trip)
{
    Trip** newTrips = new Trip * [i + 1];
    for (int j = 0; j < i; ++j) {
        newTrips[j] = trips[j];
    }
    newTrips[i] = new Trip(trip);
    delete[] trips;
    trips = newTrips;
    i++;
}

void ManagementTrips::operator-=(const Trip& trip)
{
    for (int j = 0; j < i; j++) {
        if (trips[j]->getDate() == trip.getDate()) {
            delete trips[j];
            trips[j] = trips[i - 1];
            trips[i - 1] = nullptr;
            i--;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const ManagementTrips& trips)
{
    os << "The trips are:" << endl;
    for (int j = 0; j < trips.i; j++) {
        os << *trips.trips[j] << endl;
    }
    return os;
}
