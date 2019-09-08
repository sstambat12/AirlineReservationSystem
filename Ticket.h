#pragma once
#include "Flight.h"
#include "Passenger.h"
#include<string>
#include <vector>



namespace AirlineReservationCPP {
	class Database;
	class Ticket {
	public:
		Ticket(int flightNumber, int ticketNumber);
		int getTicketNumber() const;
		void addPassengerAndSeatNumber(int passengerNumber, std::string seatNumber);
		void displayTicket(Database& db) const;
	private:
		std::vector<std::string> mSeatNumber;
		std::vector<int> mpassengerNo;
		int mflightNumber;
		int mTicketNumber;
	};
}
