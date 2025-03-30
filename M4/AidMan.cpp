/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/13/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "AidMan.h"
#include"Item.h"
#include<iostream>
#include<cstring>
using namespace std;
namespace sdds {

	unsigned int AidMan::menu() const
	{

		cout << "Aid Management System" << endl;
		cout << "Date: " << c_date/*YYYY/MM/DD*/ << endl;

		// Print the data file name or "No file" if it's null
		cout << "Data file: " << ((fileName) ? fileName : "No file") 
			<< "\n\n";

		// Run the main menu and return the selection
		return mainMenu.run();
	}
	AidMan::AidMan(const char* file) :
		fileName(nullptr),
		mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database"),
		c_date(Date())
	{
		if (file)
		{
			fileName = new char[strlen(file) + 1];
			strcpy(fileName, file);
		}
	}
	void AidMan::run() {
		//Modify the run() function so if any menu is selected before opening a database, the selection is changed to 7 automatically.

		//	Insert the following logic after where the main menu selection is returned and before executing the user's selection.

		//	after getting the selection for the menu.
		//	if selection is not zero and the filename is null and the selection is not 7, change the selection to 7.

		unsigned int choice{};
		do {
			switch (choice = menu()) { // Call the Menu's run method to get the user's choice
			case 1:
				std::cout << "\n****List Items****\n\n";break;
			case 2:
				std::cout << "\n****Add Item****\n\n";break;
			case 3:
				std::cout << "\n****Remove Item****\n\n";break;
			case 4:
				std::cout << "\n****Update Quantity****\n\n";break;
			case 5:
				std::cout << "\n****Sort****\n\n";break;
			case 6:
				std::cout << "\n****Ship Items****\n\n";break;
			case 7:
				std::cout << "\n****New/Open Aid Database****\n\n";break;
			case 0:
				std::cout << "Exiting Program!\n";break;
			default:
				std::cout << "Invalid option!\n\n";break;
			}
			if (choice!=0 && isEmpty() && choice != 7)
			{
				choice = 7;
			}
			else if(choice>0 && choice <7 && !isEmpty()){

			}
		} while (choice);
	}

	//bool AidMan::isEmpty()
	{
		return fileName == nullptr;
	}

	//void AidMan::save() const
	{
		if (fileName)
		{
			ofstream streamLine(fileName);
			if (streamLine.is_open())
			{
				for (int i = 0; i < noOfRecords; i++) {
					Pointers[i]->save(streamLine);
				}
			}
			streamLine.close();
		}
	}







	//AidMan::~AidMan()
	{
		delete[] fileName;
		fileName = nullptr;

		for (size_t i = noOfRecords-1 ; i >=0 ; i--)
		{
			delete[] Pointers[i];
			Pointers[i] = nullptr;
		}
	}

}

