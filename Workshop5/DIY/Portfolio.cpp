/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 10/15/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"
#include<cstring>
#include<iomanip>


using namespace std;
namespace sdds {

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio() {
        emptyPortfolio();
    }
    void Portfolio::dispPortfolio() const {
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this);
        cout << " | ";
        cout << " Type: ";
        cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }
    Portfolio::operator  double() const
    {
        return m_value;
    }
    Portfolio::operator const char*() const
    {
        return m_stock;
    }
    Portfolio::operator char() const
    {
        return m_type;
    }
    Portfolio::operator bool() const
    {
        return (m_type == 'G' || m_type == 'V' || m_type == 'I');
        
    }
    bool Portfolio::operator~() const
    {
        return (m_value <0);
    }
    Portfolio& Portfolio::operator+=(double RightOp)
    {
        if (this && RightOp >= 0 && (this->m_type == 'V' || this->m_type == 'I' || this->m_type == 'G')) {
            m_value += RightOp;
        }

        return *this;
    }
    Portfolio& Portfolio::operator-=(double RightOP)
    {
        if (*this && RightOP >= 0) {
            m_value -= RightOP;
        }
        return *this;
    }
    Portfolio& Portfolio::operator<<(Portfolio& RightOP)
    {
        //if (this != &RightOP && *this && RightOP)
        if (this && &RightOP)
        {
            double dollarInvestment = RightOP.m_value + this->m_value;
            m_value = dollarInvestment;
            RightOP.emptyPortfolio();
        }
        return *this;
        
    }
    Portfolio& Portfolio::operator>>(Portfolio& RightOP)
    {
        if (this && &RightOP)
        {
            double dollarInvestment = RightOP.m_value + this->m_value;
            RightOP.m_value = dollarInvestment;
            this->emptyPortfolio();
        }
        return RightOP;
    }

    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }
    double operator+(const Portfolio& left, const Portfolio& right)
    {
        if (left && right)
        {
            return static_cast<double>(left) + static_cast<double>(right);
        }
        return 0.0;
    }

    double& operator+=(double& left, const Portfolio& right)
    {
        left += static_cast<double>(right);
        return left;
    }

}