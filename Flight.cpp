#include "Flight.h"
#include <iostream>
#include <iomanip>
#include<sstream>

using namespace std;
namespace AirlineReservationCPP{

	Flight::Flight(int flightnumber): mFlightNumber(flightnumber)
	{ }

	Flight::Flight(const std::string & source, const std::string & destination):
		mSource(source), mDestination(destination)
	{
	}

	void Flight::setSource(const std::string & source)
	{
		mSource = source;
	}

	const std::string& Flight::getSource() const
	{
		// TODO: insert return statement here
		return mSource;
	}

	void Flight::setDestination(const std::string& destination)
	{
		mDestination = destination;
	}

	const std::string& Flight::getDestination() const
	{
		// TODO: insert return statement here
		return mDestination;
	}

	void Flight::setFlightNumber(int flightNo)
	{
		mFlightNumber = flightNo;
	}

	int Flight::getFlightNumber() const
	{
		return mFlightNumber;
	}

	
	void Flight::setDate(tm& date)
	{
		mDateOfTravel = date;
	}

	const tm& Flight::getDate() const
	{
		return mDateOfTravel;
	}

	void Flight::setDuration(tm& duration)
	{
		mDuration = duration;
	}

	const tm& Flight::getDuration() const
	{
		return mDuration;
	}

	std::string Flight::getNextSeatNumber()
	{
		string nextSeatNumber = mNextSeatNumber;
		int length = mNextSeatNumber.length();
		if (mNextSeatNumber[length - 1] == 'F')
		{
			int rownumber = stoi(mNextSeatNumber.substr(0, 2));
			rownumber++;
			string newstr = to_string(rownumber) + std::string("A");
			mNextSeatNumber = newstr;
		}
		else
		{
			mNextSeatNumber[length - 1] = mNextSeatNumber[length - 1] + 1;
		}
		return nextSeatNumber;
	}

	void Flight::setAirlineName(std::string airlineName)
	{
		mAirlineName = airlineName;
	}

	std::string Flight::getAirlineName() const
	{
		return mAirlineName;
	}

	void Flight::displayFlight(bool showHeader, int seqNo, bool isLastFlight) const
	{
		int w;
		if (seqNo == 0)
		{
			w = 68;
		}
		else
		{
			w = 75;
		}
		if (showHeader)
		{
			cout << setw(w) << setfill('-') << " "<< endl;
			cout<<setfill(' ');
			if (seqNo != 0)
			{
				cout << setw(1)<< "|" <<setw(6) << "No.|";
			}
			cout <<setw(11)<<"Flight No.|"<<setw(16)<< "Departure Time|" << setw(8) << "Source|" << setw(13) << "Destination|" 
				<< setw(9) << "Duration|" <<setw(10)<< "Airline|"<< endl;
			cout << setw(w) << setfill('-') << " " << endl;
			cout << setfill(' ');
		}
		if (seqNo != 0)
		{
			cout << setw(1) << "|"<<setw(5) <<seqNo << setw(1)<< "|";
		}
		string depart;
		string duration;
		stringstream s;
		stringstream sdepart;
		s << getDuration().tm_hour << "h" << getDuration().tm_min << "m";
		duration = s.str();
		sdepart << setw(2) << setfill('0') << getDate().tm_hour << ":" << setw(2) << getDate().tm_min;
		depart = sdepart.str();
		cout << setw(11)<< to_string(getFlightNumber()) + std::string("|") <<setw(16) << depart + std::string("|") << setw(8) << getSource() + std::string("|")
			<< setw(13) << getDestination() + std::string("|") << 
			setw(9) << duration + std::string("|") << setw(10) << getAirlineName() + std::string("|") <<endl;
		if (isLastFlight)
		{
			cout << setw(w) << setfill('-') << " " << endl;
			cout << setfill(' ');
		}
	}

}
