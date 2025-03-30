#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include<iostream>

namespace sdds {
		const char MAX_SZ_CONTENT = 71;
	class Label {
		char* l_frame;
		char* l_content;

		void setFrame(const char* frame);
		void setContent(const char* content);
	public:
		Label();
		~Label();
		Label(const char* content);
		Label(const char* frameArg, const char* content);
		Label& text(const char* content);

		std::ostream& printLabel()const;
		std::istream& readLabel();
	};

}
#endif // !SDDS_LABEL_H

