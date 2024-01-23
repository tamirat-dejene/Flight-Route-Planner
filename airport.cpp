#include <iostream>
#include <string>

#include "location.h"
#include "airport.h"


Airport::Airport() {
	this->code = "NULL";
	this->name = "NULL";
	this->location = Location();
}

Airport::Airport(std::string code, std::string name, Location location) {
	this->code = code;
	this->name = name;
	this->location = location;
}

void Airport::setCode(const std::string code) {
	this->code = code;
}
void Airport::setName(const std::string name) {
	this->name = name;
}
void Airport::setLocation(const Location& location) {
	this->location = location;
}
Location Airport::getLocation() const {
	return this->location;
}
std::string Airport::getCode() const {
	return this->code;
}
std::string Airport::getName() const {
	return this->name;
}

//const Airport& Airport::getDetail(std::string portCode) {
//	// TODO: insert return statement here
//	return Airport();
//}

bool Airport::operator==(const Airport& anotherAirport) const {
	return (code == anotherAirport.code);
}

bool Airport::operator<(const Airport& anotherAirport) const {
	return (code < anotherAirport.code);
}

bool Airport::equals(const Airport& anotherAirport) {
	return code == anotherAirport.code &&
		name == anotherAirport.name &&
		location == anotherAirport.location;
}

void Airport::display_airport_datails() const {
	std::cout << "\n--- ---- AIRPORT DETAILS ---- ---\n";
	std::cout << "  Code     : " << this->getCode() << std::endl;
	std::cout << "  Name     : " << this->getName() << std::endl;
	std::cout << "  Location : " << this->getLocation().toString() << std::endl;
}


//void Airport::addRoute(Airport newDestination, double distance, double altitude, double fuelConsumption, double price) {
//	(this->routes).push_back(Route(*this, newDestination, distance, altitude, fuelConsumption, price));
//}
//
//void Airport::removeRoute(Airport destination) {
//	routes.remove_if([destination](Route r) { return r.getDestination() == destination; });
//}
//
//std::list<Route> Airport::getRoutes() {
//	return this->routes;
//}