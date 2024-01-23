#include <list>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>

#include "time.h"
#include "route.h"
#include "airport.h"
#include "airline.h"
#include "queue.cpp"


Airline::Airline(std::string name) : name(name) {
	/*															
		| -- -- -- -- --[A - Y - Z - O - N] -- -- -- -- -- |
	 															*/
}

void Airline::addAirport(const Airport& newPort) {
	if (port_network.find(newPort) != port_network.end())
		port_network.insert(std::make_pair(newPort, std::list<Route>()));
	// To the list, not to the network of airports
}

void Airline::removeAirport(Airport& thisOne) {
	if (port_network.find(thisOne) != port_network.end())
		port_network.erase(thisOne);
	removeRoute(thisOne); // remove from the value map
	// Remove from the airports map
}

const std::list<Route> Airline::getPortDetail(Airport& port) {
	auto k = port_network.find(port);	// Find
	if (k != port_network.end())
		return k->second;
	else
		return std::list<Route>();
}

void Airline::addRoute(const Airport& origin, const Airport& destination, Time flight_time, double distance, double price) {
	// Adds new route betweem two airports
	Route r(origin, destination, flight_time, distance, price);

	map<Airport, std::list<Route>>::iterator iter = port_network.find(origin);

	if (iter == port_network.end()) {
		///cout << "KEY-NOT-FOUND..." << endl;
		std::list<Route> routes;
		routes.push_back(r);
		port_network.insert(std::make_pair(origin, routes));
	}
	else {
		std::list<Route> routes = iter->second;
		///cout << "KEY-FOUND.." << endl;
		auto f = std::find(routes.begin(), routes.end(), r);

		if (f == routes.end()) {
			routes.push_back(r);
			iter->second = routes;
		}
	}
}

void Airline::removeRoute(Airport& destination) {
	// Lambda expression: rmoves from the values when the values destination data field satisfies the condition
	for (auto& keys : port_network)
		keys.second.remove_if([destination](Route r) { return r.getDestination() == destination; });
}

const std::list<Airport> Airline::getAllPossiblePorts(const Airport& origin) {
	// Breadth first search using queue to find all tge ports on the network
	std::list<Airport> visited;
	visited.push_back(origin);


	std::queue<Airport> visitPorts;
	visitPorts.push(origin);
	

	while (!visitPorts.empty()) {
		Airport current = visitPorts.front();
		visitPorts.pop();
		auto iter = port_network.find(current);
		std::list<Route> route;
		if (iter != port_network.end())
			route = iter->second;				

		for (Route r : route) {
			if (std::find(visited.begin(), visited.end(), r.getDestination()) == visited.end()) {
				visitPorts.push(r.getDestination());
				visited.push_back(r.getDestination());
			}
		}	
	}
	return visited;
}

std::unordered_map<Airport, double> Airline::min_distanceFrom(const Airport& origin) const {
	
	std::unordered_map<Airport, double> distance;
	std::priority_queue<std::pair<double, Airport>, std::vector<std::pair<double, Airport>>, std::greater<>> pq;

	for (const auto& pair : port_network)
		distance[pair.first] = std::numeric_limits<int>::max();

	distance[origin] = 0;
	pq.push({ 0, origin });

	while (!pq.empty()) {
		Airport current = pq.top().second;
		double currentDistance = pq.top().first;
		pq.pop();

		if (currentDistance > distance[current])
			continue;

		for (const Route& route : port_network.at(current)) {
			double newDistance = currentDistance + route.getDistance();

			if (newDistance < distance[route.getDestination()]) {
				distance[route.getDestination()] = newDistance;
				pq.push({ newDistance, route.getDestination() });
			}
		}
	}

	return distance;
}

void Airline::print_airLines() {
	for (auto& key : port_network) {
		Airport a = key.first;
		cout << a.getCode() << " --> ";
		std::list<Route> route = key.second;
		for (auto& r : route) {
			cout << r.getDestination().getCode() << ", ";
		}
		cout << endl;
	}
}
//const Route& Airline::getAllPossibleRoutes(const Airport& origin) {
//
//	// TODO: insert return statement here
//}
//
//void Airline::findOptimumDistance(Airport origin, Airport destination) {
//
//}
//
//void Airline::findOptimumPrice(Airport origin, Airport destination) {
//
//}
//
//void Airline::findOptimumPath(Airport origin, Airport destination) {
//
//}
//
//void Airline::printAllPossibleRoutes() {
//
//}


