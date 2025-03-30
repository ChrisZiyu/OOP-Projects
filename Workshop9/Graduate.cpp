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
#include <iostream>
#include <cstring>
#include "Graduate.h"

using namespace std;
namespace sdds {

	Graduate::Graduate(const char* name, int age, const char* thesisTitle, const char* supervisor) :Student(name, age) {
		
		if (thesisTitle && thesisTitle[0] != '\0') {
			delete[] m_thesisTitle;
			m_thesisTitle = new char[strlen(thesisTitle) + 1];
			strcpy(m_thesisTitle, thesisTitle);
		}
		
		if (supervisor  && supervisor[0] != '\0') {
			delete[] m_supervisor;
			m_supervisor = new char[strlen(supervisor) + 1];
			strcpy(m_supervisor, supervisor);
		}
		
	}

	Graduate::Graduate(const Graduate& graduate) :Student(graduate) {
		*this = graduate;
	}

	Graduate& Graduate::operator=(const Graduate& graduate) {//correct no need delete

		if (this != &graduate) {
			Student::operator=(graduate);

			delete[] m_supervisor;
			m_supervisor = new char[strlen(graduate.m_supervisor) + 1];
			strcpy(m_supervisor, graduate.m_supervisor);

			delete[] m_thesisTitle;
			m_thesisTitle = new char[strlen(graduate.m_thesisTitle) + 1];
			strcpy(m_thesisTitle, graduate.m_thesisTitle);
		}
		return *this;
	}

	Graduate::~Graduate() {
		delete[] m_supervisor;
		delete[] m_thesisTitle;
		m_supervisor = m_thesisTitle = nullptr;
	}

	void Graduate::display() {
		Student::display();
		cout << "Thesis Title: " << m_thesisTitle << endl
			<< "Supervisor: " << m_supervisor << endl
			<< "---------------------------------------------" << endl;
	}
}
