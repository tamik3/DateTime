#ifndef __TRIP_H
#define __TRIP_H
#include "Date.h"

class Trip {
	static int counter;
	int id;
	char* destination;
	Date date;

public:
	int getId() const { return id; }
	char* getDestination() const { return destination; }
	Date getDate() const { return date; }
	void setDestination(char destination[30]);
	void setDate(Date date);
	Trip(char destination[30], Date date);
	Trip();
	Trip(const Trip& other);
	~Trip();
	void printTrip();
	const Trip& operator=(const Trip& other);
	friend std::ostream& operator<<(std::ostream& os, const Trip& trip);
};

#endif
