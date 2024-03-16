#ifndef SENECA_CONFIRMORDER_H
#define SENECA_CONFIRMORDER_H
#include<string>
#include"Toy.h"
namespace seneca {

	class ConfirmOrder {
		const Toy** mToys;  //Dynamically allocated array of Pointers
		size_t mCount; //number of toys recived
		size_t mCapacity; //capacity of the array
	public:
		ConfirmOrder();
		~ConfirmOrder();
		ConfirmOrder(const ConfirmOrder& other); //copy constructor
		ConfirmOrder& operator=(const ConfirmOrder& other);
		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);

	private:
		void resizeArray();  //resize the 
		bool containsToy(const Toy& toy) const; // search a toy in array
	};

	
}
#endif // !SENECA_CHILD_H
