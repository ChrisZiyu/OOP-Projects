/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 10/12/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator bool() const
    {
        return(m_passengers > 0 && m_fuel >= (m_passengers * minFuel));
    }

    Flight::operator int() const
    {
        return m_passengers;
    }
    Flight::operator double() const
    {
        return m_fuel;
    }

    Flight::operator const char* () const
    {
        return m_title;
    }

    bool Flight::operator~() const
    {
        return m_passengers == 0;//return true?
    }

    Flight& Flight::operator=( Flight& rightOp)
    {
        if (this != &rightOp) {
            // Copy the values from rightOp to the current object
            m_passengers = rightOp.m_passengers;
            m_fuel = rightOp.m_fuel;
            strcpy(m_title, rightOp.m_title);

            // Set rightOp to its initial state
            rightOp.emptyPlane();
        }
        return *this;

    }

    Flight& Flight::operator=(int passengers)
    {
        if (passengers >= 0 && passengers <= Boen747Capacity) {
            m_passengers = passengers;
        }
        return *this;
    }

    Flight& Flight::operator=(double fuel)
    {
        if (fuel>0.0 && fuel <= FuelTankCapacity)
        {
            m_fuel = fuel;
        }
        return *this;
    }

    Flight& Flight::operator+=(double addFuel)
    {
        if (addFuel>0.0)
        {
            double addedfuel = m_fuel + addFuel;
            if (addedfuel <=FuelTankCapacity)
            {
                m_fuel = addedfuel;
            }
        }
        return *this;
    }

    Flight& Flight::operator+=(int addPassengers)
    {
        if (addPassengers> 0)
        {
            int added_passengers = m_passengers + addPassengers;
            if (added_passengers<=Boen747Capacity)
            {
                m_passengers = added_passengers;
            }
        }
        return *this;
    }

    Flight& Flight::operator-=(double rest_fuel)
    {
        if (rest_fuel>0.0)
        {
            if (m_fuel >=rest_fuel)
            {
                m_fuel -= rest_fuel;
            }
            else {
                m_fuel = 0.0;
                cout << "You got an empty tank!!!" << endl;
            }

        }
        return *this;
    }

    Flight& Flight::operator-=(int restPassengers)
    {
        if (restPassengers > 0)
        {
            if (m_passengers>=restPassengers) {
                m_passengers -= restPassengers;
            }
            else {
                m_passengers = 0;
                cout << "Empty airplane no passengers!!!" << endl;
            }
        }
        return *this;
    }
    Flight& Flight::operator<<(Flight& RO)
    {
        if (this !=&RO)
        {
            int total = m_passengers + RO.m_passengers;
            if (total<=Boen747Capacity)
            {
                m_passengers = total;
                RO.m_passengers = 0;
            }
            else {
                m_passengers = Boen747Capacity;
                RO.m_passengers = total - Boen747Capacity;
            }
        }
        return *this;
    }
    Flight& Flight::operator>>(Flight& RO)
    {
        if (this != &RO)
        {
            int total = m_passengers + RO.m_passengers;
            if (total <= Boen747Capacity)
            {
                
                m_passengers = total;
                RO.m_passengers = 0;
            }
            else {
                RO.m_passengers = Boen747Capacity;
                m_passengers = total - Boen747Capacity;
            }
        }
        return *this;
    }


    int Flight::operator+(const Flight& otherFlight)
    {
        if (*this && otherFlight)
        {
            return m_passengers + otherFlight.m_passengers;
        }
        else
        {
            return 0;
        }
    }







    //Flight& Flight::operator-=(int passengersToDisembark) {
    //    if (passengersToDisembark > 0) {
    //        int potentialPassengers = m_passengers - passengersToDisembark;
    //        if (potentialPassengers >= 0) {
    //            m_passengers = potentialPassengers;
    //        }
    //        else {
    //            m_passengers = 0; // Set the passengers to 0 if trying to disembark more than available
    //        }
    //    }
    //    return *this;
    //}













    int operator+=(int& left, const Flight& RO)
    {
        left += int(RO);
        return left;
    }

}