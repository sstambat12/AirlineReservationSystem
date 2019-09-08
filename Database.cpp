#include <stdexcept>
#include "Database.h"

using namespace std;
namespace AirlineReservationCPP {
	Database::Database()
	{
		time_t t = time(nullptr);
		tm tmnow;
		localtime_s(&tmnow, &t);
		tm duration;
		duration.tm_hour = 5;
		duration.tm_min = 35;
		tmnow.tm_hour = 13;
		tmnow.tm_min = 11;
		addFlightForWeek("SEA", "JFK", tmnow, duration, "JetBlue");
		duration.tm_hour = 5;
		duration.tm_min = 15;
		tmnow.tm_hour = 13;
		tmnow.tm_min = 53;
		addFlightForWeek("SEA", "JFK", tmnow, duration, "Alaska");
		duration.tm_hour = 5;
		duration.tm_min = 31;
		tmnow.tm_hour = 11;
		tmnow.tm_min = 20;
		addFlightForWeek("SEA", "JFK", tmnow, duration, "Delta");
		duration.tm_hour = 5;
		duration.tm_min = 25;
		tmnow.tm_hour = 7;
		tmnow.tm_min = 25;
		addFlightForWeek("SEA", "JFK", tmnow, duration, "Alaska");
		duration.tm_hour = 5;
		duration.tm_min = 14;
		tmnow.tm_hour = 22;
		tmnow.tm_min = 55;
		addFlightForWeek("SEA", "JFK", tmnow, duration, "Delta");
		duration.tm_hour = 8;
		duration.tm_min = 37;
		tmnow.tm_hour = 06;
		tmnow.tm_min = 04;
		addFlightForWeek("SEA", "JFK", tmnow, duration, "American");
	}
	Passenger& Database::addPassenger(const std::string& firstname, const std::string& lastname,
		 tm& birthdate, const std::string& gender)
	 {
		// TODO: insert return statement here
		 Passenger thePassenger(firstname, lastname);
		 thePassenger.setBirthDate(birthdate);
		 thePassenger.setGender(gender);
		 thePassenger.setPassengerNumber(mNextPassengerNumber++);
		 thePassenger.getPassengerNumber();
		 mPassengers.push_back(thePassenger);

		 return mPassengers[mPassengers.size() - 1];


	 }
	 Flight& Database::addFlight(const std::string& source, const std::string& destination, tm& date, tm& duration,
								const std::string& airlineName)
	 {
		 // TODO: insert return statement here
		 Flight flight(source, destination);
		 flight.setDate(date);
		 flight.setDuration(duration);
		 flight.setFlightNumber(mFlightNumber++);
		 flight.setAirlineName(airlineName);
		 //flight.setRemainingSeats(mRemainingSeats--);

		 mFlights.push_back(flight);

		 return mFlights[mFlights.size() - 1];
	 }
	 
	 Ticket& Database::addTicket(int flightNumber)
	 {
		 Ticket ticket(flightNumber, mTicketNumber++);

		 mTicket.push_back(ticket);

		 return mTicket[mTicket.size() - 1];
	 }

	 Passenger& Database::getPassenger(const std::string& firstname, const std::string& lastname)
	 {
		 // TODO: insert return statement here
		 for (auto& passenger : mPassengers)
		 {
			 if (passenger.getFirstName() == firstname && passenger.getLastName() == lastname)
			 {
				 return passenger;
			 }
		 }
		 throw logic_error("No Passenger found..!");
	 }
	 const Passenger* Database::getPassenger(int passengerNo) const
	 {
		 for (auto& p : mPassengers)
		 {
			 if (p.getPassengerNumber() == passengerNo)
			 {
				 return &p;
			 }
		 }
		 return nullptr;
	 }
	 const std::vector<Flight> Database::getFlights(const tm& travelDate, const std::string& source, const std::string& destination)
	 {
		 
		 std::vector<Flight> availflight;
		 for (auto& flight : mFlights)
		 {
			 if (equaltime(travelDate,flight.getDate()) && source == flight.getSource() && destination == flight.getDestination())
			 {
				 availflight.push_back(flight);
			 }
		 }
		 return availflight;
	 }
	 void Database::displayPassenger(int passengerNo) const
	 {
		 const Passenger* p = getPassenger(passengerNo);
		 if (p != nullptr)
			 p->display();
		 else
			 cout << "Enter Correct Passenger number !!" << endl;
	 }

	 bool Database::equaltime(const tm& t1, const tm& t2)
	 {
		 if (t1.tm_mday == t2.tm_mday && t1.tm_mon == t2.tm_mon && t1.tm_year == t2.tm_year)
		 {
			 return true;
		 }
		 return false;
	 }

	 void Database::addFlightForWeek(const string& source, const string& destnation, tm& date, tm& duration, 
									const string& airlineName)
	 {
		 for (int i = 1; i <= 7; i++)
		 {
			 tm newDate = date;
			 DatePlusDays(&newDate, i);
			 addFlight(source, destnation, newDate, duration, airlineName);
		 }
	 }
	 void Database::setSelectedFlight(Flight& flight)
	 {
		 mSelectedFlight = flight;
	 }
	 Flight& Database::getSelectedFlight()
	 {
		 return mSelectedFlight;
	 }
	 const Flight* Database::getFlight(int flightNumber) const
	 {
		 for (auto& f : mFlights)
		 {
			 if (f.getFlightNumber() == flightNumber)
			 {
				 return &f;
			 }
		 }
		 return nullptr;
	 }
	 const Ticket* Database::getTicket(int ticketNumber) const
	 {
		 for (auto& t : mTicket)
		 {
			 if (ticketNumber == t.getTicketNumber())
			 {
				 return &t;
			 }
		 }
		 return nullptr;
	 }
	 void Database::DatePlusDays(struct tm* date, int days)
	 {
		 const time_t ONE_DAY = 24 * 60 * 60;

		 // Seconds since start of epoch
		 time_t date_seconds = mktime(date) + (days * ONE_DAY);

		 // Update caller's date
		 // Use localtime because mktime converts to UTC so may change date
		 localtime_s(date,&date_seconds); ;
	 }
}
