/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  Employee.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name :Christian Ziyu Ukiike           Date  9/21/2023          Reason
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include <iostream>
#include <iomanip>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees= nullptr;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee &emp) {
        bool ok = false;
        // return the combined success result of the three read functions. These read 
        // functions should set the properties of the reference argument of the load function
        emp.m_name = nullptr;
        if (read(emp.m_empNo)&& read (emp.m_salary) && read(emp.m_name))
        {
            ok = true;
        }
        return ok;
    }
    // TODO: Finish the implementation of the 0 arg load function 
    bool load() {
        bool ok = false;

        if (openFile(DATAFILE)) {
            noOfEmployees = noOfRecords();
            if (noOfEmployees > 0) {
                employees = new Employee[noOfEmployees];
                for (int i = 0; i < noOfEmployees; i++) {
                    if (!load(employees[i])) {
                        ok = false; // Set to false if loading any employee fails
                        break;      // Exit the loop
                    }
                }
                ok = true; // Set to true if all employees are loaded successfully
            }
            closeFile(); // Close the file after reading
        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }

        return ok;
    }
    // TODO: Implementation for the display functions go here
    void display()
    {
        sort();
        cout << "Employee Salary report, sorted by employee number\n";
        cout << "no- Empno, Name, Salary\n";
        cout << "------------------------------------------------" << endl;

        //iteration for displaying the employee objects with respective attributes
        for (int i = 0; i < noOfEmployees; i++)
        {
            cout << i + 1 << "- " << employees[i].m_empNo << ": ";
            cout << employees[i].m_name << ", ";
            cout << fixed << setprecision(0) << "$" << employees[i].m_salary << endl;

            /*cout<< "$" << static_cast<int>(employees[i].m_salary) << endl*/;
            /*sdds::display(employees[i],std::cout);*/
            //call the overload function with the parameters
        }
    }


    void display(const Employee& emp, std::ostream& str)
    {
        str << emp.m_empNo << ": " << emp.m_name << ", $" << emp.m_salary << endl;
    }
    // TODO: Implementation for the deallocateMemory function goes here  
    void deallocateMemory()
    {
        for (int i = 0; i < noOfEmployees; i++)
        {
            delete[] employees[i].m_name;
        }
        delete[] employees;

        noOfEmployees = 0;
        employees = nullptr;
    }






    



}