#ifndef CONTAINER_H
#define CONTAINER_H
#include<iostream>
namespace sdds {
	const int DESCRIPTION = 51;
	class Container {

		char m_content[DESCRIPTION];

		int m_capacity;

		int m_contentV;

	protected:

		void setEmpty();

		//const char* getContent();
		
		void setVolume(int newVolume);//setter use for child class PAck

		int getCapacity()const;

		int getVolume() const;

		bool isValid();

		bool isValid(const char* content, const int capacity, const int volume);
		



	public:
		Container(const char* content, int capacity);

		Container(const char* content, int capacity, int volume);

		int operator+=(int value);

		int operator-=(int value);

		operator bool()const;

		//B.clear(200, "Water");

		void clear(int capacity, const char* content);
		void clear(int capacity, int volume, const char* content);

		std::ostream& print(std::ostream& ostr) const;

		std::istream& read(std::istream& istr);
	};
	std::ostream& operator<<(std::ostream& ostr, const Container& container);
	std::istream& operator>>(std::istream& istr, Container& container);
}
#endif // !CONTAINER_H
