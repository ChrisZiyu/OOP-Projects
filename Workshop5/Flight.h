/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 10/12/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

    const int Boen747Capacity = 388;//max passengers
    const int FuelTankCapacity = 238840;
    static const double minFuel = 600.0;

    class Flight {

        int m_passengers = 0;// no of passengers
        double m_fuel = 0;//loaded
        char m_title[16];//name of flight
        void emptyPlane();
        //ready to depart >1passenger
        //600fuel for each passenger

    public:
        Flight();
        Flight(int passengers, double fuel, const char* title);
        std::ostream& display()const;

        //type conversion
        //cant modify object
        operator bool() const;//check valid
        operator int() const;//num passengers
        operator double() const;
        operator const char* () const;

        //unary operator
        bool operator ~() const;//cant modify fly object

        //Binary member operators
        //overload assignment operator
        Flight& operator=(Flight& rightOp);//asignment operator
        Flight& operator=(int passengers); //reference to the current object convert Flight into int
        Flight& operator=(double fuel); //reference to the current object
        Flight& operator+=(double addFuel);
        Flight& operator+=(int addPassengers);
        Flight& operator-=(double rest_fuel);
        Flight& operator-=(int restPassengers);
        //overload from right to left
        Flight& operator <<(Flight& RO);
        //left to right
        Flight& operator >>(Flight& RO);
        //add number of passengers of both flights
        int operator+(const Flight& otherFlight);
       
    };
    int operator+=(int& left, const Flight& RO);
}
#endif // SDDS_FLIGHT_H