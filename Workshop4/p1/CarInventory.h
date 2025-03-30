/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 10/3/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_CAR_INVENTORY_H
#define SDDS_CAR_INVENTORY_H

namespace sdds {
	
	class CarInventory {
		char* type;
		char* brand;
		char* model;
		int year;
		int code;
		double price;
		//int assign_year;
		//int assign_code;
		//int assign_price;
		
		void resetInfo();
	public:
		CarInventory();
		CarInventory(const char* typeCar, const char* brandCar, const char* modelCar, int yearCar=2022, int codeCar=100, double carPrice=1.0);		
		~CarInventory();
		bool isValid();
		CarInventory& setInfo(const char* typeCar, const char* brandCar, const char* model, int yearCar, int codeCar, double carPrice);
		void printInfo() const;
		//check state of the object
		bool issimilarto(const CarInventory& car) const;
		
	};
		int find_similar(CarInventory cars[], const int num_cars);
	
}
#endif // !SDDS_CAR_INVENTORY_H

