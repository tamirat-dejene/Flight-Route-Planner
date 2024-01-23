#include <iostream>
#include "airport.h";
#include "route.h"
#include "location.h"
#include "aircraft.h"
#include "weather.h"

#include <list>

#include "flight_routes.h"

Flights::Flights() {
	this->routes = std::list<Route>();
	this->airports = std::list<Airport>();
}

void Flights::addAirport() {

}

int main() {


	system("pause");
}