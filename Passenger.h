/*CIST 2362
Nic Smith
Final Project - Airline Reservation System */
#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>
using namespace std;
class Passenger {
protected:
	int flyerPoints, flightNum;
	string passFName, passLName, seatNum;
public:
	// constructors and destructors
	Passenger();
	~Passenger();
	Passenger(string, string, int, string, int);
	// accessors and mutators
	string getPassFName();
	string getPassLName();
	int getFlyerPoints();
	string getSeatNum();
	int getFlightNum();
	string getPassID();
	void setPassFName(string);
	void setPassLName(string);
	void setFlyerPoints(int);
	void setSeatNum(string);
	void setFlightNum(int);

	string toPassFile();
};
#endif