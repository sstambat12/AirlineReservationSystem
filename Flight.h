#pragma once
#include <string>

namespace AirlineReservationCPP {
	class Flight {
	public:
		Flight() = default;
		Flight(int flightnumber);
		Flight(const std::string& source, const std::string& destination);

		void setSource(const std::string& source);
		const std::string& getSource() const;

		void setDestination(const std::string& destination);
		const std::string& getDestination() const;

		void setFlightNumber(int flightNo);
		int getFlightNumber() const;

		void setDate(tm& date);
		const tm& getDate() const;

		void setDuration(tm& duration);
		const tm& getDuration() const;

		std::string getNextSeatNumber();

		void setAirlineName(std::string airlineName);
		std::string getAirlineName() const;

		void displayFlight(bool showHeader, int seqNo, bool isLastFlight) const;
		
	private:
		tm mDateOfTravel;
		std::string mSource;
		std::string mDestination;
		int mFlightNumber = -1;
		tm mDuration;
		std::string mNextSeatNumber = "11A";
		std::string mAirlineName;
	
	};
}
