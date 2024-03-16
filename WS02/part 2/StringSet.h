/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 27/01/2024
Module Name: StringSet
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#pragma once
#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H



#include <string>

namespace seneca {

	class StringSet {
		size_t currentRecord{ 0u };
		std::string *str{ nullptr };
	public:
		StringSet() {};
		~StringSet(); //destructor
		//one arg coonstructor
		StringSet(const char* filename);
		//Copy Constructor
		StringSet(const StringSet &src);
		//copy assignment
		StringSet &operator=(const StringSet &src);
		//move Constructor
		StringSet(StringSet &&src);
		//move assignment
		StringSet& operator=(StringSet &&src);

		size_t size()const;
		std::string operator[](size_t) const;
	};

}
#endif // !SENECA_STRINGSET_H