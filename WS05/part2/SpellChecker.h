/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 11802/2024
Module Name: SpellChecker.h
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H
#include <string>

namespace seneca {
	const int ARRAY_SIZE = 6;

	class SpellChecker {
		std::string m_badWords[ARRAY_SIZE]{};
		std::string m_goodWords[ARRAY_SIZE]{};
		size_t m_replaceCount[ARRAY_SIZE] {};
	public:
		SpellChecker() {}
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}

#endif // !SENECA_SPELLCHECKER_H
