/*CIST 2362
Nic Smith
Final Project - Airline Reservation System */
#include "Airplane.h"
// constructors
Seat::Seat() {}
Seat::~Seat() {}
Seat::Seat(string sn) {
	seatNumber = sn;
	seatOpen = true;
};
// functions and accessors
bool Seat::seatOpenYN() {
	return true;
}
string Seat::getSeatNumber() {
	return seatNumber;
}
Passenger &Seat::getPassenger() {
	return this->p;
}
void Seat::setPassenger(Passenger p) {
	this->p = p;
}
void Seat::setSeatOpen(bool tf) {
	this->seatOpen = tf;
}