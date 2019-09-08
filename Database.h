#pragma once
#include <iostream>
#include<vector>
#include"Passenger.h"
#include"Flight.h"
#include"Ticket.h"

namespace AirlineReservationCPP {
	const int kdefaultPassengerNumber = 1000;
	const int kdefaultFlightNumber = 100;
	
	const int kdefaultTicketNumber = 1100;
	class Database {
	public:
		Database();
		Passenger& addPassenger(const std::string& firstname, const std::string& lastname, tm& birthdate, const std::string& gender);
		Flight& addFlight(const std::string& source, const std::string& destination, tm& date, tm& duration, const std::string& airlineName);
		Ticket& addTicket(int flightNumber);
		Passenger& getPassenger(const std::string& firstname, const std::string& lastname);
		const Passenger* getPassenger(int passengerNo) const;
		const std::vector<Flight> getFlights(const tm& travelDate, const std::string& source, const std::string& destination);
		void displayPassenger(int passengerNo) const;
		void addFlightForWeek(const std::string& source, const std::string& destnation, tm& date, tm& duration, const std::string& airlineName);
		void setSelectedFlight(Flight& flight);
		Flight& getSelectedFlight();
		const Flight* getFlight(int flightNumber) const;
		const Ticket* getTicket(int ticketNumber) const;

	private:
		std::vector<Passenger> mPassengers;
		std::vector<Flight> mFlights;
		std::vector<Ticket> mTicket;
		int mNextPassengerNumber = kdefaultPassengerNumber;
		int mFlightNumber = kdefaultFlightNumber;
		void DatePlusDays(struct tm* date, int days);
		bool equaltime(const tm& t1, const tm& t2);
		Flight mSelectedFlight;
		int mTicketNumber = kdefaultTicketNumber;
	};
}
