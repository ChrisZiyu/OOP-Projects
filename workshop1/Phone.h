/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 9/09/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_PHONE_HEADER
#define SDDS_PHONE_HEADER
namespace sdds {
	struct Phones{
		char name[51];
		char areaCode[4];
		char prefix[4];
		char number[5];

	};
	void displayTitle(const char* programTitle);
	void phoneDir(const char* programTitle, const char* fileName);
	void readInput(char* searchByName);
	void getNameRecord(const char* correctInfo, const Phones* records, int recordCount);
	bool exitRecord(const char* searchByName);


}

#endif // !SDDS_PHONE_HEADER

