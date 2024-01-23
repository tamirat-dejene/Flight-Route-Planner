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
	//const Airport& getDetail(std::string portCode);
	bool operator == (const Airport& anotherAirport) const;
	bool operator < (const Airport& anotherAirport) const;
	void display_airport_datails() const;
	bool equals(const Airport& anotherAirport);

	/*void addRoute(Airport newDestination, double distance, double altitude, double fuelConsumption, double price);
	void removeRoute(Airport destination);
	std::list<Route> getRoutes();*/
};

