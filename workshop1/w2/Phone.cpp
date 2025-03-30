#define _CRT_SECURE_NO_WARNINGS
#include "Phone.h"
#include"cStrTools.h"
#include<iostream>
#include<cstring>
const int MAX_RECORDS = 36;
using namespace std;

namespace sdds {
	Phones records[MAX_RECORDS] = {};
	bool found = false;

	void readInput(char* searchByName)
	{
		cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
		cout << "> ";
		cin.getline(searchByName,51);
		//if (strcmp(searchByName, "!") == 0) {
		//	cout << "Thank you for using Star Wars directory.\n"
		//		 << "-------------------------------------------------------" << endl;
		//	
		//}
	}
	void getNameRecord(const char* correctInfo, const Phones* records, int recordCount) {
		
		for (int i = 0; i < recordCount; i++) {
			// Create a temporary string for the lowercase version of 'records[i].name'
			char nameLowerCase[51];
			strcpy(nameLowerCase, records[i].name);
			for (int j = 0; nameLowerCase[j]; j++) {
				nameLowerCase[j] = toLower(nameLowerCase[j]);
			}

			// Create a temporary string for the lowercase version of 'correctInfo'
			char correctInfoLowerCase[51];
			strcpy(correctInfoLowerCase, correctInfo);
			for (int i = 0; correctInfoLowerCase[i]; i++) {
				correctInfoLowerCase[i] = toLower(correctInfoLowerCase[i]);
			}

			// Use 'strstr' to find 'correctInfoLowerCase' in 'nameLowerCase'
			const char* match = strstr(nameLowerCase, correctInfoLowerCase);

			if (match != nullptr) {
				cout << records[i].name << ": " << "(" << records[i].areaCode << ") " << records[i].prefix << "-" << records[i].number << endl;
				found = true;
			}
		}
	}
	bool exitRecord(const char* searchByName)
	{
		if (strcmp(searchByName, "!") == 0) {
			cout << "Thank you for using Star Wars directory." << endl;
			return true;
		}
		return false;
	}
	void displayTitle(const char* programTitle)
	{
		cout << "Star Wars phone direcotry search\n" << "-------------------------------------------------------" << endl;
	}
	void phoneDir(const char* programTitle, const char* fileName) {
		FILE* file = fopen(fileName, "r");
		

		if (!file) {
			cout << programTitle << " phone direcotry search" << endl;
			cout << "-------------------------------------------------------" << endl;
			cout << fileName << " file not found!" << "\n";
			cout << "Thank you for using "<<programTitle << " directory." << endl;
			return;
		}

		int countOfRecords = 0;
		while (fscanf(file, "%[^\t]\t%s\t%s\t%s\n",records[countOfRecords].name,records[countOfRecords].areaCode,records[countOfRecords].prefix,records[countOfRecords].number)==4)
		{
			countOfRecords++;
		}
		fclose(file);
		char nameToSearch[51];
		displayTitle(programTitle);

		while (true)
		{

			readInput(nameToSearch);
			getNameRecord(nameToSearch, records, countOfRecords);
			if (exitRecord(nameToSearch)) {
				break;
			}
		}
		

	}



}
