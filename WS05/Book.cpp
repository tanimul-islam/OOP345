#include<iostream>
#include <iomanip>
#include "Book.h"

using namespace std;

namespace seneca {
	const std::string& Book::title() const {
		return bookTitle;
	}
	const std::string& Book::country() const {
		return pubCountry;
	}
	const size_t& Book::year() const {
		return publicationYear;
	}
	double& Book::price() {
		return bookPrice;
	}
	Book::Book(const std::string& strBook) {
		string tempstr = strBook;
		int tempIndex = 0u;

		auto removeSpace = [=](string& src) {
			if (src[0] == ' ') {
				src.erase(0, src.find_first_not_of(' '));
			}
			else {
				src.erase(src.find_last_not_of(' ') + 1);
			}
		};

		removeSpace(tempstr);
		tempIndex = tempstr.find(',');
		bookAuthor = tempstr.substr(0, tempIndex);
		removeSpace(bookAuthor);
		tempstr.erase(0, tempIndex + 1);

		removeSpace(tempstr);
		tempIndex = tempstr.find(',');
		bookTitle = tempstr.substr(0, tempIndex);
		removeSpace(bookTitle);
		tempstr.erase(0, tempIndex + 1);

		removeSpace(tempstr);
		tempIndex = tempstr.find(',');
		pubCountry = tempstr.substr(0, tempIndex);
		removeSpace(pubCountry);
		tempstr.erase(0, tempIndex + 1);

		removeSpace(tempstr);
		tempIndex = tempstr.find(',');
		bookPrice = std::stod(tempstr.substr(0, tempIndex));
		tempstr.erase(0, tempIndex + 1);

		removeSpace(tempstr);
		tempIndex = tempstr.find(',');
		publicationYear = std::stoi(tempstr.substr(0, tempIndex));
		tempstr.erase(0, tempIndex + 1);

		removeSpace(tempstr);
		removeSpace(tempstr);
		bookDescription = tempstr;
	}



	std::ostream& operator<<(std::ostream& os, const Book& src)
	{
		os << setw(20) << std::right << src.bookAuthor << " | ";
		os << setw(22) << src.bookTitle << " | ";
		os << setw(5) << src.pubCountry << " | ";
		os << setw(4) << src.publicationYear << " | ";
		os << setw(6) << fixed << setprecision(2) << src.bookPrice << " | ";
		os << std::left << src.bookDescription << endl;
		return os;
	}
	
}