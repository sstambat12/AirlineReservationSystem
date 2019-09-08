#pragma once
#include <string>
#include <ctime>

namespace AirlineReservationCPP {

	class Passenger 
	{
	public:
		Passenger () = default;
		Passenger(const std::string& firstName,
			const std::string& lastName);

		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setPassengerNumber(int passengerNumber);
		int getPassengerNumber() const;

		void setGender(const std::string& gender);
		const std::string& getGender() const;

		void setBirthDate(tm& birthdate);
		const tm& getBirthDate() const;
		
		void display() const;

	private:
		std::string mFirstName;
		std::string mLastName;
		tm mBirthdate;
		int mPassengerNumber = -1;
		std::string mGender;



	};

		
}
