/*CIST 2362
Nic Smith
Final Project - Airline Reservation System */
#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Flight {
protected:
	char flightType;
	int flightNumber, freqFlyerPoints;
	string departure, arrival, departureCode, arrivalCode, departureTime, arrivalTime;
public:
	// constructors and destructors
	Flight();
	~Flight();
	Flight(int, int, string, string, string, string, string, string);
	// accessors and mutators
	char getFlightType();
	int getFlightNumber();
	int getFreqFlyerPoints();
	string getDeparture();
	string getArrival();
	string getDepartureCode();
	string getArrivalCode();
	string getDepartureTime();
	string getArrivalTime();
	void setFlightType(char);
	void setFlightNumber(int);
	void setFreqFlyerPoints(int);
	void setDeparture(string);
	void setArrival(string);
	void setDepartureCode(string);
	void setArrivalCode(string);
	void setDepartureTime(string);
	void setArrivalTime(string);

	string toFile();
};
#endif