#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h" // intentional

int cout = 0; // won't compile if headers don't follow convention regarding namespaces

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	seneca::Book library[7];
	size_t bookCount = 0;
	if (argc == 2) {
		std::ifstream inputFile(argv[1]);
		if (!inputFile) {
			std::cerr << "ERROR: Cannot open file: " << argv[1] << "\n";
			exit(AppErrors::CannotOpenFile);
		}
		std::string line;
		while (std::getline(inputFile, line) && bookCount < 7) {
			if (!line.empty() && line[0] != '#') {
				library[bookCount] = seneca::Book(line);
				++bookCount;
			}
		}
		inputFile.close();
	}
	else
	{
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	//a lambda expression that fixes the price of a book accoding to the rules
	auto adjustPrice = [&](seneca::Book& book) {
		if (book.country() == "US")
			book.price() *= usdToCadRate;
		else if (book.country() == "UK" && book.year() >= 1990 && book.year() <= 1999)
			book.price() *= gbpToCadRate;
	};



	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	//  iterate over the library and print each book to the screen
	for (size_t i = 0; i < 7 && i < bookCount; ++i) {
		std::cout << library[i];
	}


	std::cout << "-----------------------------------------\n\n";

	for (size_t i = 0; i < bookCount; ++i) {
		adjustPrice(library[i]);
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	// Iterate over the library and print each book to the screen
	for (size_t i = 0; i < 7 && i < bookCount; ++i) {
		std::cout << library[i];
	}

	std::cout << "-----------------------------------------\n";

	return cout;
}
