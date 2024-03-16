/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 11802/2024
Module Name: Book.h
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <string>

namespace seneca {
	class Book {
		std::string bookAuthor{ "" };
		std::string bookTitle{ "" };
		std::string pubCountry{ "" };
		size_t publicationYear{ 0 };
		double bookPrice{ 0.0 };
		std::string bookDescription{ "" };
	public:
		Book() {};
		const std::string& title() const;
		const std::string& country() const; // a query that returns the publication country
		const size_t& year() const; //a query that returns the publication year
		double& price(); //a function that returns the price by reference, allowing the client code to update the price
		Book(const std::string& strBook);

		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(bookDescription);
		}

		friend std::ostream& operator<<(std::ostream& os, const Book& src);
	};
}

#endif // !SENECA_BOOK_H
