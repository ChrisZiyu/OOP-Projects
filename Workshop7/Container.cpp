/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/09/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Container.h"
#include <cstring>

namespace sdds {
	Container::Container(const char* content, int capacity, int volume=0) {

		if (content && volume <= capacity)
		{
			strncpy(m_content, content, DESCRIPTION);
			m_content[DESCRIPTION-1] = '\0';
			m_capacity = capacity;
			m_contentV = volume;
		}
		else {
			setEmpty();
		}
	}
	void Container::setEmpty()
	{
		m_content[0] = '\0';
		m_capacity = 0;
		m_contentV = 0;
	}
	void Container::setVolume(int newVolume)
	{
		if (newVolume >= 0 && newVolume <= m_capacity) {
			m_contentV = newVolume;
		}
	}
	int Container::getCapacity() const
	{
		return m_capacity;
	}
	int Container::getVolume() const
	{
		return m_contentV;
	}
	bool Container::isValid()
	{
		return(m_content[0] != '\0' && m_contentV <= m_capacity);
	}
	bool Container::isValid(const char* content, const int capacity, const int volume)
	{
		return(m_content[0] != '\0' && m_contentV <= m_capacity);
	}
	int Container::operator+=(int value)
	{
		if (value <= (m_capacity - m_contentV)) {
			m_contentV += value;
			return value;
		}
		else {
			int added = m_capacity - m_contentV;
			m_contentV = m_capacity;
			return added;
		}
	}
	int Container::operator-=(int value)
	{
		if (value <= m_contentV) {
			m_contentV -= value;
			return value;
		}
		else {
			int reduced = m_contentV;
			m_contentV = 0;
			return reduced;
		}
	}
	Container::operator bool() const
	{
		return(m_content[0] != '\0' && m_contentV <= m_capacity);
	}
	void Container::clear(int capacity, const char* content)
	{
		if (capacity >0 && content[0]!='\0')
		{
			m_capacity = capacity;
			strncpy(m_content, content,DESCRIPTION);
			m_content[DESCRIPTION] = '\0';
			m_contentV = 0;
		}
		else {
			setEmpty();
		}
	}
	void Container::clear(int capacity, int volume, const char* content)
	{
		if (capacity > 0 && content[0] != '\0')
		{
			m_capacity = capacity*volume;
			strncpy(m_content, content, DESCRIPTION-1);
			m_content[DESCRIPTION-1] = '\0';
			m_contentV = 0;
		}
		else {
			setEmpty();
		}
	}
	std::ostream& Container::print(std::ostream& ostr) const
	{
		if (*this)
		{
			ostr<< m_content << ": (" << m_contentV << "cc/" << m_capacity << ")";
		}
		else {
			ostr << "****: (**cc/***)";
		}
		return ostr;
	}
	std::istream& Container::read(std::istream& istr)
	{
		if (!*this)
		{
			std::cout << "Broken Container, adding aborted! Press <ENTER> to continue...."<<std::endl;
			while (istr.get() != '\n') {}
		}
		else {
			std::cout<< "Add to "<<m_content << ": (" << m_contentV << "cc/" << m_capacity << ")";
			std::cout << std::endl << "> ";
			int amount;
			istr >> amount;
			if (!istr) {
				std::cout << "Invalid Integer, retry: ";
				while (istr.get() != '\n') {}
			}
			else if (amount < 1 || amount > 999) {
				std::cout << "Value out of range [1<=val<=999]: ";
				while (istr.get() != '\n') {}
			}
			else {
				int added = *this += amount;
				std::cout << "Added " << added << " CCs\n";
			}
		}
		return istr;
	}
	Container::Container(const char* content, int capacity):Container(content,capacity,0) {

	}

	std::ostream& operator<<(std::ostream& ostr, const Container& container)
	{
		container.print(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Container& container)
	{
		container.read(istr);
		return istr;
	}

}