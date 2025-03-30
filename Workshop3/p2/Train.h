/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 9/28/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H
namespace sdds {
	const int MIN_TIME = 700;
	const int MAX_TIME = 2300;
	const int MAX_NO_OF_PASSENGERS = 1000;
	class Train{
		char* train_name;
		int p_aboard;
		int dep_time;
		int passengers;
		int new_dep_time;
		int totalPassengers;
	public:
		void initialize();
		bool validTrainName(const char* name);
		bool validTime(int value)const;
		bool validNoOfPassengers(int value)const;
		void set(const char* name);
		void set(int noOfPassengers, int departure);
		void set(const char* name, int noOfPassengers, int departure);
		void finalize();
		bool isInvalid() const;
		bool isValid() const;
		int noOfPassengers() const;
		const char* getName() const;
		int getDepartureTime() const;
		void display() const;
		//
		bool load(int& cantBoard);
		bool load(int passengers, int& cantBoard);

		bool updateDepartureTime();
		bool transfer(const Train& from);
		
	};
}



#endif // !SDDS_TRAIN_H

