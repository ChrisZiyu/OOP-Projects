/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/16/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Rectangle.h"
#include<iostream>
#include<limits>
#include<iomanip>
#include<cstring>
sdds::Rectangle::Rectangle():LblShape(),m_width(0),m_height(0){}

sdds::Rectangle::Rectangle(const char* Cstring, int width, int height):LblShape(Cstring),m_width(width),m_height(height){
	if (static_cast<size_t>(m_height) < 3 && static_cast<size_t>(m_width) < strlen(label()) + 2)
	{
		setLabelToNull();
		m_width = 0;
		m_height = 0;
	}
}

void sdds::Rectangle::getSpecs(istream& istr)
{
	LblShape::getSpecs(istr);
	istr.ignore(0,',');
	istr >> m_width;
	istr.ignore(1,',');
	istr >> m_height;

	istr.ignore(numeric_limits<streamsize>::max(), '\n');
}

void sdds::Rectangle::draw(ostream& ostr) const
{
	if (this!=nullptr && m_width>0 &&m_height>0)
	{
		//top
		ostr << '+';
		ostr << setw(m_width -1) << setfill('-') << '+' << setfill(' ') << endl;
		
		//label
		ostr << '|' << setw(m_width - 2) <<left << label();
		
		
		ostr /*<<setw((strlen(label())+1)-(m_width-1))*/<< right << setfill(' ') << '|' << endl;

		//inside
		for (int i = 0; i < m_height - 3; ++i) {
			ostr << '|' << setw(m_width - 1) << right << '|' << endl;
		}

		// bottom
		ostr << '+' << setw(m_width - 1) << setfill('-') << '+' << setfill(' ');
	}
}


