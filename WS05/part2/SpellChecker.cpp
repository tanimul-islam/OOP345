/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 11802/2024
Module Name: SpellChecker.cpp
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include"SpellChecker.h"

using namespace std;

namespace seneca {
	SpellChecker::SpellChecker(const char* filename)
	{
		ifstream readFile(filename);
		if (!readFile) {
			throw "Bad file name!";
		}
		else {
			string m_line{ "" };
			size_t m_count{ 0u };
			int m_space{ 0u };

			while (m_count < ARRAY_SIZE && getline(readFile, m_line)) {
				m_line.erase(0, m_line.find_first_not_of(' '));
				m_space = m_line.find(' ');
				m_badWords[m_count] = m_line.substr(0, m_space);
				m_line.erase(0, m_space);

				m_line.erase(0, m_line.find_first_not_of(' '));
				m_space = m_line.find(' ');
				m_goodWords[m_count] = m_line.substr(0, m_space);
				++m_count;
			}
		}
	}

	void SpellChecker::operator()(std::string& text)
	{
		for (auto i =0; i < ARRAY_SIZE; ++i) {
			while (text.find(m_badWords[i]) != string::npos) {
				text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
				++m_replaceCount[i];
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << endl;

		for (auto i = 0u; i < ARRAY_SIZE; ++i)
			out << setw(15) << std::right << m_badWords[i] << ": " << m_replaceCount[i] << " replacements" << std::left << endl;
	}
}