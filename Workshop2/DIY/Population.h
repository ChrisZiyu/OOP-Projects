/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 9/28/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#include "File.h"
namespace sdds {
	
	struct Population {
		char* p_code;
		int s_population;
		

	};
	// returns true of the cstring starts with subString
	bool load(const char* filename, char* partial_postal_code_prefix);
	void sort();
	bool getPostalCode(char* postal_code_prefix);
	bool startsWith(const char* cString, const char* subString);
	void display();
	void deallocateMemory();



}
#endif // SDDS_POPULATION_H_