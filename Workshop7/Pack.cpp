/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/09/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Pack.h"
#include <limits>
namespace sdds {
	Pack::Pack(const char* description, int size, int unitSize, int numberOfUnits) :Container(description, (size*unitSize), (numberOfUnits*unitSize))
	{
		if (unitSize > 0)
		{
			m_unitSize = unitSize;
			m_numOfUnits = numberOfUnits;
		}
		else {
			setEmpty();
		}
	}

	Pack::Pack(const char* description, int unitSize): Container(description, 330 * unitSize, 0), m_unitSize(330), m_numOfUnits(unitSize)
	{
		if (unitSize > 0)
		{
			m_numOfUnits = unitSize;
		}
		else {
			setEmpty();
		}
	}
	int Pack::operator+=(int valuePack)
	{
		//int newVolume = 0;
		//if (isValid() && valuePack > 0) {
		//	spaceAvailable = (getCapacity() - getVolume()) / m_unitSize;
		//	remainingSpace = m_numOfUnits - unitsAdded; // Calculate remaining space in the pack
		//	int additionalUnits = valuePack <= spaceAvailable ? valuePack : spaceAvailable;

		//	// Limit the additional units to the remaining space (10)
		//	if (additionalUnits >= remainingSpace ) {
		//		additionalUnits = remainingSpace;
		//	}
		//	remainingSpace -= additionalUnits;
		//	unitsAdded = additionalUnits; // Accumulate unitsAdded
		//	remainingSpace = unitsAdded;
		//	if (remainingSpace==spaceAvailable)
		//	{
		//		remainingSpace = m_numOfUnits;
		//	}

		//	newVolume = unitsAdded * m_unitSize; // Calculate new volume based on accumulated unitsAdded

		//	if (additionalUnits > 0) {
		//		Container::operator+=(newVolume);
		//	}
		//}
		//return unitsAdded;
		
		if (isValid() && valuePack > 0)
		{
			int spaceAvailable = (getCapacity() - getVolume()) / m_unitSize;

			// Calculate how many units can be added, considering available space
			unitsAdded = (valuePack <= spaceAvailable) ? valuePack : spaceAvailable;

			// Calculate the new volume based on the added units
			int newVolume = unitsAdded * m_unitSize;

			// Update the pack's volume and the number of units added
			Container::operator+=(newVolume);
			 // Accumulate unitsAdded

			// If all available space is used, reset the remaining space to the full pack size
			//if (unitsAdded == spaceAvailable)
			//{
			//	unitsAdded = m_numOfUnits;
			//}
		}
		return unitsAdded;
	}

	int Pack::operator-=(int valuePack)
	{
		//int newVolume = 0;
		//unitsAdded = 0;
		//if (isValid() && valuePack > 0) {
		//	spaceAvailable = m_numOfUnits;
		//	remainingSpace = m_numOfUnits - valuePack; // Calculate remaining space in the pack
		//	int additionalUnits = (m_numOfUnits >= valuePack) ? valuePack : m_numOfUnits;

		//	// Limit the additional units to the remaining space (10)
		//	if (additionalUnits >= remainingSpace) {
		//		additionalUnits = remainingSpace;
		//		unitsAdded = valuePack;
		//	}
		//	/*remainingSpace += additionalUnits;*/
		//	if (additionalUnits<=remainingSpace)
		//	{
		//		unitsAdded = remainingSpace;
		//	}
		//	 // Accumulate unitsAdded
		//	remainingSpace = additionalUnits;


		//	newVolume = unitsAdded * m_unitSize; // Calculate new volume based on accumulated unitsAdded

		//	if (additionalUnits > 0) {
		//		Container::operator-=(newVolume);
		//	}

		//}
		//return unitsAdded;
		/*int unitsRemoved = 0;*/
		if (isValid() && valuePack > 0)
		{
			// Calculate the total units in the pack
			int totalUnits = getNoUnits();

			// Determine how many units can be removed (up to the total units in the pack)
			unitsAdded = (valuePack <= totalUnits) ? valuePack : totalUnits;

			// Calculate the volume to remove
			int volumeToRemove = m_unitSize*unitsAdded  ;

			// Call the base class's operator-= with the calculated volume
			Container::operator-=(volumeToRemove);

			// If the pack is empty, reset the number of units
			//if (getNoUnits() == 0) {
			//	unitsAdded = 0;
			//}
		}
		return unitsAdded;
	}

	int Pack::unit() const
	{
		return m_unitSize;
		/*return getVolume() / m_unitSize*/;

	}

	int Pack::getNoUnits() const
	{
		/*if (isValid())*/
		{
			return getVolume() / m_unitSize;
		}
		/*return 0;*/
	}

	int Pack::getSize() const
	{
		/*if (isValid())*/
		{
			return getCapacity() / m_unitSize;
		}
		/*return 0;*/
	}

	void Pack::clear(int packSize, int unitSize, const char* description)
	{
		if (unitSize>0)
		{
			Container::clear(packSize,unitSize,description);
			m_unitSize = unitSize;
		}
	}

	std::ostream& Pack::printPack(std::ostream& ostr) const
	{
		Container::print(ostr);
		if (*this)
		{
			/*int remainingSpace = m_numOfUnits - getNoUnits();*/
				ostr << ", " << getVolume() / m_unitSize << " in a pack of " << m_numOfUnits;
		}
		return ostr;
	}
	//recheck this!!!!
	std::istream& Pack::readPack(std::istream& istr)
	{
		if (!isValid())
		{
			std::cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.get(); // Wait for Enter key
			return istr;
		}
		if (getCapacity() == getVolume()) {

			istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
			std::cout << "Pack is full! Press <ENTER> to continue...";
			istr.get(); // Wait for Enter key
			return istr;
		}
		unitsAdded = 0;
		std::cout << "Add to ";
		Pack::printPack(std::cout);
		std::cout << std::endl << "> ";

		int value = 0;
		int missingU = getSize();
		while (true) {
			istr >> value;
			if (istr.fail()) {
				istr.clear();
				istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				//while (istr.get() != '\n') {}
				std::cout << "Invalid Integer, retry: ";
				continue;
			}
			if (value < 1 || value > missingU) {
				/*while (istr.get() != '\n') {}*/
				std::cout << "Value out of range [1<=val<=" << missingU-value<<"]: ";
				continue;
			}
			else if (value*m_unitSize+this->getVolume()!=this->getCapacity()&&this->getVolume()!=0) {
				std::cout << "Value out of range [1<=val<=" << missingU - value << "]: ";
				continue;
			}
			break;
		}

		unitsAdded = operator+=(value);
		std::cout << "Added " << unitsAdded << std::endl;
		return istr;

	}



	std::ostream& operator<<(std::ostream& ostr, const Pack& pack)
	{
		pack.printPack(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Pack& pack)
	{
		pack.readPack(istr);
		return istr;
	}

}
