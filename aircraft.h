#pragma once
#include <string>

class Aircraft {
private:
	std::string model;
	int capacity;
	float fuelCapacity;
	int cruiseSpeed;
public:
	Aircraft();
	Aircraft(std::string model, int capacity, float fuelCapacity, int cruiseSpeed);
	void setModel(std::string model);
	int getCapacity();
	void setCapacity(const int capacity);
	std::string getModel();
};

