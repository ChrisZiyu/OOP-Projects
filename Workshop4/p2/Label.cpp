#define _CRT_SECURE_NO_WARNINGS
#include "Label.h"
#include <iomanip>
#include <cstring>

void sdds::Label::setFrame(const char* frame)
{
	delete[] l_frame;
	l_frame = nullptr;
	if (frame != nullptr && frame[0]!='\0')
	{
		l_frame = new char[strlen(frame) + 1];
		strcpy(l_frame, frame);
		// goes out of scope so destructor should delete it
	}
}

void sdds::Label::setContent(const char* content)
{
		delete[] l_content;
		l_content = nullptr;

	if (content != nullptr && content[0] !='\0')
	{
		l_content = new char[strlen(content) + 1];
		strcpy(l_content, content);

	}
}

sdds::Label::Label()
{
	l_frame = nullptr;
	l_content = nullptr;
	setFrame("+-+|+-+|");
}

sdds::Label::~Label()
{
    //need to delete every object created
	//if (l_frame !=nullptr)
	//{
	//	delete[] l_frame;
	//}
	//else if (l_content != nullptr)
	//{
	//	delete[] l_content;
	//}
	delete[] l_frame;
	delete[] l_content;
	l_frame = nullptr;
	l_content = nullptr;
}

sdds::Label::Label(const char* frameArg)
{
	l_frame = nullptr;
	l_content = nullptr;

	if (frameArg != nullptr) {
	setFrame(frameArg);
	
	}
}

sdds::Label::Label(const char* frameArg, const char* content)
{
	l_frame = nullptr;
	l_content = nullptr;
	//int size = 0;

	//size = strlen(content);
	size_t size = strlen(content);

	if (size<=MAX_SZ_CONTENT)
	{
		setFrame(frameArg);
		setContent(content);
	}

}

sdds::Label& sdds::Label::text(const char* content)
{
	if (content != nullptr)
	{
		size_t length = strlen(content);
		if (length <=MAX_SZ_CONTENT)
		{
			setContent(content);
		}

	}
	return *this;
}

std::ostream& sdds::Label::printLabel() const
{
	if (l_frame != nullptr && l_content != nullptr)
	{
		size_t content_length = strlen(l_content);
		// top
		std::cout << l_frame[0];
		std::cout << std::setw(content_length + 3) << std::setfill(l_frame[1]) << l_frame[6] << std::endl;

		// middle
		for (int i = 0; i < 3; i++)
		{
			if (i == 1)
			{
				std::cout << l_frame[7] << ' ' << l_content << ' ' << l_frame[3] << std::endl;
			}
			else
			{
				std::cout << l_frame[7] << std::setw(content_length + 3) << std::setfill(' ') << l_frame[3] << std::endl;
			}
		}

		// bottom
		std::cout << l_frame[6] << std::setw(content_length + 3) << std::setfill(l_frame[1]) << l_frame[4];
	}
	return std::cout;
}

std::istream& sdds::Label::readLabel()
{;
	char tempContent[MAX_SZ_CONTENT];
	std::cin.getline(tempContent, sizeof(tempContent));

	size_t lenght = strlen(tempContent);
	if (lenght<=MAX_SZ_CONTENT)
	{
		setContent(tempContent);
	}
	return std::cin;
}
