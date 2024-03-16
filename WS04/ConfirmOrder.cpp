#include<iostream>
#include<string>
#include"ConfirmOrder.h"

namespace seneca {
	//Constructor and destructor
	ConfirmOrder::ConfirmOrder() : mToys(nullptr), mCapacity(0), mCount(0) {};
	ConfirmOrder::~ConfirmOrder() {
		delete[] mToys;
		mCapacity = 0;
		mCount = 0;
	}
	ConfirmOrder::ConfirmOrder(const ConfirmOrder& other) : mToys(nullptr), mCount(other.mCount), mCapacity(other.mCapacity) {
		mToys = new const Toy * [mCapacity];
		for (size_t i = 0; i < mCapacity; ++i) {
			mToys[i] = new Toy(*other.mToys[i]);
		}
	}
	// Assignment operator
	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& other) {
		if (this != &other) { // Check for self-assignment
			// Deallocate existing memory
			for (size_t i = 0; i < mCount; ++i) {
				delete mToys[i];
			}
			delete[] mToys;

			// Copy data from other object
			mCount = other.mCount;
			mCapacity = other.mCapacity;
			mToys = new const Toy * [mCapacity];
			for (size_t i = 0; i < mCount; ++i) {
				mToys[i] = new Toy(*other.mToys[i]);
			}
		}
		return *this;
	}
	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
	{
		if (containsToy(toy)) {
			return *this;
		}
		
		if (mCount >= mCapacity) {
			resizeArray();
		}
		mToys[mCount++] = &toy;
		return*this;
	}
	// Operator -= to remove a toy from the order
	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
		bool flag = false;
		for (size_t i = 0; i < mCount; ++i) {
			if (containsToy(toy) && !flag) { // Compare contents of Toy objects
				delete mToys[i]; // Deallocate memory for the Toy object
				mToys[i] = nullptr;
				flag = true;
			}
		}
		return *this;
	}




	//private function for resizing the array
	void ConfirmOrder::resizeArray() {
		size_t newCapacity = (mCapacity == 0) ? 1 : mCapacity * 2; // doubling the capacity 
		const Toy** temp = new const Toy * [newCapacity];
		for (size_t i = 0; i < mCount; ++i) {
			temp[i] = mToys[i]; // Copy existing elements to the new array
		}
		delete[] mToys;
		mToys = temp;
		mCapacity = newCapacity;
	}
	// Private helper function to search for a toy in the array
	bool ConfirmOrder::containsToy(const Toy& toy) const {
		for (size_t i = 0; i < mCount; ++i) {
			if (mToys[i] == &toy) {
				return true; // Toy found
			}
		}
		return false; // Toy not found
	}

}