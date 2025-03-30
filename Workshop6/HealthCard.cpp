/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 05/11/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "HealthCard.h"
using namespace std;
namespace sdds {
	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
	{									  //131231234
		return (name != nullptr && number > 999999999 && number< 9999999999&&vCode[0]!='\0'
			&&sNumber[0]!='\0' && strlen(vCode) == 2 && strlen(sNumber) == 9);
	}
	void HealthCard::setEmpty()
	{
		m_number = 0;
		m_vCode[0] = '\0';
		m_sNumber[0] = '\0';
	}
	void HealthCard::setEmpty(const char* name,long long number, const char vCode[], const char sNumber[])
	{
		m_number = 0;
		m_vCode[0] = '\0';
		m_sNumber[0] = '\0';
	}
	std::istream& HealthCard::extractChar(std::istream& istr, char ch) const
	{
		// Example
		char next;
		/*int value;*/
		
		/*cout << "Enter a number: ";*/
		next = istr.peek();
		if (next==ch) { // checking if the next character in keyboard is not a digit
			istr.ignore();
			istr.clear();
		}
		else {
			istr.ignore(1000, ch);
		//istr.ignore(1000, '\n'); // flush the invalid value or everything after the number.
			istr.setstate(std::ios::badbit);
		}
		return istr;
	}
	std::ostream& HealthCard::printInfo(std::ostream& ostr,bool toFile) const
	{
		//insert
		//m_number,m_vcode,m_snumber
		if (m_number !=0 && m_vCode[0]!='\0' && m_sNumber[0]!='\0')
		{
		    
			if (toFile==true)
			{
				ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
				
			}
			else
			{
				ostr << m_number << "-" << m_vCode << "," << m_sNumber;
			}
		}
		return ostr;
	}
	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
	{

		if (validID(name,number,vCode,sNumber))
		{
			delete[] m_name;
			m_name = nullptr;

			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_number = number;
			size_t size=0;
			size = strlen(vCode);
			if (size==2)
			{
				strcpy(m_vCode, vCode);
			}
			size = strlen(sNumber);
			if (size==9)
			{
				strcpy(m_sNumber, sNumber);
			}
			else {
				delete m_name;
				m_name = nullptr;
				setEmpty();
			}
		}
	}
	HealthCard::HealthCard()
	{
		setEmpty();
	}
	HealthCard::HealthCard(const char* name,long long number, const char vCode[], const char sNumber[])
	{
		if (validID(name,number,vCode,sNumber))
		{
			set(name, number, vCode, sNumber);

		}
		else
		{
			setEmpty(name,number, vCode, sNumber);

		}
	}
	HealthCard::HealthCard(const HealthCard& hc)
	{
		if (hc.m_name)
		{
			m_name = new char[strlen(hc.m_name) + 1];
			strcpy(m_name, hc.m_name);
			m_number = hc.m_number;
			strcpy(m_vCode, hc.m_vCode);
			strcpy(m_sNumber, hc.m_sNumber);
		}
		else
		{
			setEmpty();
		}
		
	}
	HealthCard::~HealthCard()
	{
		delete[] m_name;
	}
	HealthCard::operator bool() const
	{
		return m_name != nullptr;
	}
	std::ostream& HealthCard::print(std::ostream& ostr, bool toFile) const
	{
		if (m_name!=nullptr)
		{
			if (toFile)
			{
				ostr << m_name << ",";
				printInfo(ostr);
				ostr << endl;
			}
			else {
				ostr << std::left << std::setw(50) << std::setfill('.') << m_name;
				printInfo(ostr);
				ostr << std::setfill(' ');
			}
		}
		return ostr;
	}
	void HealthCard::setValid(bool value)
	{
		isValid = value;
	}
	std::istream& HealthCard::read(istream& str)
	{
		const int bufferSize = MaxNameLength + 1;
		char name[bufferSize] = { 0 };
		long long number=0;
		char vCode[4] = { 0 };
		char sNumber[11] = {0};

		str.get(name, bufferSize, ',');
		if (str.peek()==' ')
		{
			
			/*str.get(name, bufferSize, ' ');*/
			str.ignore();
		}
		extractChar(str, ',');
		str >> number;
		extractChar(str, '-');
		str.get(vCode, 4, ',');
		extractChar(str, ',');
		str.get(sNumber, 11, '\n');

		if (validID(name, number, vCode, sNumber))
		{
			set(name, number, vCode, sNumber);

			setValid(true);
		}
		else {
			setValid(false);
			setEmpty();
			
		}
		str.clear();
		str.ignore(1000, '\n');
		return str;
	}
	bool HealthCard::validCard() const
	{
		return (m_name != nullptr && m_name[0] != '\0' &&
			m_number > 999999999 && m_number < 9999999999 &&
			m_vCode[0] != '\0' && m_sNumber[0] != '\0');
	}
	HealthCard& HealthCard::operator=(const HealthCard& hc)
	{
		if (this!=&hc)
		{
			delete[] m_name;
			m_name = nullptr;
			if (hc.m_name)
			{
				m_name = new char[strlen(hc.m_name) + 1];
				strcpy(m_name, hc.m_name);
				m_number = hc.m_number;
				strcpy(m_vCode, hc.m_vCode);
				strcpy(m_sNumber, hc.m_sNumber);
			}

		}
		else{
			setEmpty();
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc)
	{
		
		if (hc.validCard())
		{
			hc.print(ostr, false);
		}
		else
		{
			ostr << "Invalid Health Card Record";
		}
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, HealthCard& hc)
	{
		return hc.read(istr);
	}

}