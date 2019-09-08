#include "Ticket.h"
#include "Database.h"
#include <iostream>
using namespace std;
namespace AirlineReservationCPP {
	Ticket::Ticket(int flightNumber, int ticketNumber) : mflightNumber(flightNumber), mTicketNumber(ticketNumber)
	{

	}
	int Ticket::getTicketNumber() const
	{
		return mTicketNumber;
	}
	void Ticket::addPassengerAndSeatNumber(int passengerNumber, std::string seatNumber)
	{
		mSeatNumber.push_back(seatNumber);
		mpassengerNo.push_back(passengerNumber);
	}

	void Ticket::displayTicket(Database& db) const
	{
		cout << "Your Ticket Details => " << endl;
		cout << endl << "Ticket Number => " << getTicketNumber() << endl;
		cout << endl << endl << "Flight Details => " << endl;
		const Flight* f = db.getFlight(mflightNumber);
		f->displayFlight(true, 0, true);
		int i = 0;
		for (auto& pNo : mpassengerNo)
		{
			const Passenger* p = db.getPassenger(pNo);
			p->display();
			cout << endl << "Seat Number => " << mSeatNumber[i] << endl<<endl<<endl ;
			i++;
		}
		
	}

	

}

