#include "airport.h"
#include "time.h"
#include "route.h"

Route::Route(const Airport& departure, const Airport& destination, Time flight_time, double distance, double price) {
    this->departure = departure;
    this->destination = destination;
    this->hours = flight_time;
    this->distance = distance;
    this->price = price;
}
Airport Route::getDeparture() const {
    return this->departure;
}
void Route::setDeparture(const Airport& departure) {
    this->departure = departure;
}
Airport Route::getDestination() const {
    return this->destination;
}
void Route::setDestination(const Airport& destination) {
    this->destination = destination;
}
double Route::getDistance() const {
    return this->distance;
}
void Route::setDistance(double distance) {
    this->distance = distance;
}
double Route::getPrice() const {
    return this->price;
}
void Route::setPrice(double price) {
    this->price = price;
}

Time Route::getTime() const {
    return this->hours;
}

void Route::setTime(Time& t) {
    this->hours = t;
}

bool Route::operator==(const Route& anotherRoute) const {
    return departure == anotherRoute.departure &&
        destination == anotherRoute.destination &&
        price == anotherRoute.price &&
        distance == anotherRoute.distance &&
        hours == anotherRoute.hours;    
}
