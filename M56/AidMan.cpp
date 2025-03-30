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
#include<iomanip>
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
						choice = 0;
					}
					else {
						readNonPeri(filename);
						choice = 0;
					}
				}
				cout << endl;
			}
		} while (choice != 0);
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
			if (/*executeCase7 &&*/ (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6) && (fileName == nullptr)) {
				choice = 7; // Set choice to 7 if conditions are met
			}
			switch (choice) { // Call the Menu's run method to get the user's choice
			case 1:
				std::cout << "\n****List Items****\n"; list(); rowSelected(noOfRecs); break;
			case 2:
				std::cout << "\n****Add Item****\n"; addProduct("data.dat"); break;
			case 3:
				std::cout << "\n****Remove Item****\n"; removeInput(); break;
			case 4:
				std::cout << "\n****Update Quantity****\n"; break;
			case 5:
				std::cout << "\n****Sort****\n"; sort(); break;
			case 6:
				std::cout << "\n****Ship Items****\n"; shipItems(); break;
			case 7:
				std::cout << "\n****New/Open Aid Database****\n";
				load("data.dat");
				break;
			case 0:
				std::cout << "Exiting Program!\n"; break;
			default:
				std::cout << "Invalid option!\n\n"; break;
			}

		} while (choice != 0);
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
			cout << "Failed to open" << filename << "for reading!" << endl;
			cout << "Would you like to create a new data file?" << endl;
			cout << "1- Yes!" << endl;
			cout << "0- Exit" << endl;
			int choice = 0;
			cin >> choice;
			if (choice == 1)
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
		return (noOfRecs > 0);
	}


	int AidMan::list(const char* sub_desc) const//Works!
	{
		int rowNum = 0;
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
			else if (sub_desc) {

				cout << "   " << i + 1 << " | ";
				Product[i]->display(cout);
				rowNum++;
				cout << endl;
			}
		}
		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

		return rowNum;
	}

	int AidMan::rowSelected(const int number) const
	{

		bool validInput = true;
		do {
			cout << "Enter row number to display details or <ENTER> to continue:" << endl;
			cout << "> ";
			cin.ignore();
			if (cin.peek() == '\n') {

				cout << "\n";
				break;
			}
			int number = ut.getint(1, noOfRecs);
			if (number >= 1 && number <= noOfRecs) {
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


		return number;
	}

	int AidMan::search(int sku) const
	{
		for (int i = 0; i < noOfRecs; i++)
		{
			if (*Product[i] == sku)
			{
				return i;
			}
		}
		return -1;
	}

	void AidMan::sort()
	{
		int difqty[sdds_max_num_items]{};
		int temp{};
		iProduct* tempProduct{};
		for (int i = 0; i < noOfRecs; i++)
		{

			difqty[i] = Product[i]->qtyNeeded() - Product[i]->qty();
		}
		for (int i = 0; i < noOfRecs; i++)
		{
			for (int j = 0; j < noOfRecs - 1; j++) {
				if (difqty[j] < difqty[j + 1])
				{
					temp = difqty[j];
					difqty[j] = difqty[j + 1];
					difqty[j + 1] = temp;

					tempProduct = Product[j];
					Product[j] = Product[j + 1];
					Product[j + 1] = tempProduct;
				}
			}
		}
		cout << "Sort completed!\n" << endl;
		save(fileName);
	}

	void AidMan::shipItems()
	{
		ofstream fout("shippingOrder.txt");
		int match{};
		
		fout << "Shipping Order, Date: " << c_date << endl;
		fout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry\n";
		fout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
		for (int i = 0; i < noOfRecs; i++)
		{
			if (Product[i]->qtyNeeded()==Product[i]->qty()) {
				fout<<setw(4) <<setfill(' ') <<right<< (match+1) << " | ";
				Product[i]->linear(true);
				Product[i]->display(fout);
				fout << endl;
				remove(i);
				match++;
				
			}

		}
		fout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
		save("shippingOrder.txt");
		fout.close();
		cout << "Shipping Order for " << match << " times saved!\n" << endl;
	}

	void AidMan::removeInput()
	{
		char searchDesc[sdds_max_num_items]{};
		cout << "Item description: ";
		cin.ignore();
		cin.getline(searchDesc, sizeof(searchDesc), '\n');

		// Find and display matching items
		int match = 0;
		cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
		for (int i = 0; i < noOfRecs; i++) {
			if (strstr(Product[i]->getItemDesc(), searchDesc) != nullptr) {
				/*list(searchDesc);*/
				cout << "   " << i + 1 << " | ";
				Product[i]->linear(true);
				Product[i]->display(cout);
				cout << endl;
				match++;
			}
		}
		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

		// Check if there are matching items
		if (match == 0) {
			cout << "No matching items found." << endl;
			return;
		}
		// Get user input for SKU
		int sku;
		cout << "Enter SKU: ";
		cin >> sku;

		// Check if the entered SKU is valid
		int index = search(sku);
		if (index != -1) {
			cout << "Following item will be removed: " << endl;
			Product[index]->linear(false);
			Product[index]->display(cout);
			cout << endl;

			cout << "Are you sure?" << endl;
			cout << "1- Yes!" << endl;
			cout << "0- Exit" << endl;
			int chosen = ut.getint(0, 1, "> ");

			if (chosen == 1) {
				cout << "Item removed!\n" << endl;
				remove(index);
			}
		}
		else {
			cout << "Item not found!" << endl;
		}
		save(fileName);
	}


	void AidMan::remove(int index)
	{
		
			delete Product[index];

			// Compact the array
			for (int i = index; i < noOfRecs - 1; i++) {
				Product[i] = Product[i + 1];
			}
			noOfRecs--;
	}


	//void AidMan::remove(int index)
	//{
	//	if (index>0)
	//	{
	//		char searchDesc[sdds_max_num_items]{};
	//		cout << "Item description: ";
	//		cin.ignore();
	//		cin.getline(searchDesc, sizeof(searchDesc), '\n');
	//		for (int i = 0; i < noOfRecs; i++)
	//		{
	//			if (i!=index && strstr(Product[i]->getItemDesc(), searchDesc) != nullptr) {
	//				list(searchDesc);
	//				int sku = Product[noOfRecs]->readSku(cin);

	//			
	//				if (*this)
	//				{
	//					if (search(sku) != -1)
	//					{
	//						cout << "Following item will be removed: " << endl;
	//						Product[sku]->linear(false);
	//						Product[sku]->display(cout);
	//						cout << endl;
	//						cout << "Are you sure?" << endl;
	//						cout << "1- Yes!" << endl;
	//						cout << "0- Exit" << endl;
	//					    int chosen= ut.getint(0, 1, "> ");
	//						if (chosen == 1)
	//						{
	//							cout << "Item removed!" << endl;
	//							delete Product[i];
	//							// Assuming removal means the array needs to be compacted
	//							for (int j = i; j < noOfRecs - 1; j++)
	//							{
	//								Product[j] = Product[j + 1];
	//							}
	//							noOfRecs--;
	//							break;

	//						}
	//					}else {cout << "Aborted!\n";}
	//				}else {cout << "SKU not found!" << endl;}
	//			}
	//		}
	//	}
	//}

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

