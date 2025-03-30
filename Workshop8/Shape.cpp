/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/16/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include"Shape.h"
#include<iostream>
using namespace std;
namespace sdds {
	istream& operator>>(istream& istr,Shape& shape) {
		shape.getSpecs(istr);
		return istr;
	}
	ostream& operator<<(ostream& ostr, Shape& shape)
	{
		shape.draw(ostr);
		return ostr;
	}
}