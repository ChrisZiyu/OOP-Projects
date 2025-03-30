/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name :Christian Ziyu Ukiike           Date  9/21/2023          Reason
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<cstring>
#include "File.h"
#include "Employee.h"

namespace sdds {
    FILE* fptr;//global
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
     //TODO: read functions go here
    bool read(char* &name) {

        char tempName[128];// local
        
        int result = fscanf(fptr, "%127[^\n]\n", tempName);

        if (result == true)
        {
            name = new char[strlen(tempName) + 1];
            strcpy(name, tempName);
            return true;
        }
        else
            return false;
    }
    bool read(int& empNum) {

        int result = fscanf(fptr, "%d,",&empNum);

        if (result == true)
        {
            return true;
        }
        else
            return false;
    }
    bool read(double& salary) {
        int result = fscanf(fptr, "%lf,", &salary);

        if (result == true)
        {
            return true;
        }
        else
            return false;
    }
    
}