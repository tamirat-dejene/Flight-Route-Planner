#include "time.h"

Time::Time() : minutes(0), hours(0){
	// Default constructor
}

Time::Time(const float hours, const float minutes) : hours(hours), minutes(minutes){

}

float Time::getHour(){
	return this->hours;
}

void Time::setHour(float& hr) {
	this->hours = hr;
}

float Time::getMinutes(){
	return this->minutes;
}

void Time::setMinutes(float& min){
	this->minutes = min;
}

std::ostream& Time::operator<<(std::ostream output) const {
	output << this->hours << ":" << this->minutes;
	return output;
}

std::istream& Time::operator>>(std::istream input) {
	input >> this->hours;
	input.ignore();  // :
	input >> this->minutes;
	return input;
}

bool Time::operator==(const Time& anotherTime) const{
	return hours == anotherTime.hours && minutes == anotherTime.minutes;
}
