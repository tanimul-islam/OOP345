/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 04/02/2024
Module Name: Pait.cpp
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include "Pair.h"
#include <iostream>
#include <string>
#include <iomanip>
namespace seneca {

	bool Pair::operator==(const Pair& src) {
		return this->getKey() == src.m_key;
	}
	std::ostream& Pair::display(std::ostream& os)const {
		os << std::right << std::setw(20) << m_key << ": " << std::left << m_value;
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const Pair& src) {
		return src.display(os);
	}
}