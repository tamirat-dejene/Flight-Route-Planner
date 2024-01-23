#include <iostream>

#include "queue.cpp"
#include "time.h"
#include "location.h"
#include "airport.h"
#include "airline.h"
using namespace std;

void display(Airline airline);

int main() {
	 /*///////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
   //////////////////                           ///////////////////////////
  //////////////////DIRECT NETWORK OF AIRPORTS///////////////////////////
  \\\\\\\\\\\\\\\\\\                           \\\\\\\\\\\\\\\\\\\\\\\\\\\
   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/        

	/*Queue<int> numQueue;
	numQueue.enqueue(1);
	numQueue.enqueue(4);
	numQueue.enqueue(2);
	numQueue.enqueue(3);

	if (numQueue.contains(1))
		cout << "True\n";
	cout << numQueue.getFront() << endl;
	numQueue.dequeue();
	cout << numQueue.getFront() << endl;
	numQueue.dequeue();
	numQueue.dequeue();
	numQueue.dequeue();
	numQueue.dequeue();
	numQueue.dequeue();
	cout << numQueue.getFront() << "  " << numQueue.getSize() << endl;
	
	system("pause");*/

	//Location l("Ethiopia", "Addis Ababa");
	//cout << l.getCountry() << endl;

	//Airport a("BOLE001", "Bolie Interanational Airport", l);
	//l = a.getLocation();
	//cout << a.getLocation().getCity() << endl;

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

	//std::cout << t << std::endl;


	airline.addRoute(ports[0], ports[1], t, 550, 3500);
	airline.addRoute(ports[0], ports[2], t1, 450, 2000);
	airline.addRoute(ports[1], ports[2], t2, 300, 3500);
	airline.addRoute(ports[1], ports[4], t1, 450, 2000);
	airline.addRoute(ports[2], ports[3], t3, 100, 5500);
	//airline.addRoute(ports[3], ports[2], t3, 100, 5500);

	/*	Test#2
	
	cout << "Before removing ports[0]\n\n";
	display(airline);
	airline.removeRoute(ports[0]);
	cout << "After removing ports[0]\n\n";
	display(airline);*/






	/*	Test#3 Breadth first search
	
	std::list<Airport> airports = airline.getAllPossiblePorts(ports[0]);

	for (Airport a : airports)
		cout << a.getCode() << " " << a.getName() << " " << a.getLocation().getCountry() << " " << a.getLocation().getCity() << endl;*/



	/*  Test#4  Dijsktras algorithm to find the min distances from the origin to all node( airports)*/

	std::unordered_map<Airport, double> distancesFrom = airline.min_distanceFrom(ports[0]);

	//for (const auto& pair : distancesFrom)
	//	std::cout << "To: " << pair.first.getCode() << ", Distance: " << pair.second << std::endl;
	
	system("pause");
	return 0;
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