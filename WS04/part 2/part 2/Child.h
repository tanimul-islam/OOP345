/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 11/02/2024
Module Name: Child.h
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SENECA_CHILD_H
#define SENECA_CHILD_H
#include<string>
#include"Toy.h"
namespace seneca {

	class Child {
		std::string childName;
		int childAge;
		const Toy** toyObject;
		size_t totalCount;              // Number of toys stored
		
		//private method to copy toys
		void copyToy(const Toy* toys[], size_t numofToys);

	public:
		Child(std::string name, int age, const Toy* toys[], size_t count);
		~Child();

        // Copy constructor
		Child(const Child& other);

        // Move constructor
		Child(Child&& other) ;

        // Copy assignment operator
        Child& operator=(const Child& other);

        // Move assignment operator
        Child& operator=(Child&& other) ;


		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Child& child);
	};
}
#endif // !SENECA_CHILD_H
