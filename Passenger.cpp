/*CIST 2362
Nic Smith
Final Project - Airline Reservation System */
#include "Passenger.h"
// constructors and destructors
Passenger::Passenger() {}
Passenger::~Passenger() {}
Passenger::Passenger(string pfn, string pln, int fp, string sn, int fn){
	passFName = pfn;
	passLName = pln;
	flyerPoints = fp;
	seatNum = sn;
	flightNum = fn;
}
// accessors and mutators
string Passenger::getPassFName() {
	return passFName;
}
string Passenger::getPassLName() {
	return passLName;
}
int Passenger::getFlyerPoints() {
	return flyerPoints;
}
string Passenger::getSeatNum() {
	return seatNum;
}
int Passenger::getFlightNum() {
	return flightNum;
}
string Passenger::getPassID() {
	return (passFName + passLName);
}
void Passenger::setPassFName(string pfn) {
	this->passFName = pfn;
}
void Passenger::setPassLName(string pln) {
	this->passLName = pln;
}
void Passenger::setFlyerPoints(int fp) {
	this->flyerPoints = fp;
}
void Passenger::setSeatNum(string sn) {
	this->seatNum = sn;
}
void Passenger::setFlightNum(int fn) {
	this->flightNum = fn;
}
string Passenger::toPassFile() {
	return (passFName + "," + passLName + "," + to_string(flyerPoints) + "," + seatNum + "," + to_string(flightNum));
}