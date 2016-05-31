/*CIST 2362
Nic Smith
Final Project - Airline Reservation System */
#include "Airplane.h"
// constructors and destructors
Airplane::Airplane() {}
Airplane::~Airplane() {}
Airplane::Airplane(char t) {
	type = toupper(t);
	setUpType(type);
}
// functions
bool Airplane::planeFullYN() {
	if (numSeatsAvail == 0)
		return true;
}
// accessors and mutators
char Airplane::getType() {
	return type;
}
int Airplane::getNumSeatsAvail() {
	return numSeatsAvail;
}
int Airplane::getCapacity() {
	return capacity;
}
Flight &Airplane::getFlight() {
	return this->f;
}
void Airplane::setType(char t) {
	this->type = t;
}
void Airplane::setNumSeatsAvail(int nsa) {
	this->numSeatsAvail = nsa;
}
void Airplane::setCapacity(int c) {
	this->capacity = c;
}
void Airplane::setFlight(Flight f) {
	this->f = f;
}
vector <Seat> &Airplane::getSeats() {
	return this->allSeats;
}
// sets seat on airplane by row and column
void Airplane::setSeats() {
	string abc = "ABCDEFGHI";
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			this->allSeats.push_back(Seat(to_string(row + 1) + abc[col]));
		}
	}
}
void Airplane::viewSeats() {
	// loop to view airplane layout with seats
	for (int row = 0, seat = 0; row < this->rows; row++) {
		for (int col = 0; col < this->cols + 1; col++, seat++) {
			if (col != this->aisle && allSeats.at(seat).seatOpenYN()) {
				cout << allSeats.at(seat).getSeatNumber() << " ";
			}
			else if (col != this->aisle) {
				cout << "--";
			}
			else {
				seat--;
				// display aisle
				cout << "XX ";
			}
		}
		cout << endl;
	}
}
void Airplane::setUpType(char t) {
	// input char and use to set up airplane type
	switch (toupper(t)) {
	case 'A':
		this->rows = 5;
		this->cols = 4;
		this->aisle = 2;
		break;
	case 'B':
		this->rows = 5;
		this->cols = 3;
		this->aisle = 1;
		break;
	default:
		this->rows = 5;
		this->cols = 4;
		this->aisle = 2;
		break;
	}
	setSeats();
}
// sorts airplaneList by departure
bool Airplane::sortByDeparture(Airplane a, Airplane b) {
	string tempA = a.f.getDeparture() + a.f.getArrival() + to_string(a.f.getFlightNumber());
	string tempB = b.f.getDeparture() + b.f.getArrival() + to_string(b.f.getFlightNumber());
	return (tempA < tempB);
}
// sorts airplaneList by arrival
bool Airplane::sortByArrival(Airplane a, Airplane b) {
	string tempA = a.f.getArrival() + a.f.getDeparture() + to_string(a.f.getFlightNumber());
	string tempB = b.f.getArrival() + b.f.getDeparture() + to_string(b.f.getFlightNumber());
	return (tempA < tempB);
}
// sorts airplaneList by departure time
bool Airplane::sortByDepartureTime(Airplane a, Airplane b) {
	string tempA = a.f.getDepartureTime() + a.f.getDeparture() + a.f.getArrival();
	string tempB = b.f.getDepartureTime() + b.f.getDeparture() + b.f.getArrival();
	return (tempA < tempB);
}
// sorts airplaneList by arrival time
bool Airplane::sortByArrivalTime(Airplane a, Airplane b) {
	string tempA = a.f.getArrivalTime() + a.f.getDeparture() + a.f.getArrival();
	string tempB = b.f.getArrivalTime() + b.f.getDeparture() + b.f.getArrival();
	return (tempA < tempB);
}
// sorts airplaneList by flight number
bool Airplane::sortByFlightNumber(Airplane a, Airplane b) {
	string tempA = to_string(a.f.getFlightNumber()) + a.f.getDeparture() + a.f.getArrival();
	string tempB = to_string(b.f.getFlightNumber()) + b.f.getDeparture() + b.f.getArrival();
	return (tempA < tempB);
}
// sorts airplaneList by airplane type
bool Airplane::sortByFlightType(Airplane a, Airplane b) {
	string tempA = a.f.getFlightType() + a.f.getDeparture() + a.f.getArrival();
	string tempB = b.f.getFlightType() + b.f.getDeparture() + b.f.getArrival();
	return (tempA < tempB);
}
// sorts airplaneList by frequent flyer points
bool Airplane::sortByFreqFlyerPoints(Airplane a, Airplane b) {
	string tempA = to_string(a.f.getFreqFlyerPoints()) + a.f.getDeparture() + a.f.getArrival();
	string tempB = to_string(b.f.getFreqFlyerPoints()) + b.f.getDeparture() + b.f.getArrival();
	return (tempA < tempB);
}