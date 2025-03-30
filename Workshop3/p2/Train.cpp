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
	passengers = 0;
	new_dep_time = 0;
	totalPassengers = 0;
}

bool sdds::Train::validTrainName(const char* name)
{
	return (name != nullptr && name[0] != '\0');
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
	if (validNoOfPassengers(noOfPassengers) && validTime(departure) && validTrainName(name))
	{
		//cleanup
		delete[] train_name;
		train_name = nullptr;
		
		
			train_name = new char[strlen(name) + 1];
			strcpy(train_name, name);
		

		p_aboard = noOfPassengers;
		dep_time = departure;
	}
	else if (validTrainName(name))
	{
		//cleanup
		delete[] train_name;
		train_name = nullptr;


		train_name = new char[strlen(name) + 1];
		strcpy(train_name, name);


		p_aboard = -1;
		dep_time = -1;
	}
	else {
		train_name = nullptr;
		p_aboard = -1;
		dep_time = -1;
	}
}

void sdds::Train::finalize()
{
	delete[] train_name;
	train_name = nullptr;
}

bool sdds::Train::isInvalid() const
{
	// Return true if any of these conditions are met
	return (train_name == nullptr || p_aboard == -1 || dep_time == -1 || (new_dep_time < MIN_TIME || new_dep_time > MAX_TIME));
}

bool sdds::Train::isValid() const
{
	return (train_name != nullptr && p_aboard > 0 && p_aboard <= MAX_NO_OF_PASSENGERS && dep_time >= MIN_TIME && dep_time <= MAX_TIME);
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
		cout << "DEPARTURE TIME:       " << dep_time << "\n";
	}
	else
		cout << "Train in an invalid State!" << endl;
}

bool sdds::Train::load(int& cantBoard)
{
	cout << "Enter number of passengers boarding:" << endl;
	cout << "> ";
	cin >> passengers;

	if (validNoOfPassengers(passengers))
	{
		
		if(passengers>0 && passengers <= MAX_NO_OF_PASSENGERS)
		{
			// aggregate the number of passengers on board to people already aboard
			p_aboard += passengers;
			if (p_aboard > MAX_NO_OF_PASSENGERS)
			{
				
				// Calculate passengers left behind
				cantBoard = p_aboard - MAX_NO_OF_PASSENGERS;
				
				p_aboard = MAX_NO_OF_PASSENGERS;
				//cout << "Train is full, " << cantBoard << " passengers could not be boarded." << endl;
				return false;
			}
			//cout << "Boarding Complete..." << endl;
		}
		return true; // Indicate successful boarding
	}
	return false;
}

bool sdds::Train::load(int passengers, int& cantBoard)
{
	
	if (validNoOfPassengers(passengers) || passengers >MAX_NO_OF_PASSENGERS)
	{
		if (passengers > MAX_NO_OF_PASSENGERS)
		{
			cantBoard = passengers - MAX_NO_OF_PASSENGERS;
			p_aboard = MAX_NO_OF_PASSENGERS;
			return false;
		}
		else
		{
			p_aboard = passengers;
			return true;
		}
	}
	else
	{
		cantBoard = passengers;
		p_aboard = -1;
		return false;
	}
	return false;
}

bool sdds::Train::updateDepartureTime()
{

	
		cout << "Enter new departure time:" << endl;
		cout << "> ";
		cin >> new_dep_time;

		if (validTime(new_dep_time))
		{
			dep_time = new_dep_time;
			new_dep_time = dep_time;
			return true;
		}
		else 
		{
			new_dep_time = -1;
			return false;
		}

	

}

bool sdds::Train::transfer(const Train& from)
{
	// Check if both trains are in a valid state
	if (this->isValid() && from.isValid()) {
		// Combine the names of the two trains
		char* combinedName = new char[strlen(from.train_name) + strlen(from.train_name) + 3]; // +3 for ", " and '\0'
		strcpy(combinedName, train_name);
		strcat(combinedName, ", ");
		strcat(combinedName, from.train_name);

		// Set the combined name as the new name for the current train
		delete[] train_name;
		totalPassengers = this->p_aboard + from.p_aboard;
		train_name = combinedName;

		// Attempt to board passengers from the other train (from)
		int cantBoard = 0;
		if (load(totalPassengers, cantBoard)) {
			/*cout << "Train is full; " << cantBoard << " passengers of " << from.train_name << " could not be boarded!" << endl;*/
			return true; 
		}
		cout << "Train is full; " << cantBoard << " passengers of " << from.train_name << " could not be boarded!" << endl;
		return true; 
	}



	return false; // Indicate success
}



