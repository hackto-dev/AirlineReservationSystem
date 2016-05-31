/*CIST 2362
Nic Smith
Final Project - Airline Reservation System */
#ifndef CITY_H
#define CITY_H
#include <string>
using namespace std;
class City {
private:
	string cityName, cityCode;
public:
	// constructors
	City();
	~City();
	City(string, string);
	// accessors and mutators
	string getCityName();
	string getCityCode();
	void setCityName(string);
	void setCityCode(string);
};
#endif