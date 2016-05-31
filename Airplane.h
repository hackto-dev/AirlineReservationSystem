/*CIST 2362
Nic Smith
Final Project - Airline Reservation System */
#ifndef AIRPLANE_H
#define AIRPLANE_H
#include "Flight.h"
#include "Seat.h"
class Airplane {
private:
	char type;
	int numSeatsAvail, capacity, rows, cols, aisle;
	vector <Seat> allSeats;
	Flight f;
public:
	// constructors and destructors
	Airplane();
	~Airplane();
	Airplane(char);
	// functions
	void setUpType(char);
	bool planeFullYN();
	// accessors and mutators
	Flight &getFlight();
	char getType();
	int getNumSeatsAvail();
	int getCapacity();
	void setFlight(Flight);
	void setType(char);
	void setNumSeatsAvail(int);
	void setCapacity(int);
	vector <Seat> &getSeats();
	void setSeats();
	void viewSeats();

	static bool sortByDeparture(Airplane, Airplane);
	static bool sortByArrival(Airplane, Airplane);
	static bool sortByDepartureTime(Airplane, Airplane);
	static bool sortByArrivalTime(Airplane, Airplane);
	static bool sortByFlightNumber(Airplane, Airplane);
	static bool sortByFlightType(Airplane, Airplane);
	static bool sortByFreqFlyerPoints(Airplane, Airplane);
};


#endif