#pragma once
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"


namespace sdds
{
    class LabelMaker
    {
        Label* m_labels;
        size_t m_size;
    public:

        LabelMaker(int noOfLabels);
        ~LabelMaker();
        void readLabels();
        void printLabels();
    };

}

#endif // SDDS_LABELMAKER_H

