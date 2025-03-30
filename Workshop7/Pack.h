/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/09/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef PACK_H
#define PACK_H
#include<iostream>
#include"Container.h"
namespace sdds {

	class Pack : public Container {

		int m_unitSize;//330//capacity
		int m_numOfUnits;//24
		//int remainingSpace=0;
		//int spaceAvailable = 0;
		int unitsAdded = 0;
		/*int m_noOfBottles=0;*/
		//This attribute will be used in combination with the attributes of the Container to calculate the following:
		//Size of the Pack is the capacity of container / unit size
		//Number of units currently in the pack is the content volume of the container / unit size
	public:
		//special
		Pack(const char* description, int size, int unitSize, int numberOfUnits);
		Pack(const char* description,int unitSize);
		//operators +-
		int operator+=(int valuePack);
		int operator-=(int valuePack);
		
		//getters
		int unit() const;
		int getNoUnits() const;
		int getSize() const;
		
		
		//clear
		void clear(int packSize, int unitSize, const char* description);
		//print , read
		std::ostream& printPack(std::ostream& ostr) const;
		std::istream& readPack(std::istream& istr);
	};

	std::ostream& operator<<(std::ostream& ostr, const Pack& pack);
	std::istream& operator>>(std::istream& istr, Pack& pack);
}
#endif // !PACK_H
