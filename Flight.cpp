/*CIST 2362
Nic Smith
Final Project - Airline Reservation System */
#include "Flight.h"
// constructors and destructors
Flight::Flight() {}
Flight::~Flight() {}
Flight::Flight(int fn, int ffp, string d, string a, string dc, string ac, string dt, string at) {
	flightNumber = fn;
	freqFlyerPoints = ffp;
	departure = d;
	arrival = a;
	departureCode = dc;
	arrivalCode = ac;
	departureTime = dt;
	arrivalTime = at;
}
// accessors and mutators
char Flight::getFlightType() {
	return flightType;
}
int Flight::getFlightNumber() {
	return flightNumber;
}
int Flight::getFreqFlyerPoints() {
	return freqFlyerPoints;
}
string Flight::getDeparture() {
	return departure;
}
string Flight::getArrival() {
	return arrival;
}
string Flight::getDepartureCode() {
	return departureCode;
}
string Flight::getArrivalCode() {
	return arrivalCode;
}
string Flight::getDepartureTime() {
	return departureTime;
}
string Flight::getArrivalTime() {
	return arrivalTime;
}
void Flight::setFlightType(char ft) {
	this->flightType = ft;
}
void Flight::setFlightNumber(int fn) {
	this->flightNumber = fn;
}
void Flight::setFreqFlyerPoints(int ffp) {
	this->freqFlyerPoints = ffp;
}
void Flight::setDeparture(string d) {
	this->departure = d;
}
void Flight::setArrival(string a) {
	this->arrival = a;
}
void Flight::setDepartureCode(string dc) {
	this->departureCode = dc;
}
void Flight::setArrivalCode(string ac) {
	this->arrivalCode = ac;
}
void Flight::setDepartureTime(string dt) {
	this->departureTime = dt;
}
void Flight::setArrivalTime(string at) {
	this->arrivalTime = at;
}
string Flight::toFile() {
	return (departure + "," + arrival + "," + departureTime + "," + arrivalTime + "," + to_string(flightNumber) + "," + 
		flightType + "," + to_string(freqFlyerPoints));
}