#pragma once
#include "airport.h"

class Route {
private:
    Airport departure;
	Airport destination;
	double distance;
	double price;
    Time hours;
public:
	Route(const Airport& departure, const Airport& destination, Time flight_time, double distance, double price);
    Airport getDeparture() const;
    void setDeparture(const Airport& departure);
    Airport getDestination() const;
    void setDestination(const Airport& destination);
    double getDistance() const;
    void setDistance(double distance);
    double getPrice() const;
    void setPrice(double price);
    Time getTime() const;
    void setTime(Time& t);

    bool operator == (const Route& anotherRoute) const;
};

