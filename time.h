#pragma once
#include <istream>
#include <ostream>

class Time {
private:
	float hours;
	float minutes;
public:
	Time();
	Time(const float hours, const float minutes);
	float getHour();
	void setHour(float& hr);
	float getMinutes();
	void setMinutes(float& min);
	/* Direct time input and output*/
	std::ostream& operator << (std::ostream output) const;
	std::istream& operator >> (std::istream input);
	bool operator == (const Time& anotherTime) const;
};

