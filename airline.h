#pragma once

#include <iostream>
#include <list>
#include <map>

#include "location.h"
#include "time.h"
#include "airport.h"
#include "route.h"

class Airline {
private:
	std::string name;
	std::map<Airport, std::list<Route>> port_network;

	std::map<Airport, std::pair<double, std::list<Airport>>> dijkstra_Optimum(const char _param, const Airport& origin);
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

	std::map<Airport, double> min_distanceFrom(const Airport& origin); // Minim cost
	std::map<Airport, std::pair<double, std::list<Airport>>> min_distance_path(const Airport& origin);
	std::map<Airport, std::pair<double, std::list<Airport>>> min_price_path(const Airport& origin);
	
	
	void print_airLines();
};

