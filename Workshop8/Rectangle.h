/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/16/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "LblShape.h"
#include<iostream>
using namespace std;
namespace sdds {
	class Rectangle : public LblShape {
		int m_width;
		int m_height;
	public:
		Rectangle();
		Rectangle(const char* Cstring, int height,int width);
		void getSpecs(istream& istr)override;
		void draw(ostream& ostr)const override;




	};
}
#endif // !SHAPE_H