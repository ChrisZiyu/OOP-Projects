/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/16/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef _GRADUATE_H_
#define _GRADUATE_H_
#include "Student.h"

namespace sdds {
	class Graduate :public Student {
		char* m_thesisTitle{};
		char* m_supervisor{};
	public:
		Graduate() {}
		Graduate(const char* name, int age, const char* thesisTitle, const char* supervisor);
		Graduate(const Graduate& graduate);
		Graduate& operator=(const Graduate& graduate);
		virtual~Graduate();
		void display();
	};
}
#endif // !_GRADUATE_H_
