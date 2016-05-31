/*CIST 2362
Nic Smith
Final Project - Airline Reservation System */
#include "Airplane.h"
#include "City.h"
// function prototypes
void bookReservation();
void cancelReservation();
vector <City> readCityFile();
vector <Airplane> readFile();
vector <Passenger> readPassengerFile();

int main() {
	// create lists of objects, read from files
	vector <City> cityList = readCityFile();
	vector <Airplane> airplaneList = readFile();
	vector <Passenger> passengerList = readPassengerFile();
	Passenger tempPass;

	// initialize variables
	int menuChoice, dispFlightChoice, availCityChoice, pFlightNumber, pFFPoints;
	string pFirstName, pLastName, seatChoice;
	bool error, bigError, medError, cancelError, quit = false;
	
	// display main menu
	while (!quit) {
		cout << "Welcome to the Airline Reservation System!\n\n"
			"1: Display flight schedule\n"
			"2: Display available cities\n"
			"3: Display passenger's boarding pass\n"
			"4: Book a reservation\n"
			"5: Cancel a reservation\n"
			"6: Quit program\n";
		cin >> menuChoice;
		switch (menuChoice) {
		case 1:
			// display flight schedule
			cout << "\nHow would you like to view the flight schedule?\n"
				"1: Departure\n"
				"2: Arrival\n"
				"3: Departure Time\n"
				"4: Arrival Time\n"
				"5: Flight Number\n"
				"6: Airplane Type\n"
				"7: Frequent Flyer Points\n";
			cin >> dispFlightChoice;
			while (dispFlightChoice < 1 || dispFlightChoice > 7) {
				cout << "\nSorry, please enter a valid choice (1-7): ";
				cin >> dispFlightChoice;
			}
			switch (dispFlightChoice) {
			case 1:
				// display flight schedule by departure
				cout << "\n\nDep\tArr\tDTime\tATime\tF#\tType\tFFP\n";
				cout << "---------------------------------------------------\n";
				sort(airplaneList.begin(), airplaneList.end(), Airplane::sortByDeparture);
				for (Airplane plane : airplaneList) {
					cout << plane.getFlight().getDeparture() + "\t" + plane.getFlight().getArrival() + "\t" + plane.getFlight().getDepartureTime()
						+ "\t" + plane.getFlight().getArrivalTime() + "\t" + to_string(plane.getFlight().getFlightNumber()) + "\t" +
						plane.getFlight().getFlightType() + "\t" + to_string(plane.getFlight().getFreqFlyerPoints()) + "\n";
				}
				break;
			case 2:
				// display flight schedule by arrival
				cout << "\n\nDep\tArr\tDTime\tATime\tF#\tType\tFFP\n";
				cout << "---------------------------------------------------\n";
				sort(airplaneList.begin(), airplaneList.end(), Airplane::sortByArrival);
				for (Airplane plane : airplaneList) {
					cout << plane.getFlight().getDeparture() + "\t" + plane.getFlight().getArrival() + "\t" + plane.getFlight().getDepartureTime()
						+ "\t" + plane.getFlight().getArrivalTime() + "\t" + to_string(plane.getFlight().getFlightNumber()) + "\t" +
						plane.getFlight().getFlightType() + "\t" + to_string(plane.getFlight().getFreqFlyerPoints()) + "\n";
				}
				break;
			case 3:
				// display flight schedule by departure time
				cout << "\n\nDep\tArr\tDTime\tATime\tF#\tType\tFFP\n";
				cout << "---------------------------------------------------\n";
				sort(airplaneList.begin(), airplaneList.end(), Airplane::sortByDepartureTime);
				for (Airplane plane : airplaneList) {
					cout << plane.getFlight().getDeparture() + "\t" + plane.getFlight().getArrival() + "\t" + plane.getFlight().getDepartureTime()
						+ "\t" + plane.getFlight().getArrivalTime() + "\t" + to_string(plane.getFlight().getFlightNumber()) + "\t" +
						plane.getFlight().getFlightType() + "\t" + to_string(plane.getFlight().getFreqFlyerPoints()) + "\n";
				}
				break;
			case 4:
				// display flight schedule by arrival time
				cout << "\n\nDep\tArr\tDTime\tATime\tF#\tType\tFFP\n";
				cout << "---------------------------------------------------\n";
				sort(airplaneList.begin(), airplaneList.end(), Airplane::sortByArrivalTime);
				for (Airplane plane : airplaneList) {
					cout << plane.getFlight().getDeparture() + "\t" + plane.getFlight().getArrival() + "\t" + plane.getFlight().getDepartureTime()
						+ "\t" + plane.getFlight().getArrivalTime() + "\t" + to_string(plane.getFlight().getFlightNumber()) + "\t" +
						plane.getFlight().getFlightType() + "\t" + to_string(plane.getFlight().getFreqFlyerPoints()) + "\n";
				}
				break;
			case 5:
				// display flight schedule by flight number
				cout << "\n\nDep\tArr\tDTime\tATime\tF#\tType\tFFP\n";
				cout << "---------------------------------------------------\n";
				sort(airplaneList.begin(), airplaneList.end(), Airplane::sortByFlightNumber);
				for (Airplane plane : airplaneList) {
					cout << plane.getFlight().getDeparture() + "\t" + plane.getFlight().getArrival() + "\t" + plane.getFlight().getDepartureTime()
						+ "\t" + plane.getFlight().getArrivalTime() + "\t" + to_string(plane.getFlight().getFlightNumber()) + "\t" +
						plane.getFlight().getFlightType() + "\t" + to_string(plane.getFlight().getFreqFlyerPoints()) + "\n";
				}
				break;
			case 6:
				// display flight schedule by flight type
				cout << "\n\nDep\tArr\tDTime\tATime\tF#\tType\tFFP\n";
				cout << "---------------------------------------------------\n";
				sort(airplaneList.begin(), airplaneList.end(), Airplane::sortByFlightType);
				for (Airplane plane : airplaneList) {
					cout << plane.getFlight().getDeparture() + "\t" + plane.getFlight().getArrival() + "\t" + plane.getFlight().getDepartureTime()
						+ "\t" + plane.getFlight().getArrivalTime() + "\t" + to_string(plane.getFlight().getFlightNumber()) + "\t" +
						plane.getFlight().getFlightType() + "\t" + to_string(plane.getFlight().getFreqFlyerPoints()) + "\n";
				}
				break;
			case 7:
				// display flight schedule by frequent flyer points
				cout << "\n\nDep\tArr\tDTime\tATime\tF#\tType\tFFP\n";
				cout << "---------------------------------------------------\n";
				sort(airplaneList.begin(), airplaneList.end(), Airplane::sortByFreqFlyerPoints);
				for (Airplane plane : airplaneList) {
					cout << plane.getFlight().getDeparture() + "\t" + plane.getFlight().getArrival() + "\t" + plane.getFlight().getDepartureTime()
						+ "\t" + plane.getFlight().getArrivalTime() + "\t" + to_string(plane.getFlight().getFlightNumber()) + "\t" +
						plane.getFlight().getFlightType() + "\t" + to_string(plane.getFlight().getFreqFlyerPoints()) + "\n";
				}
				break;
			}
			break;
		case 2:
			// display available cities
			cout << "\n\nCode\tName\n";
			cout << "-------------------------\n";
			for (City myCity : cityList) {
				cout << myCity.getCityCode() + "\t" + myCity.getCityName() + "\n";
			}
			break;
		case 3:
			// display passenger's boarding pass

		case 4:
			// book a reservation
			bigError = true;
			while (bigError) {
				// get input from user
				cout << "\n\nEnter your first name: ";
				cin >> pFirstName;
			
				cout << "\n\nEnter your last name: ";
				cin >> pLastName;
				// get flight number from user
				cout << "\n\nEnter your frequent flyer points: ";
				cin >> pFFPoints;
				bigError = true;
				while (bigError) {
					cout << "\n\nEnter a flight number: ";
					cin >> pFlightNumber;
					// create temp passenger from input
					tempPass.setPassFName(pFirstName);
					tempPass.setPassLName(pLastName);
					tempPass.setFlyerPoints(pFFPoints);
					// for loop airplanelist

					for (int u = 0; u < airplaneList.size(); u++) {
						// if that equals plane, search through plane seats
						if (airplaneList.at(u).getFlight().getFlightNumber() == pFlightNumber) {
							bigError = false;
							medError = true;
							while (medError) {
								airplaneList.at(u).viewSeats();
								cout << "Enter seat you want to book: ";
								cin >> seatChoice;
								for (int k = 0; k < airplaneList.at(u).getSeats().size(); k++) {

									if (airplaneList.at(u).getSeats().at(k).seatOpenYN() && airplaneList.at(u).getSeats().at(k).getSeatNumber() == seatChoice) {
										tempPass.setPassFName(pFirstName);
										tempPass.setPassLName(pLastName);
										tempPass.setFlyerPoints(pFFPoints);
										tempPass.setFlightNum(pFlightNumber);
										tempPass.setSeatNum(airplaneList.at(u).getSeats().at(k).getSeatNumber());
										
										cout << tempPass.getPassFName() << endl;
										cout << tempPass.getPassLName() << endl;
										cout << tempPass.getFlightNum() << endl;
										cout << tempPass.getSeatNum() << endl;
										cout << tempPass.getFlyerPoints() << endl;
										

										passengerList.push_back(tempPass);
										airplaneList.at(u).getSeats().at(k).setSeatOpen(false);
										medError = false;
									}
								}
								if (medError) {
									cout << "Sorry that seat is not available.\nDo you want to try again: ";
									cin >> pFirstName;
									if (pFirstName != "y") {
										medError = false;
									}
								}
							}
						}
					}
					if (bigError) {
						cout << "Sorry that flight number is not available.\nDo you want to try again: ";
						cin >> pFirstName;
						if (pFirstName != "y") {
							bigError = false;
						}
					}
				}
			}
			break;
		case 5:
			// cancel a reservation
			// get input from user
			cancelError = true;
			while (cancelError) {
				cout << "\n\nEnter your first name: ";
				cin >> pFirstName;
				cout << "\n\nEnter your last name: ";
				cin >> pLastName;
				// loop through passengerList, if found, erase passenger from list
				cancelError = true;
				while (cancelError) {
					for (int g = 0; g < passengerList.size(); g++) {
						if (passengerList.at(g).getPassID() == pFirstName + pLastName) {
							passengerList.erase(passengerList.begin() + g);
							cancelError = false;
							cout << "Success!";
							break;
						}
					}
					if (cancelError) {
						cout << "Sorry that passenger is not listed.\nDo you want to search again: ";
						cin >> pFirstName;
						if (pFirstName != "y") {
							cancelError = false;
						}
					}
				}
			}
			break;
		case 6:
			quit = true;
			break;
		default:
			cout << "\nSorry, please enter a valid choice (1-6): ";
			break;
		}

	}

	system("pause");
	// save airplaneList and write flight schedule to
	ofstream outfile;
	outfile.open("FlightSchedule.csv");
	for (int w = 0; w < airplaneList.size(); w++) {
		outfile << airplaneList.at(w).getFlight().toFile();
		if (w < airplaneList.size() - 1) {
			outfile << endl;
		}
	}
	outfile.close();

	outfile.open("AllPassengers.csv");
	for (int w = 0; w < passengerList.size(); w++) {
		outfile << passengerList.at(w).toPassFile();
		if (w < passengerList.size() - 1) {
			outfile << endl;
		}
	}
	outfile.close();
	return 0;
}
vector <City> readCityFile() {
	vector <City> cityList;
	string temp;
	ifstream inFile;
	inFile.open("AvailableCities.csv");
	while (!inFile.eof()) {

		// read each line from file
		inFile >> temp;
		// take that line, place into stream
		istringstream line(temp);
		// holds temp info about City class
		vector <string> cityInfo;
		// for each variable that's in the City class
		for (int r = 0; r < 2; r++) {
			// take istringstream = line, break it up using comma dilimeter
			// and take each broken up piece in temp per loop iteration
			getline(line, temp, ',');
			// add piece to temp vector of Flight class information
			cityInfo.push_back(temp);
		}
		// create newTemp City
		City tempCity;
		// set each element to variable in tempCity City
		tempCity.setCityCode(cityInfo.at(0));
		tempCity.setCityName(cityInfo.at(1));
		// create tempCity City
		// add tempCity to cityList
		cityList.push_back(tempCity);
	}
	return cityList;
}
vector <Airplane> readFile() {
	vector <Airplane> airplaneList;

	string temp;
	ifstream inFile;
	inFile.open("FlightSchedule.csv");

	while (!inFile.eof()) {

		// read each line from file
		inFile >> temp;
		// take that line, place into stream
		istringstream line(temp);
		// holds temp info about Flight class
		vector <string> flightInfo;
		// for each variable that's in the Flight class
		for (int r = 0; r < 7; r++) {
			// take istringstream = line, break it up using comma dilimeter
			// and take each broken up piece in temp per loop iteration
			getline(line, temp, ',');
			// add piece to temp vector of Flight class information
			flightInfo.push_back(temp);
		}
		// create newTemp Flight
		Flight newTemp;
		// set each element to variable in newTemp Flight
		newTemp.setDeparture(flightInfo.at(0));
		newTemp.setArrival(flightInfo.at(1));
		newTemp.setDepartureTime(flightInfo.at(2));
		newTemp.setArrivalTime(flightInfo.at(3));
		newTemp.setFlightNumber(stoi(flightInfo.at(4)));
		newTemp.setFlightType(flightInfo.at(5)[0]);
		newTemp.setFreqFlyerPoints(stoi(flightInfo.at(6)));
		// create tempPlane Airplane
		Airplane tempPlane;
		// set flightType of Flight to type of Airplane
		tempPlane.setUpType(newTemp.getFlightType());
		// puts newTemp info and sets new Flight in Airplane
		tempPlane.setFlight(newTemp);
		// add tempPlane to airplaneList
		airplaneList.push_back(tempPlane);
	}
	return airplaneList;
}
vector <Passenger> readPassengerFile() {
	vector <Passenger> passengerList;

	string temp;
	ifstream inFile;
	inFile.open("AllPassengers.csv");

	while (!inFile.eof()) {

		// read each line from file
		inFile >> temp;
		// take that line, place into stream
		istringstream line(temp);
		// holds temp info about Flight class
		vector <string> passInfo;
		// for each variable that's in the Flight class
		for (int r = 0; r < 5; r++) {
			// take istringstream = line, break it up using comma dilimeter
			// and take each broken up piece in temp per loop iteration
			getline(line, temp, ',');
			// add piece to temp vector of Flight class information
			passInfo.push_back(temp);
		}
		// create newTemp Flight
		Passenger newTemp;
		// set each element to variable in newTemp Flight
		newTemp.setPassFName(passInfo.at(0));
		newTemp.setPassLName(passInfo.at(1));
		newTemp.setFlyerPoints(stoi(passInfo.at(2)));
		newTemp.setSeatNum(passInfo.at(3));
		newTemp.setFlightNum(stoi(passInfo.at(4)));
		// add tempPlane to airplaneList
		passengerList.push_back(newTemp);
	}
	return passengerList;
}