/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 9/28/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Population.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace sdds {
    int noOfPcodes;
    Population* pCodes = nullptr;
    bool displayAll = false;
    const char* globalPcode = nullptr;
    

    bool startsWith(const char* cstring, const char* subString) {
        return std::strstr(cstring, subString) == cstring;
    }


    void display()
    {
        int populationSum = 0;
        int displayedCount = 0;
        for (int i = 0; i < noOfPcodes; i++)
        {
            
            if (startsWith(pCodes[i].p_code, globalPcode) || strcmp(globalPcode, "all") == 0)
            {
                displayedCount++;
                cout << displayedCount << "- ";
                cout << pCodes[i].p_code << ":  ";
                cout<< pCodes[i].s_population << "\n";
                populationSum += pCodes[i].s_population;
                
            }
        }       
        cout << "-------------------------\n";

 
        
            if (displayAll)
            {
                cout << "Population of all areas: " << populationSum << "\n\n";
            }
            else
            {
                cout << "Population of the listed areas: " << populationSum << "\n\n";
            }
  
    }


    void deallocateMemory()
    {
        for (int i = noOfPcodes - 1; i >= 0; i--)
        {
            delete[] pCodes[i].p_code;
        }
        delete[] pCodes;
        pCodes = nullptr;
    }




    bool load(const char* filename, char* partial_postal_code_prefix)
    {
        bool ok{};
        if ((ok = openFile(filename)))
        {
            noOfPcodes = noOfRecords();
            if (noOfPcodes > 0)
            {
                pCodes = new Population[noOfPcodes];
                for (int i = 0; i < noOfPcodes; i++)
                {
                    read(pCodes[i].p_code);
                    read(pCodes[i].s_population);
                }
                sort();
            }

            closeFile();
        }
        return ok;
    }

    void sort()
    {
        int i, j;
        Population temp;
        for (i = noOfPcodes - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (pCodes[j].s_population > pCodes[j + 1].s_population) {
                    temp = pCodes[j];
                    pCodes[j] = pCodes[j + 1];
                    pCodes[j + 1] = temp;
                }
            }
        }
    }

    bool getPostalCode(char* postal_code_prefix)
    {

        cout << "Population Report\n";
        cout << "-----------------\n";
        cout << "Enter postal code:\n";
        cout << "> ";
        cin.getline(postal_code_prefix, 4);
        if (strcmp(postal_code_prefix, "!") == 0)
        {
            exit(0); // Return false to signal program exit
        }
        globalPcode = postal_code_prefix;// DONT FORGET!!!!!!!!!!!!!!!!!
        cout << "Postal Code: population\n";
        cout << "-------------------------\n";
        return true; // Continue processing if "!" was not entered
    }





}