/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/16/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include<cstring>

const char* sdds::LblShape::label() const
{
	return m_label;
}

void sdds::LblShape::setLabelToNull()
{
	delete[] m_label;
	m_label = nullptr;
}

sdds::LblShape::LblShape():m_label(nullptr){}

void sdds::LblShape::getSpecs(istream& istr)
{
	delete[] m_label;
	m_label = nullptr;
	if (istr)
	{
		char temp[100];
		istr.getline(temp, 1000, ',');
		m_label = new char[strlen(temp) + 1];

		//safer"O_O
		strncpy(m_label, temp, strlen(temp) + 1);
	}
	
}

sdds::LblShape::LblShape(const char* string):m_label(nullptr)
{
	if (string)
	{
		m_label = new char[strlen(string) + 1];
		strcpy(m_label, string);
	}
}
sdds::LblShape::~LblShape() {
	delete[] m_label;
	m_label = nullptr;
}


