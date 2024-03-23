//==============================================
// Name:           Tanimul Islam
// Student Number: 129414223
// Email:          tislam38@myseneca.ca
// Section:        ZAA
// Date:           March 22, 2024
// I have completed all the coding by myself and
// copied only the code provided by the professor to submit my assignment.
//==============================================
#ifndef SENECA_LIST_H
#define SENECA_LIST_H


#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace seneca {
	template <typename T>
	class List {
		std::vector<T> list;
	public:
		List() { }
		List(const char* fn) {
			std::ifstream file(fn);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(fn) + std::string(" ***");
			while (file) {
				T e;
				if (e.load(file))
					list.push_back(T(e));
			}
		}
		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		// Overload the += operator with a raw pointer
		//       as a second operand.
		void operator+=(const T* obj) {
			list.push_back(*obj);
		}

		// Overload the += operator with a smart pointer
			//       as a second operand.
		void operator+=(const std::unique_ptr<T>& obj) {
			list.push_back(*obj);
		}

		void display(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.display(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const List<T>& l) {
		l.display(os);
		return os;
	}
}
#endif