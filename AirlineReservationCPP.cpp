// AirlineReservationCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Database.h"
#include "Ticket.h"
#include <stdexcept>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;
using namespace AirlineReservationCPP;

int displayMenu();
void reserveSeat(Database& db);
void scheduleFlight(Database& db);
void displayPassenger(Database& db);
void displayFlightDetails(Database& db);
void displayTicket(Database& db);
std::vector<Flight> availFlights(Database& db);

int main()
{
	Database db;
	while (true)
	{
		int selection = displayMenu();
		switch (selection)
		{
		case 0:
			return 0;
		case 1:
			scheduleFlight(db);
			break;
		case 2:
			reserveSeat(db);
			break;
		case 3:
			displayPassenger(db);
			break;
		case 4:
			displayFlightDetails(db);
			break;
		case 5:
			displayTicket(db);
			break;


		default:
			cerr << "UNKNOWN COMMAND." << endl;
			break;
		}
		cout << endl << endl;
		system("pause");
		cout << endl << endl;
	}
	

}

int displayMenu()
{
	int selection;
	
	cout << "--------------------------------------" << endl;
	cout << "Welcome to Airline Reservation System" << endl;
	cout << "--------------------------------------" << endl;
	cout << "1. Flight Schedule" << endl;
	cout << "2. Reserve a Seat" << endl;
	cout << "3. Display passenger info" << endl;
	cout << "4. Flight details" << endl;
	cout << "5. User ticket information" << endl;
	cout << "0. Exit the program" << endl;
	cout << "Please Enter your choice =>" << endl;

	cin >> selection;

	return selection;
}

void reserveSeat(Database& db)
{
	std::vector<Flight> availableFlights = availFlights(db);
	if (availableFlights.size() == 0)
	{
		return;
	}
	int choice;
	while(true)
	{	
		cout << endl << endl<< "Select a flight => ";
		cin >> choice;
		if (choice <= availableFlights.size())
		{
			break;
		}
		cout << endl<< "Please Select Correct flight Number " <<endl;
	}
	Flight f = availableFlights[choice - 1];
	cout <<endl<< "Your selected flight =>" << endl << endl;
	f.displayFlight(true, 0, true);
	db.setSelectedFlight(f);
	int numberOfPassenger;
	cout << endl << "Enter the number of Passengers => ";
	cin >> numberOfPassenger;
	string firstName;
	string lastName;
	string gender;
	tm birthdate;
	string date;
	int i = 1;
	Ticket& ticket = db.addTicket(f.getFlightNumber());
	while(numberOfPassenger > 0)
	{
		cout << "Please Enter Details for passenger " << i << "=>" <<endl;
		cout << endl;
		cout <<setw(25)<< "First name " <<"=> ";
		cin >> firstName;
		cout << setw(25) << "Last name " <<"=> ";
		cin >> lastName;
		cout << "Date of Birth(mm/dd/yyyy)=> ";
		cin >> date;
		int tmonth = stoi(date.substr(0, 2));
		int tday = stoi(date.substr(3, 2));
		int tyear = stoi(date.substr(6, 4));
		birthdate.tm_mon = tmonth - 1;
		birthdate.tm_mday = tday;
		birthdate.tm_year = tyear - 1900;
		cout <<setw(25)<< "Gender " << "=> ";
		cin >> gender;
		Passenger passenger = db.addPassenger(firstName, lastName, birthdate, gender);
		
		ticket.addPassengerAndSeatNumber(passenger.getPassengerNumber(), f.getNextSeatNumber());
		cout << endl;
		cout << "Passenger added with Passenger Number => " << passenger.getPassengerNumber() << endl << endl;

		numberOfPassenger--;
		i++;
	}
	cout << "Congratulations..!! Your ticket has been booked..!!!" << endl <<endl;
	cout << "Ticket Number => " << ticket.getTicketNumber() << endl<<endl;
	
}

void scheduleFlight(Database& db)
{
	availFlights(db);
}

void displayPassenger(Database& db)
{
	int number;
	cout << endl << "Please Enter Passenger Number => " << endl;
	cin >> number;

	db.displayPassenger(number);
}

void displayFlightDetails(Database& db)
{
	Flight f = db.getSelectedFlight();
	if (f.getFlightNumber() == -1)
	{
		cout << endl << "You have not selected any Flight...!!" << endl << endl;
		return;
	}
	cout << endl << "Your Flight details =>" << endl<<endl;
	f.displayFlight(true, 0, true);
	
}

void displayTicket(Database& db)
{
	int number;
	cout << endl << "Please Enter Ticket Number => " << endl;
	cin >> number;
	cout << endl;
	
	const Ticket* ticket = db.getTicket(number);
	if (ticket != nullptr)
		ticket->displayTicket(db);
	else
		cout << endl << "Invalid Ticket Number...!!" << endl;
}

std::vector<Flight> availFlights(Database& db)
{
	string source;
	string destination;
	tm tdate;
	string traveldate;
	cout << endl << endl;
	cout << setw(28) << "Date of Travel(mm/dd/yyyy) " <<"=>";
	cin >> traveldate;
	cout << setw(28)<<"Source  " <<"=>";
	cin >> source;
	cout << setw(28) << "Destination " <<"=>";
	cin >> destination;
	
	int month = stoi(traveldate.substr(0, 2));
	int day = stoi(traveldate.substr(3, 2));
	int year = stoi(traveldate.substr(6, 4));
	tdate.tm_mon = month - 1;
	tdate.tm_mday = day;
	tdate.tm_year = year - 1900;
	std::vector<Flight> availableFlights = db.getFlights(tdate, source, destination);
	if (availableFlights.size() == 0)
	{
		cout << endl << "No Flights available...!! " << endl;
		return availableFlights;
	}
	int i = 1;
	cout << endl << "Your Flight Details => " << endl;
	for (auto& f : availableFlights)
	{
		f.displayFlight(i == 1, i, i== availableFlights.size());
		i++;
	}
	return availableFlights;
}
