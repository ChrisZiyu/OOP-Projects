/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/16/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef _STUDENT_H_
#define _STUDENT_H_

namespace sdds {
	class Student {
		char* m_name{};
		int m_age{};
	public:
		Student() {}
		Student(const char* name, int age);
		Student(const Student& student);
		Student& operator=(const Student& student);
		virtual~Student();
		void display();
		
	};
}
#endif // !_STUDENT_H_
