/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 9/28/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
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


    bool read(char*& pCode)
    {
        char tempPcode[128];
        int result = fscanf(fptr, "%[^,],", tempPcode);
        if (result == 1) {
            pCode = new char[strlen(tempPcode) + 1];
            strcpy(pCode, tempPcode);
            return true;
        }
        else
            return false;
    }

    bool read(int& pop)
    {
        int result = fscanf(fptr, "%d\n", &pop);
        return (result == 1);
    }

}