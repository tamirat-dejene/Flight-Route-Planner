# Flight Route Planner

## Overview

Flight Route Planner is a C++ project that implements various functionalities related to airline route planning. The project includes classes for representing airports (`Airport`), routes between airports (`Route`), and an airline network (`Airline`). It utilizes Dijkstra's algorithm to find the shortest paths between airports based on the distances provided in the `Route` class, the optimum price to travel based on the prices set for each route and uses the map abstract data type to represent (model) network of routes using the adjacency list representation of graph.

## Classes

### Airport

The `Airport` class represents an airport and includes a constructor to initialize the airport with a given code. It also defines a method to retrieve the airport code.
```
#pragma once
#include <string>
#include <list>
#include "location.h"

class Airport {
private:
	std::string code;
	std::string name;
	Location location;
public:
	Airport();
	Airport(std::string code, std::string name, Location location);
	
	void setCode(const std::string code);
	void setName(const std::string name);
	void setLocation(const Location& location);
	
	Location getLocation() const;
	std::string getCode() const;
	std::string getName() const;
	bool operator == (const Airport& anotherAirport) const;
	bool operator < (const Airport& anotherAirport) const;
	void display_airport_datails() const;
	bool equals(const Airport& anotherAirport);
};
```

### Route

The `Route` class represents a route between two airports and includes information about the source airport, destination airport, and the distance between them, flight time length, and the pricing. It provides methods to retrieve these details of the class.

```
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
```

### Airline

The `Airline` class manages the airline network, which is a collection of airports and routes. It includes a Dijkstra's algorithm implementation (`dijkstra` method) to find the shortest distances from a given source airport to all other airports in the network.

```
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
	const std::list<Airport> allAirportEntries(const Airport& origin);	// 

	std::map<Airport, double> min_distanceFrom(const Airport& origin); // Minim cost
	std::map<Airport, std::pair<double, std::list<Airport>>> min_distance_path(const Airport& origin);
	std::map<Airport, std::pair<double, std::list<Airport>>> min_price_path(const Airport& origin);
	
	
	void print_airLines();
};
```

### Location

The location class represents the geographical places where the airports are located. It provide the constructors and methods to get the class details.

```
#pragma once
#include <string>
class Location {
private: 
	std::string country;
	std::string city;
public:
	Location();
	Location(std::string country, std::string city);
	void setCountry(std::string country);
	void setCity(std::string city);
	std::string getCountry();
	std::string getCity();

	std::string toString() const;

	bool operator==(const Location& another) const;
	bool operator < (const Location& another) const;
	bool eqauls(const Location& anotherLocation) const;
	
};
```
## How to Use

To use the Flight Route Planner:
1. Initialize airports and routes, locations, `Airline` class.
2. Use the Airline class object to use the methods provided.
3. Call the `dijkstra` method with a source airport to find the shortest distances, optimal price and other method.
4. Retrieve the results and utilize them in your application.

## Example
``` coming sooon ```
