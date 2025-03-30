/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/16/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef LBLSHAPE_H
#define LBLSHAPE_H
#include "Shape.h"
#include<iostream>
using namespace std;
namespace sdds {
	class LblShape: public Shape {
		char* m_label;
	protected:
		const char* label()const;
	public:
		void setLabelToNull();
		LblShape();
		LblShape(const char* string);

		LblShape(const LblShape& other) = delete;
		LblShape& operator=(const LblShape& other) = delete;

		void getSpecs(istream& istr) override;

		~LblShape();
	};
}
#endif // !SHAPE_H