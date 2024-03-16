/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 11/02/2024
Module Name: Toy.h
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SENECA_TOY_H
#define SENECA_TOY_H

#include <iostream>

namespace seneca {


    class Toy {
        unsigned int orderID{};  //a positive orderID
        std::string toyName;  //string type toyname
        size_t numOfToys{};  //total numofToy as size_t- size of order
        double price{};  //toy price with double type
        static const double HST;  //unmodifyable HST value maikng available for all objects

        void trimSpaces(std::string& str);

    public:
        Toy();
        void update(int numItems);
        Toy(const std::string& toy);
        friend std::ostream& operator<<(std::ostream& os, const Toy& toy);

    };
}
#endif // !SENECA_TOY_H!