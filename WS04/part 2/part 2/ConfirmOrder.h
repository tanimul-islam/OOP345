/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 11/02/2024
Module Name: confirmOrder.h
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SENECA_CONFIRMORDER_H
#define SENECA_CONFIRMORDER_H
#include<string>
#include"Toy.h"
namespace seneca {

	class ConfirmOrder {
		const Toy** mToys;  //Dynamically allocated array of Pointers
		size_t mCount; //number of toys recived
		size_t mCapacity; //capacity of the array
		void resizeArray();    // Private method to resize the array
	public:
        // Constructor and destructor
        ConfirmOrder();
        ConfirmOrder(const ConfirmOrder& src);
        ConfirmOrder(ConfirmOrder&& src) noexcept;
        ~ConfirmOrder();

        // Copy and move assignment operators
        ConfirmOrder& operator=(const ConfirmOrder& src);
        ConfirmOrder& operator=(ConfirmOrder&& src) noexcept;

        // Add and remove toys
        ConfirmOrder& operator+=(const Toy& toy);
        ConfirmOrder& operator-=(const Toy& toy);

        // Friend insertion operator
        friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& confirmOrder);
	};

	
}
#endif // !SENECA_CHILD_H
