#include <iostream>
#include <map>

#include "queue.cpp"
#include "time.h"
#include "location.h"
#include "airport.h"
#include "airline.h"
using namespace std;

void display(Airline airline);
void print_result(std::map<Airport, std::pair<double, std::list<Airport>>> result);

int main() {
	 /*///////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
   //////////////////                           ///////////////////////////
  ////////////////// Welcome to Flight Route Planner ///////////////////////////
  \\\\\\\\\\\\\\\\\\                           \\\\\\\\\\\\\\\\\\\\\\\\\\\
   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/      

	Airport ports[] = { Airport("ET0", "Bole Int. Airport", Location("Ethiopia", "Addis Ababa")),
						Airport("ET1", "Bahirdar Airport", Location("Ethiopia", "Bahirdar")),
						Airport("ET2", "Mekele Airport", Location("Ethiopia", "Mekele")),
						Airport("ET3", "Gonder Airport", Location("Ethiopia", "Gonder")),
						Airport("ET4", "Jimma Airport", Location("Ethiopia", "Jimma")) };

	Airline airline("Ethiopian Airlines");

	airline.addAirport(ports[0]);
	airline.addAirport(ports[1]);
	airline.addAirport(ports[2]);
	airline.addAirport(ports[3]);
	airline.addAirport(ports[4]);

	Time t(2, 30);
	Time t1(1, 30);
	Time t2(3, 30);
	Time t3(1, 00);

	airline.addRoute(ports[0], ports[1], t, 550, 3500);
	airline.addRoute(ports[0], ports[2], t1, 450, 2000);
	airline.addRoute(ports[1], ports[2], t2, 300, 3500);
	airline.addRoute(ports[1], ports[4], t1, 450, 2000);
	airline.addRoute(ports[2], ports[3], t3, 100, 5500);

	/*std::list<Route> r = airline.getPortDetail(ports[2]);
	for (auto a : r)
		cout << a.getDestination().getCode() << endl;
	system("pause");*/
	//airline.addRoute(ports[3], ports[2], t3, 100, 5500);

	
	
	//Test#2
	//
	//cout << "Before removing ports[0]\n\n";
	//display(airline);
	//airline.removeAirport(ports[0]);
	////airline.removeRoute(ports[0]);
	//cout << "After removing ports[0]\n\n";
	//display(airline);
	//system("pause");





	/*	Test#3 Breadth first search
	
	std::list<Airport> airports = airline.getAllPossiblePorts(ports[0]);

	for (Airport a : airports)
		cout << a.getCode() << " " << a.getName() << " " << a.getLocation().getCountry() << " " << a.getLocation().getCity() << endl;*/



	/*  Test#4  Dijsktras algorithm to find the min distances from the origin to all node( airports)*/

	/*std::map<Airport, double> distancesFrom = airline.min_distanceFrom(ports[3]);

	for (const auto& pair : distancesFrom)
		std::cout << "To: " << pair.first.getCode() << ", Distance: " << pair.second << std::endl;
	
	*/


	/*  Test#5  Dijsktras algorithm to find the min distances from the origin to all node( airports) with paths*/
	std::map<Airport, std::pair<double, std::list<Airport>>> result1 = airline.min_price_path(ports[0]);
	print_result(result1);
	std::map<Airport, std::pair<double, std::list<Airport>>> result2 = airline.min_distance_path(ports[0]);
	print_result(result2);



	system("pause");
	return 0;
}

void print_result(std::map<Airport, std::pair<double, std::list<Airport>>> result) {
	for (const auto& entry : result) {
		const Airport& airport = entry.first;
		const double distance = entry.second.first;
		const std::list<Airport>& path = entry.second.second;

		std::cout << "Destination Airport: " << airport.getCode() << ", Distance: " << distance << ", Path: ";
		for (const Airport& stop : path) {
			std::cout << stop.getCode();
			if (!(stop == path.back()))
				std::cout << " --> ";
		}
		std::cout << std::endl;
	}
}
void display(Airline airline) {
	//Test
		for (auto& pair : airline.getPortNets()) {
			Airport a = pair.first;
			std::list<Route> r = pair.second;

			cout << a.getCode() << "[Origin]\n";
			for (auto& d : r)
				cout << d.getDeparture().getCode() << " --> " << d.getDestination().getCode() << endl;
			cout << endl;
			r.clear();
		}
	//Test^^^^

}