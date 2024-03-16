/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 27/01/2024
Module Name: StringSet
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#include <fstream>
#include"StringSet.h"

using namespace std;

namespace seneca {

	StringSet::~StringSet() {
		if (str) delete[] str;
	}



	//one arg coonstructor
	StringSet::StringSet(const char* filename) {
		if (filename) {
			ifstream readFile(filename);
			string temp;

			if (readFile) {
				while (getline(readFile, temp, ' '))
					++currentRecord;

				//allocating new memory for current number of strings
				str = new string[currentRecord];

				// Reset file stream to read from the beginning
				readFile.clear();
				readFile.seekg(0, std::ios::beg);

				int i = 0;
				while (getline(readFile, str[i], ' '))
					++i;
			}
			
		}
	}


	//Copy Constructor
	StringSet::StringSet(const StringSet& src) {
		*this = src;
	}

	StringSet& StringSet::operator=(const StringSet& src) {
		if (this != &src) {
			if (this->str) {
				delete[] str;
				str = nullptr;
			}

			this->currentRecord = src.currentRecord;

			this->str = new string[currentRecord];
			for (size_t i = 0; i < currentRecord; ++i) {
				this->str[i] = src.str[i];
			}
		}
		return *this;
	}

	//Move Constructor

	StringSet::StringSet(StringSet&& src) {
		*this = std::move(src);
	}

	//Move Op

	StringSet& StringSet::operator=(StringSet&& src) {
		if (this != &src) {
			if (this->str) {
				delete[] str;
				str = nullptr;
			}

			this->currentRecord = src.currentRecord;
			src.currentRecord = 0u;

			this->str = src.str;
			src.str = nullptr;
		}
		return *this;
	}

	size_t StringSet::size()const {
		return currentRecord;
	}

	string StringSet::operator[](size_t src)const {
		string copy = "";

		if (src < currentRecord) {
			copy = str[src];
		}
		return copy;
	}

}