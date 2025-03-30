/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 10/3/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include "CarInventory.h"
#include<cstring>
#include<iostream>
#include <iomanip>

using namespace std;
using namespace sdds;

void CarInventory::resetInfo()
{
	type = nullptr;
	brand = nullptr;
	model = nullptr;
	year = 0;
	code = 0;
	price = 0.0;
}

CarInventory::CarInventory()
{
	resetInfo();
}

CarInventory::~CarInventory()
{
	if (type !=nullptr && brand != nullptr && model !=nullptr)
	{
		delete[] type;
		delete[] brand;
		delete[] model;

		type = nullptr;
		brand = nullptr;
		model = nullptr;
	}

}

CarInventory::CarInventory(const char* typeCar, const char* brandCar, const char* modelCar, int yearCar, int codeCar, double priceCar)
{
		resetInfo();


		//if (type != nullptr && brand != nullptr && model != nullptr && yearCar == 0 && codeCar == 0 && priceCar == 0)
		//{
		//	type = new char[strlen(typeCar) + 1];
		//	strcpy(type, typeCar);

		//	brand = new char[strlen(brandCar) + 1];
		//	strcpy(brand, brandCar);

		//	model = new char[strlen(modelCar) + 1];
		//	strcpy(model, modelCar);



		//	this->year = 2002;
		//	this->code = 100;
		//	this->price = 1.0;
		//	//yearCar = year;
		//	//codeCar = code;
		//	//priceCar = price;
		//}
		//else {
			type = new char[strlen(typeCar) + 1];
			strcpy(type, typeCar);

			brand = new char[strlen(brandCar) + 1];
			strcpy(brand, brandCar);

			model = new char[strlen(modelCar) + 1];
			strcpy(model, modelCar);

			year = yearCar;
			code = codeCar;
			price = priceCar;
		//}
}






bool CarInventory::isValid()
{
	bool ok = true;
	ok= (type != nullptr && brand != nullptr && model != nullptr && year >= 1990 && code >= 100 && code <= 999 && price > 0);
	if (ok)
	{
		return true;
	}
	else if (type != nullptr && brand != nullptr && model != nullptr && year == 0 && code == 0 && price == 0)
	{
		return false;
	}
	return false;
	//else if (type != nullptr && brand != nullptr && model != nullptr)
	//{

	//}
}

CarInventory&::CarInventory::setInfo(const char* typeCar, const char* brandCar, const char* modelCar, int yearCar, int codeCar, double carPrice)
{
	delete[] type;
	delete[] brand;
	delete[] model;

	type = nullptr;
	brand = nullptr;
	model = nullptr;

	type = new char[strlen(typeCar) + 1];
	strcpy(type, typeCar);

	brand = new char[strlen(brandCar) + 1];
	strcpy(brand, brandCar);

	model = new char[strlen(modelCar) + 1];
	strcpy(model, modelCar);

	year = yearCar;
	code = codeCar;
	price = carPrice;

	return *this;
}

void CarInventory::printInfo() const
{
	cout << left 
		<< "| " 
		<< setw(10) 
		<< type 
		<< " | " << setw(16)
		<< brand 
		<< " | " 
		<< setw(16) 
		<< model
		<< " | " 
		<< setw(4)
		<< year
		<< " | "
		<< setw(4)
		<< right
		<< code
		<< " | " 
		<< setw(9)
		<< fixed
		<< right
		<< setprecision(2)
		<< price
		<< " |"
		<< endl;

	//cout.setf(ios::fixed);
	//cout.setf(ios::left);
	//cout << " ";
	//cout.width(60);
	//cout << type;
	//cout.fill(' ');
	//cout << "|"<<endl;
	//cout.unsetf(ios::left);

	

	
}

bool CarInventory::issimilarto(const CarInventory& car) const
{

	if (type == nullptr || brand == nullptr || model == nullptr ||
		car.type == nullptr || car.brand == nullptr || car.model == nullptr) {
		return false;
	}

	
	return strcmp(type, car.type) == 0 &&
		strcmp(brand, car.brand) == 0 &&
		strcmp(model, car.model) == 0 &&
		year == car.year;
}


int sdds::find_similar(CarInventory cars[], const int num_cars)
{
	for (int i = 0; i < num_cars; i++) {
		for (int j = i + 1; j < num_cars; j++) {
			if (cars[i].issimilarto(cars[j])) {
				return i;
			}
		}
	}
	return false;
}
