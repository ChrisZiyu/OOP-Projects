/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/2/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Utils.h"
using namespace std;
namespace sdds {
    // The ut object of type Utils that is accessible to any file including "Utils.h" to call the Utils
    // methods
    Utils ut;

    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    //void Utils::alocpy(char*& destination, char* source)
    //{
    //    delete[] destination;
    //    destination = nullptr;
    //    if (source!=nullptr)
    //    {
    //        destination = new char[strlen(source) + 1];
    //        if (destination)
    //        {
    //            strcpy(destination, source);
    //        }
    //        else {
    //            cout << "Utils.cpp source was invalid" << endl;
    //        }
    //    }

    //}
    //int Utils::getInt(const char* prompt)
    //{
    //    int value;
    //    bool validInput = false;
    //    while (!validInput)
    //    {
    //        if (prompt!=nullptr)
    //        {
    //            cout << prompt << endl;
    //        }
    //        if (!(std::cin >> value)) {
    //            cin.clear();
    //            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //            std::cout << "Invalid Integer, retry: " << endl;

    //        }
    //        else {
    //            validInput = true;
    //        }
    //    }
    //    return value;
    //}
    //int Utils::getint(int min, int max, const char* prompt, const char* errMes)
    //{
    //    int value;
    //    bool validInput = false;
    //    while (!validInput)
    //    {
    //        if (prompt != nullptr)
    //        {
    //            cout << prompt << endl;
    //        }
    //        if (!(std::cin >> value)) {
    //            if (value>=min && value <=max)
    //            {
    //                validInput = true;
  
    //            }
    //            else {
    //                cin.clear();
    //                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //                if (errMes != nullptr)
    //                {
    //                    cout << errMes << ", retry: " << endl;
    //                }
    //                else {
    //                    cout << "Value out of range [" << min << "<=val<=" << max << ": " << endl;
    //                }
    //            }

    //        }
    //        else {
    //            std::cin.clear(); // Clear error flags
    //            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
    //            std::cout << "Invalid Integer, retry: ";
    //        }
    //    }
    //    return value;
    //}
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
}