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