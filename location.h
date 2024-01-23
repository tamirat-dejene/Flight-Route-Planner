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

