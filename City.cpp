/*CIST 2362
Nic Smith
Final Project - Airline Reservation System */
#include "City.h"
// constructors
City::City() {}
City::~City() {}
City::City(string cn, string cc) {
	cityName = cn;
	cityCode = cc;
}
// accessors and mutators
string City::getCityName() {
	return cityName;
}
string City::getCityCode() {
	return cityCode;
}
void City::setCityName(string cn) {
	this->cityName = cn;
}
void City::setCityCode(string cc) {
	this->cityCode = cc;
}