/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 11/02/2024
Module Name: Child.cpp
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#include<iostream>
#include<string>
#include"Child.h"

namespace seneca {
	//private function for making copy of toys
	void Child::copyToy(const Toy* toys[], size_t numofToys) {
		toyObject = new const Toy * [numofToys];
		for (size_t i = 0; i < numofToys; i++) {
			toyObject[i] =  toys[i]; //deep copy
		}
        totalCount = numofToys;
	}
	//constructor
	Child::Child(std::string name, int age, const Toy* toys[], size_t count)
	{
		childName = name;
		childAge = age;
		totalCount = count;
		copyToy(toys, count);
	}
	//destructor
	Child::~Child() {
        delete[] toyObject;
        toyObject = nullptr;
	}


    // Copy constructor
    Child::Child(const Child& other) {
        childName = other.childName;
        childAge = other.childAge;
        totalCount = other.totalCount;
        toyObject = new const Toy * [totalCount];
        for (size_t i = 0; i < totalCount; ++i) {
            toyObject[i] = new Toy(*(other.toyObject[i]));
        }
    }

    Child& Child::operator=(const Child& other) {
        if (this != &other) {
            childName = other.childName;
            childAge = other.childAge;
            // Delete existing toys
            for (size_t i = 0; i < totalCount; ++i) {
                delete toyObject[i];
            }
            delete[] toyObject;
            // Copy toys from other object
            totalCount = other.totalCount;
            toyObject = new const Toy * [totalCount];
            for (size_t i = 0; i < totalCount; ++i) {
                toyObject[i] = new Toy(*(other.toyObject[i]));
            }
        }
        return *this;
    }

    Child::Child(Child&& other)  {
        *this = std::move(other);
    }

    Child& Child::operator=(Child&& other)  {
        if (this != &other) {
            // Delete existing toys
            for (size_t i = 0; i < totalCount; ++i) {
                delete toyObject[i];
            }
            delete[] toyObject;
            // Move data from other object
            childName = std::move(other.childName);
            childAge = std::move(other.childAge);
            totalCount = std::move(other.totalCount);
            toyObject = other.toyObject;;
            // Reset other object
            other.childName = "";
            other.childAge = 0;
            other.totalCount = 0;
            other.toyObject = nullptr;
        }
        return *this;
    }


	// Query to get the number of toys
	size_t Child::size() const {
		return totalCount;
	}
	// Friend insertion operator
	 std::ostream& operator<<(std::ostream& os, const Child& child) {
         static int toyCounter = 0;
         ++toyCounter;
		os << "--------------------------" << std::endl;
        os << "Child " << toyCounter << ": " << child.childName << " " << child.childAge << " years old:" << std::endl;
		os << "--------------------------" << std::endl;
		if (child.size() == 0) {
			os << "This child has no toys!" << std::endl;
		}
		else {
			for (size_t i = 0; i < child.size(); i++) {
				os << *child.toyObject[i];
			}
			os << "--------------------------" << std::endl;
		}
		return os;
	}

}