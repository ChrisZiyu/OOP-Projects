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
#include"iProduct.h"
#include<fstream>
#include <iostream>

namespace sdds {
	const int sdds_max_num_items = 100;
	class AidMan {
		char* fileName;
		Menu mainMenu;
		Date c_date;
		iProduct* Product[sdds_max_num_items];
		int noOfRecs{};

		unsigned int menu() const;
	public:
		AidMan(const char* file=nullptr);
		AidMan(const AidMan& other) = delete;
		AidMan& operator=(const AidMan& other) = delete;
		~AidMan();
		
		iProduct* addProduct(const char* filename);
		void readPerishable(const char* filename);
		void readNonPeri(const char* filename);
		//int setNewPeri(int sku, istream& istr);
		void run();
		void save(const char* filename);
		bool load(const char* filename);
		int list(const char* sub_desc = nullptr) const;
		int search(int sku) const;
		void deallocate();
		
		
		operator bool()const { return fileName && noOfRecs; };
	};

}
#endif // !AIDMAN_H

