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
#include "Perishable.h"
#include"Item.h"
#include<iostream>
#include<cstring>
#include<fstream>
#include<limits>
using namespace std;
namespace sdds {

	unsigned int AidMan::menu() const
	{

		
			cout << "Aid Management System" << endl;
			cout << "Date: " << c_date/*YYYY/MM/DD*/ << endl;

			// Print the data file name or "No file" if it's null
			cout << "Data file: " << ((fileName) ? fileName : "No file")
				<< "\n"
				<< "---------------------------------" << endl;
		

		// Run the main menu and return the selection
		return mainMenu.run();
	}
	AidMan::AidMan(const char* file) :
		fileName(nullptr),
		mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database"),
		c_date(Date()), Product{}
	{}



	//int AidMan::setNewPeri(int sku,istream& istr)
	//{
	//	if (sku ==1 || sku ==2)
	//	{
	//		if (sku==1) {
	//			readPerishable(istr);
	//		}
	//	}
	//}

	iProduct* AidMan::addProduct(const char* filename)
	{

		
		unsigned int choice{};
		do
		{
			if (noOfRecs > sdds_max_num_items)
			{
				cout << "Database full!" << endl;
			}
			else {
				cout << "1- Perishable\n"
					<< "2- Non-Perishable\n"
					<< "-----------------\n"
					<< "0- Exit\n"
					<< "> ";
				while (!(cin >> choice))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Please enter a number.\n> ";
				}
				if (choice == 0)
				{
					cout << "Aborted\n";
					
				}
				else if (choice == 1 || choice == 2)
				{
					if (choice == 1)
					{
						
						readPerishable(filename);
						choice=0;
					}
					else {
						readNonPeri(filename);
						choice = 0;
					}
				}
				cout << endl;
			}
		} while (choice!=0);
		save(filename);
		return Product[noOfRecs];
	}

	void AidMan::readPerishable(const char* filename) 
	{


		if (noOfRecs <= sdds_max_num_items)
		{

			Product[noOfRecs] = new Perishable;
			int sku = Product[noOfRecs]->readSku(cin);

			//Item* item = dynamic_cast<Item*>(Product[noOfRecs]);
			if (*this)
			{


				if (search(sku) != -1)
				{
					cout << "Sku: " << sku << " is already in the system, try updating quantity instead." << endl;
					delete Product[noOfRecs];
				}
				else {

					Product[noOfRecs]->read(cin);

					if (*Product[noOfRecs])
					{
						noOfRecs++;

					}
					else {
						cout << "Error";
						delete Product[noOfRecs];
					}
				}
			}

		}
		else {
			cout << "Database full!" << endl;
		}
	}

	void AidMan::readNonPeri(const char* filename) 
	{

		
		if (noOfRecs <= sdds_max_num_items)
		{
			
			Product[noOfRecs] = new Item;
			int sku = Product[noOfRecs]->readSku(cin);
	
			//Item* item = dynamic_cast<Item*>(Product[noOfRecs]);
			if (*this)
			{
				
				
				if (search(sku) != -1)
				{
					cout << "Sku: " << sku << " is already in the system, try updating quantity instead." << endl;
					delete Product[noOfRecs];
				}
				else {

					Product[noOfRecs]->read(cin);

					if (*Product[noOfRecs])
					{
						noOfRecs++;

					}
					else {
						cout << "Error";
						delete Product[noOfRecs];
					}
				}
			}

		}
		else {
			cout << "Database full!" << endl;
		}
	}

	void AidMan::run() {
		unsigned int choice{};
		
		

		do {
			choice = menu();
			// Check the conditions for executing case 7
			if (/*executeCase7 &&*/ (choice == 1 || choice == 2|| choice==3 || choice==4 || choice==5 || choice==6)&&(fileName==nullptr)) {
				choice = 7; // Set choice to 7 if conditions are met
			}
			switch (choice) { // Call the Menu's run method to get the user's choice
			case 1:

					std::cout << "\n****List Items****\n";
					list();
					break;
				
					
			case 2:
					/*if (noOfRecs>6 && noOfRecs<=sdds_max_num_items)
					{*/
						std::cout << "\n****Add Item****\n";

					//}
					addProduct("data.dat");
					break;
			case 3:
					std::cout << "\n****Remove Item****\n";break;
			case 4:
					std::cout << "\n****Update Quantity****\n";break;
			case 5:
					std::cout << "\n****Sort****\n";break;
			case 6:
					std::cout << "\n****Ship Items****\n";break;
			case 7:
					std::cout << "\n****New/Open Aid Database****\n";
					load("data.dat");
					break;
			case 0:
					std::cout << "Exiting Program!\n";break;
			default:
					std::cout << "Invalid option!\n\n";break;
			}

		} while (choice!=0);
	}
	void AidMan::save(const char* filename)
	{
		if (fileName)
		{
			// Create an output file stream 
			ofstream outfile(fileName);

			
			if (outfile.is_open())
			{
				for (int i = 0; i < noOfRecs; i++)
				{
					//save to file
					Product[i]->save(outfile);
					outfile << '\n';
				}
				

				// Close the output file stream after writing
				outfile.close();
				/*cout << "Data saved to " << fileName << " successfully." << endl;*/
			}
			else
			{
				cout << "Failed to open " << fileName << " for writing!" << endl;
			}
		}
	}

	bool AidMan::load(const char* filename)
	{
		if (fileName)
		{
			delete[] fileName;
			fileName = nullptr;
		}
		if (filename != nullptr && filename[0] != '\0') {
			fileName = new char[strlen(filename) + 1];
			strcpy(fileName, filename);
		}
		ifstream ifstr(fileName);
		// Check if the input file stream is open
		if (!ifstr.is_open())
		{
			cout << "Failed to open"<<filename<< "for reading!" << endl;
			cout << "Would you like to create a new data file?" << endl;
			cout << "1- Yes!" << endl;
			cout << "0- Exit" << endl;
			int choice = 0;
			cin >> choice;
			if (choice==1)
			{
				ofstream outfile(fileName);
				if (!outfile.is_open())
				{
					cout << "Failed to create new data file!" << endl;
					return false;
				}
				outfile.close();
			}
			return false;
		}

		// Assuming noOfRecs is a member variable of AidMan class
		noOfRecs = 0;

		// Loop to read data from the input file stream
		while (!ifstr.eof() && noOfRecs < sdds_max_num_items)
		{
			// Check the condition for perishable products
			if (ifstr.peek() >= '1' && ifstr.peek() <= '3')
			{
				// Create perishable product
				Product[noOfRecs] = new Perishable;
			}
			// Check the condition for non-perishable products
			else if (ifstr.peek() >= '4' && ifstr.peek() <= '9')
			{
				// Create non-perishable product
				Product[noOfRecs] = new Item;
			}
			else
			{
				// Clear and ignore the rest of the line if the condition is not met
				ifstr.clear();
				ifstr.ignore(1000, '\n');
				continue;  
			}

			// Load data for the created product
			Product[noOfRecs]->load(ifstr);

			// Check if the product was loaded successfully
			if (*Product[noOfRecs])
			{
				noOfRecs++;
			}
		}
		if (*this)
		{
			cout << "Enter file name: " << fileName << endl;
			cout << noOfRecs << " records loaded!\n" << endl;
			
		}
		save(filename);
		//deallocate();
		return (noOfRecs > 0);
	}


	int AidMan::list(const char* sub_desc) const//Works!
	{
		int rowNum = 0;
		int number = 0;
		bool validInput = true;
		cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
		for (int i = 0; i < noOfRecs; i++)
		{

			if (sub_desc == nullptr)
			{
				Product[i]->linear(true);
				cout << "   " << i + 1 << " | ";
				Product[i]->display(cout);
				rowNum++;
				cout << endl;
			}
			else if (sub_desc){
				
				cout << "   " << i + 1 << " | ";
				Product[i]->display(cout);
				rowNum++;
				cout << endl;
			}
		}
		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

		do {
			cout << "Enter row number to display details or <ENTER> to continue:" << endl;
			cout << "> ";
			cin.ignore();
			if (cin.peek() == '\n') {
			
				cout << "\n";
				break;
			}
			cin >> number;
			if (number >= 1 && number <= rowNum) {
				Product[number - 1]->linear(false);
				Product[number - 1]->display(cout);
				cout << '\n' << '\n';
				/*validInput;*/

			}
			else {
				cout << "Invalid input. Please enter a valid row number." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			cin.get(); // Consume the newline character

		} while (!validInput);

		
		return rowNum;

	}

	int AidMan::search(int sku) const
	{
		for (int i = 0; i < noOfRecs; i++)
		{
			if (*Product[i]==sku)
			{
				return i;
			}
		}
		return -1;
	}

	void AidMan::deallocate()
	{
		for (size_t i = noOfRecs; i > 0;)
		{
			--i;
			delete Product[i];
			Product[i] = nullptr;
		}
		noOfRecs = 0;
	}
	AidMan::~AidMan()
	{
		delete[] fileName;
		fileName = nullptr;
		deallocate();

	}



}

