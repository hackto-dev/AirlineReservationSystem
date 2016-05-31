/*CIST 2362
Nic Smith
Final Project - Airline Reservation System */
#ifndef SEAT_H
#define SEAT_H
#include "Passenger.h"
class Seat {
	protected:
		string seatNumber;
		bool seatOpen;
		Passenger p;
	public:
		// constructors
		Seat();
		~Seat();
		Seat(string);
		// functions and accessors
		bool seatOpenYN();
		string getSeatNumber();
		Passenger &getPassenger();
		void setPassenger(Passenger);
		void setSeatOpen(bool);
}; 
#endif