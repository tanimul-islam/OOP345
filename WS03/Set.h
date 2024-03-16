/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 04/02/2024
Module Name: Set.h
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SENECA_SET_H
#define SENECA_SET_H
#include <cmath>
#include "Collection.h"
namespace seneca {
	template <typename T>
	class Set : public Collection<T, 100> {
	public:
		bool add(const T& item);
	};

	//overriding the inherited add function
	template<typename T>
	bool Set<T>::add(const T& item) {
		bool flag = true;
		size_t size = this->size();
		for (size_t i = 0; i < size; ++i) {
			if ((*this)[i] == item) {
				flag = false;
			}
		}
		if (flag) {
			Collection<T, 100>::add(item);
		}
		return flag;
	}

	// Specialization for T = double
	template <>
	bool Set<double>::add(const double& item) {
		for (size_t i = 0; i < this->size(); ++i) {
			if (std::fabs(this->operator[](i) - item) <= 0.01) {
				return false; // Already exists, so don't add
			}
		}
		// Not found, add the item
		return Collection<double, 100>::add(item);
	}

}

#endif //SENECA_SET_H!