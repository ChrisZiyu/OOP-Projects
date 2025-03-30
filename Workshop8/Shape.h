/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/16/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SHAPE_H
#define SHAPE_H
#include<iostream>
using namespace std;
namespace sdds {
	class Shape {
	public:
		virtual void draw(ostream& ostr)const = 0;
		virtual void getSpecs(istream& istr) = 0;
		virtual ~Shape() {};
	};
	istream& operator>>(istream& istr,Shape& shape);
	ostream& operator <<(ostream& ostr, Shape& shape);
}
#endif // !SHAPE_H
