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
#include "Student.h"
using namespace std;
namespace sdds {

	Student::Student(const char* name, int age) {

		if (name && name[0] != '\0') {
			delete[] m_name;
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_age = age;//porsi
		}
	}

	Student::Student(const Student& student) {
		*this = student;
	}

	Student& Student::operator=(const Student& student) {
		if (this != &student) {
			delete[] m_name;
			m_name = new char[strlen(student.m_name) + 1];
			strcpy(m_name, student.m_name);
			m_age = student.m_age;
		}
		return *this;
	}

	Student::~Student() {
		delete[] m_name;
	}

	void Student::display() {
		cout << "Name: " << m_name << endl
			<< "Age: " << m_age << endl;
	}
}