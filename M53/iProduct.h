/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/16/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_I_PRODUCTS_H
#define SDDS_I_PRODUCTS_H
#include <iostream>
#include <fstream>
namespace sdds {
	class iProduct {
	public:
		// to read the Stock-Keeping Unit from the console before
		// main data entry
		virtual int readSku(std::istream& istr) = 0;
		// to reduce the quantity on hand
		virtual int operator-=(int qty) = 0;
		// to increase the quantity on hand
		virtual int operator+=(int qty) = 0;
		// returns the price of the produce
		virtual operator double()const = 0;
		// returns if the iProduct is in a good state
		virtual operator bool()const = 0;
		// returns the number of products needed
		virtual int qtyNeeded()const = 0;
		// returns the quantity on hand
		virtual int qty()const = 0;
		//return item desc
		virtual char* getItemDesc() const = 0;
		// determines if the iProduct is displayed in a linear format or 
		// descriptive format
		virtual void linear(bool isLinear) = 0;
		// saves the iProduct into a file
		virtual std::ofstream& save(std::ofstream& ofstr)const = 0;
		// loads an iProduct from a file
		virtual std::ifstream& load(std::ifstream& ifstr) = 0;
		// displays the iProduct on the screen
		virtual std::ostream& display(std::ostream& ostr)const = 0;
		// reads the iProduct from the console
		virtual std::istream& read(std::istream& istr) = 0;
		// return true if the SKU is a match to the iProduct's SKU
		virtual bool operator==(int sku)const = 0;
		// returns true if the description is found in the iPorduct's description
		virtual bool operator==(const char* description)const = 0;

		virtual ~iProduct() {};//special functions are not pure functions!!!!!!!!!!!!!!
	};
	std::istream& operator>>(std::istream& istr, iProduct& p);
	std::ostream& operator<<(std::ostream& ostr, iProduct& p);


}
#endif // !I_PRODUCTS_H
