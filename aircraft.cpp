#include "aircraft.h"

Aircraft::Aircraft(){
	this->capacity = 0;
	this->model = "";
	this->cruiseSpeed = 0;
	this->fuelCapacity = 0;
}
Aircraft::Aircraft(std::string model, int capacity, float fuelCapacity, int cruiseSpeed) {
	this->model = model;
	this->capacity = capacity;
	this->fuelCapacity = fuelCapacity;
	this->cruiseSpeed = cruiseSpeed;
}
void Aircraft::setModel(std::string model) {
	this->model = model;
}
int Aircraft::getCapacity() {
	return this->capacity;
}
void Aircraft::setCapacity(const int capacity) {
	this->capacity = capacity;
}
std::string Aircraft::getModel() {
	return this->model;
}