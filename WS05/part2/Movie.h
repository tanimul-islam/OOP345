/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 11802/2024
Module Name: Movie.h
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H

#include<string>

namespace seneca {
	class Movie {
		std::string movieTitle{ "" };
		size_t releasedYear{ 0u };
		std::string movieDes{ "" };
	public:
		Movie() {}
		const std::string& title() const;
		Movie(const std::string& strMovie);

		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(movieTitle);
			spellChecker(movieDes);
		}

		friend std::ostream& operator<<(std::ostream& os, const Movie& src);
	};
}

#endif // !SENECA_MOVIE_H
