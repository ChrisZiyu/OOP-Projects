/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 05/11/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H
#include<iostream>
#include<cstring>
#include<iomanip>
namespace sdds {
    const int MaxNameLength = 55;
    class HealthCard {
        char* m_name{}; //fullname Cstring not null and not empty
        long long m_number;//card numbernumber consists of 10 digits (>999999999 and <9999999999)
        char m_vCode[3];//version code of the card 2 characters
        char m_sNumber[10];//stock control number 9 characters
        bool isValid;

        bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;
        void setEmpty();
        void setEmpty(const char* name,long long number, const char vCode[], const char sNumber[]);
        std::istream& extractChar(std::istream& istr, char ch) const;
        std::ostream& printInfo(std::ostream& ostr,bool toFile=true) const;
        void set(const char* name, long long number, const char vCode[], const char sNumber[]);

    public:
        HealthCard();
        HealthCard(const char* name,long long number, const char vCode[], const char sNumber[]);
        //Rule of three
        HealthCard(const HealthCard& hc);//copy constructor
        HealthCard& operator=(const HealthCard& hc);//copy assignment operator
        ~HealthCard();
        void setValid(bool value);//values received are valid or not
        operator bool() const;//healthcard object is valid = true
        std::ostream& print(std::ostream& ostr, bool toFile = true) const;
        std::istream& read(std::istream& str);
        
        bool validCard()const;//check the object if hold good data
    };
    std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc);
    std::istream& operator>>(std::istream& istr, HealthCard& hc);
}
#endif // !SDDS_HealthCard_H

