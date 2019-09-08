#include "Passenger.h"
#include <iostream>
#include <iomanip>


using namespace std;

namespace AirlineReservationCPP {
	Passenger::Passenger(const std::string& firstName, const std::string& lastName) :
		mFirstName(firstName), mLastName(lastName)
	{ }

	void Passenger::setFirstName(const std::string& firstName)
	{
		mFirstName = firstName;
	}
	const std::string& Passenger::getFirstName() const
	{
		return mFirstName;
	}
	void Passenger::setLastName(const std::string& lastName)
	{
		mLastName = lastName;
	}
	const std::string& Passenger::getLastName() const
	{
		return mLastName;
	}
	void Passenger::setPassengerNumber(int passengerNumber)
	{
		mPassengerNumber = passengerNumber;
	}

	int Passenger::getPassengerNumber() const
	{
		return mPassengerNumber;
	}

	void Passenger::setGender(const std::string& gender)
	{
		mGender = gender;
	}

	const std::string& Passenger::getGender() const
	{
		// TODO: insert return statement here
		return mGender;
	}

	void Passenger::setBirthDate(tm& birthdate)
	{
		mBirthdate = birthdate;
	}

	const tm& Passenger::getBirthDate() const
	{

		return mBirthdate;
	}

	void Passenger::display() const
	{
		char str[26];
		tm birthdate = getBirthDate();
		strftime(str, sizeof(str), "%b %d %Y", &birthdate);
		cout << endl;
		cout << setw(12)<<"Passenger : " << getFirstName() << " " << getLastName() << endl;
		cout << setw(12)<<"Birthdate : " << str << endl;
		cout << setw(12)<<"Gender : " << getGender() << endl;
		
	}
	
}