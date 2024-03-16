/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 04/02/2024
Module Name: Collection.h
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <iostream>
#include <iomanip>
#include "Pair.h"
namespace seneca {

	// Collection class template
	template <typename T, int CAPACITY>
	class Collection {
		T m_elements[CAPACITY];
		static T m_dummy;
		size_t currentSize;
	public:
		Collection();
		~Collection(); //empty body destructor
		size_t size() const;
		std::ostream& display(std::ostream& os = std::cout) const;
		bool add(const T& item);
		T operator[](const int index) const;
	};

	// class var
	template <typename T, int CAPACITY>
	T Collection<T, CAPACITY>::m_dummy{};

	// specialize m_dummy object
	template <>
	Pair Collection<Pair, 100>::m_dummy("No Key", "No Value");

	// Default Constructor
	template <typename T, int CAPACITY>
	Collection<T, CAPACITY>::Collection() {
		currentSize = {};
	}

	// Destructor
	template <typename T, int CAPACITY>
	Collection<T, CAPACITY>::~Collection() {
		// Empty body destructor
	}

	// Return current Number of elements in the collection
	template <typename T, int CAPACITY>
	size_t Collection<T, CAPACITY>::size() const {
		return currentSize;
	}


	// Display Collection
	template<typename T, int CAPACITY>
	std::ostream& Collection<T, CAPACITY>::display(std::ostream& ostr)const {
		ostr << "----------------------" << std::endl;
		ostr << "| Collection Content |" << std::endl;
		ostr << "----------------------" << std::endl;
		for (auto i = 0ul; i < currentSize; ++i)
			ostr << m_elements[i] << std::endl;
		ostr << "----------------------" << std::endl;
		return ostr;
	}

	// Add an item to collection
	template <typename T, int CAPACITY>
	bool Collection<T, CAPACITY>::add(const T& item) {
		bool flag = false;
		if (currentSize < CAPACITY)
		{
			m_elements[currentSize++] = item;
			flag = true;
		}
		return flag;
	}

	// [] overload returns a record at index
	template<typename T, int CAPACITY>
	T Collection<T, CAPACITY>::operator[](const int index)const {
		T tempDummy;
		if (index < (int)currentSize)
		{
			tempDummy = m_elements[index];
		}
		else
		{
			tempDummy = m_dummy;
		}
		return tempDummy;
	}
}
#endif