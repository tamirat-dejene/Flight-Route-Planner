#include <string>
#include "location.h"


Location::Location() {
	this->country = "NULL";
	this->city = "NULL";
}
Location::Location(std::string country, std::string city) {
	this->country = country;
	this->city = city;
}
void Location::setCountry(std::string country) {
	this->country = country;
}
void Location::setCity(std::string city) {
	this->city = city;
}
std::string Location::getCountry() {
	return this->country;
}
std::string Location::getCity() {
	return this->city;
}

bool Location::operator==(const Location& another) const {
	return (this->country == another.country && this->city == another.city);
}

bool Location::operator < (const Location& another) const {
	return country < another.country && city < another.city;
}

bool Location::eqauls(const Location& anotherLocation) const{
	return (this->city == anotherLocation.city && this->country == anotherLocation.country);
}

std::string Location::toString() const{
	return ("City: " + this->city + ", Country: " + this->country);
}
