#include "LabelMaker.h"
#include <iostream>
using namespace std;
//

sdds::LabelMaker::LabelMaker(int noOfLabels)
{
	m_size = noOfLabels;
	m_labels = new Label[noOfLabels];
}

sdds::LabelMaker::~LabelMaker()
{

	delete[] m_labels;
	m_labels = nullptr;
}

void sdds::LabelMaker::readLabels()
{
    cout << "Enter " << m_size << " labels:" << endl;
    for (size_t i = 0; i < m_size; i++)
    {
        cout << "Enter label number " << i + 1<<endl;
		cout << "> ";
        m_labels[i].readLabel();
    }
}

void sdds::LabelMaker::printLabels()
{
	
	for (size_t i = 0; i < m_size; i++)
	{
		m_labels[i].printLabel();
		cout << "\n";
	}
}
