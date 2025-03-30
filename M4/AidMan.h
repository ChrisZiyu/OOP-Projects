/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/2/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include"Menu.h"
#include "Date.h"
#include "iProduct.h"
namespace sdds {
		const int max_num_items = 100;
	class AidMan {
		char* fileName;
		Menu mainMenu;
		Date c_date;
		iProduct* Pointers[max_num_items]{};
		int noOfRecords{};

		unsigned int menu() const;
	public:
		AidMan(const char* file);
		AidMan(const AidMan& other) = delete;
		AidMan& operator=(const AidMan& other) = delete;
		~AidMan();

		//void run();
		//bool isEmpty();


		//m5 added fucntions
		//void save()const;
		//delete AidMan();
		//load();

	};

}
#endif // !AIDMAN_H

