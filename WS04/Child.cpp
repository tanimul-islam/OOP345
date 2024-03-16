#include<iostream>
#include<string>
#include"Child.h"

namespace seneca {
	//private function for making copy of toys
	void Child::copyToy(const Toy* toys[], size_t numofToys) {
		toyObject = new const Toy * [numofToys];
		for (size_t i = 0; i < numofToys; ++i) {
			toyObject[i] = new Toy(*toys[i]); //deep copy
		}
		mCount = numofToys;
	}
	//constructor
	Child::Child(std::string name, int age, const Toy* toys[], size_t count)
	:childName(std::move(name)), childAge(age), toyObject(nullptr), mCount(0){
		copyToy(toys, count);
	}
	//destructor
	Child::~Child() {
		for (size_t i = 0; i < mCount; ++i) {
			delete toyObject[i]; // Delete each Toy object
		}
		delete[] toyObject; // Delete the array of pointers
		mCount = 0;
	}
	// Query to get the number of toys
	size_t Child::size() const {
		return mCount;
	}
	// Friend insertion operator
	 std::ostream& operator<<(std::ostream& os, const Child& child) {
		os << "--------------------------" << std::endl;
		os << "Child CALL_CNT: " << child.childName << " " << child.childAge << " years old:" << std::endl;
		os << "--------------------------" << std::endl;
		if (child.size() == 0) {
			os << "This child has no toys!" << std::endl;
		}
		else {
			for (size_t i = 0; i < child.size(); ++i) {
				os << *child.toyObject[i] << std::endl;
			}
			os << "--------------------------" << std::endl;
		}
		return os;
	}

}