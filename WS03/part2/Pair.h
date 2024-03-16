/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 04/02/2024
Module Name: Pair.h
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H
#include <iostream>
#include <string>
namespace seneca {

	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		const std::string& getKey() { return m_key; }
		const std::string& getValue() { return m_value; }
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value } {};
		Pair() = default;
		bool operator==(const Pair& src);
		std::ostream& display(std::ostream& os)const;
	};
	std::ostream& operator<<(std::ostream& os, const Pair& src);
}
#endif // !SENECA_PAIR_H
