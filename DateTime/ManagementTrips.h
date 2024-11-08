#ifndef __MANAGEMENTTRIPS_
#define __MANAGEMENTTRIPS_
#include "Trip.h"
#include <ostream>

class ManagementTrips {
	Trip** trips;
	int i;
public:
	ManagementTrips() { trips = new Trip * [0]; i = 0; }
	ManagementTrips(const ManagementTrips& o);
	const ManagementTrips& operator=(const ManagementTrips & o);
	void operator+=(const Trip& trip);
	void operator-=(const Trip& trip);
	friend std::ostream& operator<<(std::ostream& os, const ManagementTrips& trips);
};

#endif
