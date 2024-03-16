/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 11/02/2024
Module Name: Toy.cpp
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#include <iostream>
#include <string>
#include <iomanip>
#include<cmath>
#include"Toy.h"

namespace seneca {
	const double Toy::HST = 0.13;

	void Toy::update(int numItems) {
		numOfToys = numItems;
	}

    // Utility function to trim leading and trailing spaces
    void Toy::trimSpaces(std::string& str) {
        size_t first = str.find_first_not_of(' ');
        size_t last = str.find_last_not_of(' ');
        str = str.substr(first, (last - first + 1));
    }

    Toy::Toy(const std::string& toy) {
        std::string toyCopy = toy; // Making a copy of the original toy string for editing
        size_t position = 0;
        std::string delimiter = ":";

        // Extracting orderID
        position = toyCopy.find(delimiter);
        orderID = stoi(toyCopy.substr(0, position));
        toyCopy.erase(0, position + delimiter.length());

        // Extracting toy name
        position = toyCopy.find(delimiter);
        toyName = toyCopy.substr(0, position); // Assigning directly to toyName
        trimSpaces(toyName);
        toyCopy.erase(0, position + delimiter.length());

        // Extracting number of toys
        position = toyCopy.find(delimiter);
        numOfToys = stoi(toyCopy.substr(0, position));
        toyCopy.erase(0, position + delimiter.length());

        // Extracting toy price
        position = toyCopy.find(delimiter);
        price = stod(toyCopy.substr(0, position)); // Converting to double
        toyCopy.erase(0, position + delimiter.length());
    }


	std::ostream& operator<<(std::ostream& os, const Toy& toy) {
		double subtotal = toy.price * toy.numOfToys;
		double tax = subtotal * Toy::HST;
		double total = subtotal + tax;
        

        os << "Toy" << std::setw(8) << toy.orderID << ":"
            << std::setw(18) << std::right << toy.toyName
            << std::setw(3) << toy.numOfToys << " items"
            << std::setw(8) << toy.price << "/item  subtotal:"
            << std::setw(7) << subtotal << " tax:"
            << std::setw(6) << std::fixed << std::setprecision(2) << tax
            << " total:"<< std::setw(7) << total << std::endl;

		return os;
	}

}

