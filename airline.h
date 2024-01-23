#pragma once

#include <iostream>
#include <list>
#include <map>

#include "location.h"
#include "time.h"
#include "airport.h"
#include "route.h"
#include <unordered_map>



class Airline {
private:
	std::string name;
	std::map<Airport, std::list<Route>> port_network;
public:
	Airline(std::string name);

	std::map<Airport, std::list<Route>>& getPortNets() {
		return this->port_network;
	}

	void addAirport(const Airport& newPort);
	void removeAirport(Airport& thisOne);
	const std::list<Route> getPortDetail(Airport& port);

	void addRoute(const Airport& origin, const Airport& destination, Time flight_time, double distance, double price);	// Brand new direct route
	void removeRoute(Airport& destination);
	const std::list<Airport> getAllPossiblePorts(const Airport& origin);	// 

	std::unordered_map<Airport, double> min_distanceFrom(const Airport& origin) const; // Minim cost
	//void findOptimumPrice(Airport origin, Airport destination); // Minimize price
	//void findOptimumPath(Airport origin, Airport destination); // Minimize distance and cost
	//void printAllPossibleRoutes();  // Network of airports that the airline operates on

	void print_airLines();
};

