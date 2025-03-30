/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/16/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Line.h"
#include <limits>
#include<iostream>
using namespace std;
sdds::Line::Line():LblShape(), m_lenght(0) {}

sdds::Line::Line(const char* Cstring, int lenght):LblShape(Cstring),m_lenght(lenght){}

void sdds::Line::getSpecs(istream& istr)
{
	LblShape::getSpecs(istr);
	istr >> m_lenght;
	istr.ignore(numeric_limits<streamsize>::max(), '\n');
}

void sdds::Line::draw(ostream& ostr) const
{
	if (m_lenght>0 &&label()!=nullptr)
	{
		ostr << label()<<endl;
		for (int i = 0; i < m_lenght; i++)
		{
			ostr << '=';
		}
		
	}
}

