/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 9/28/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Train.h"
#include<cstring>
#include <iostream>

using namespace std;

void sdds::Train::initialize()
{
	
	train_name = nullptr;
	dep_time = -1;
	p_aboard = -1;
}

bool sdds::Train::validTime(int value) const
{
	/*int hours=value/100;*/
	int minutes=value %100;
	//return true if condition is met
	return (value >= MIN_TIME && value <= MAX_TIME && minutes <= 59);
}

bool sdds::Train::validNoOfPassengers(int value) const
{
	//return true if condition is met
	return(value > 0 && value <= MAX_NO_OF_PASSENGERS);

}

void sdds::Train::set(const char* name)
{
	delete[] train_name;
	train_name = nullptr;

	if (name !=nullptr && name[0]!='\0')
	{
		train_name = new char[strlen(name) + 1];

		strcpy(train_name, name);
	}
}

void sdds::Train::set(int noOfPassengers, int departure)
{
	if (validNoOfPassengers(noOfPassengers) && validTime(departure))
	{
		p_aboard = noOfPassengers;
		dep_time = departure;
	}
	else {
		p_aboard = -1;
		dep_time = -1;
	}
}

void sdds::Train::set(const char* name, int noOfPassengers, int departure)
{
	if (validNoOfPassengers(noOfPassengers) && validTime(departure) && name != nullptr && name[0] != '\0')
	{
		//cleanup
		delete[] train_name;
		train_name = nullptr;

		train_name = new char[strlen(name) + 1];
		strcpy(train_name, name);
		p_aboard = noOfPassengers;
		dep_time = departure;
	}
	//else
	//	train_name = nullptr;
	//	p_aboard = -1;
	//	dep_time = -1;
}

void sdds::Train::finalize()
{
	delete[] train_name;
	train_name = nullptr;
}

bool sdds::Train::isInvalid() const
{
	//return true if condition is met
	
	return (train_name == nullptr || p_aboard == -1 || dep_time == -1);

}

int sdds::Train::noOfPassengers() const
{
	return p_aboard;
}

const char* sdds::Train::getName() const
{
	return train_name;
}

int sdds::Train::getDepartureTime() const
{
	return dep_time;
}

void sdds::Train::display() const
{
	if (validNoOfPassengers(p_aboard) && validTime(dep_time) && train_name != nullptr)
	{
		cout << "NAME OF THE TRAIN:    " << train_name << endl;
		cout << "NUMBER OF PASSENGERS: " << p_aboard << endl;
		cout << "DEPARTURE TIME:       " << dep_time << endl;
	}
	else
		cout << "Train in an invalid State!" << endl;
}
