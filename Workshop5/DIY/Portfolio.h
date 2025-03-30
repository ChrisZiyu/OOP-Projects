/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name   Christian Ziyu Ukiike              Date  10/15/2023          Reason I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>

namespace sdds {

    class Portfolio {
        double m_value = 0;
        char m_stock[16];
        char m_type;

    public:
        Portfolio();
        Portfolio(double value, const char* stock, char type);
        void emptyPortfolio();
        void dispPortfolio() const;
        std::ostream& display() const;
        //conversion overloads
        operator  double() const;
        operator const char*() const;
        operator char() const;
        operator bool() const;
        bool operator~() const;
        //binary
        Portfolio& operator+=(double RightOP);
        Portfolio& operator-=(double RightOP);
        Portfolio& operator<<(Portfolio& RightOP);
        Portfolio& operator>>(Portfolio& RightOP);
    };
    //helper
    double operator+(const Portfolio& left, const Portfolio& right);
    double& operator+=(double& left, const Portfolio& right);
}
#endif // SDDS_Portfolio_H_