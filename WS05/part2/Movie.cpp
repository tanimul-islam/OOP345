/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 11802/2024
Module Name: movie.cpp
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#include<iostream>
#include<iomanip>
#include"Movie.h"

using namespace std;

namespace seneca {
	const std::string& Movie::title() const
	{
		return movieTitle;
	}

	Movie::Movie(const std::string& strMovie)
	{
        if (!strMovie.empty()) {
            string tempStr = strMovie;
            int tempIndex = 0u;

            auto removeSpace = [=](string& src) {
                if (src[0] == ' ')
                    src.erase(0, src.find_first_not_of(' '));
                else
                    src.erase(src.find_last_not_of(' ') + 1);
                };

            removeSpace(tempStr);
            tempIndex = tempStr.find(',');
            movieTitle = tempStr.substr(0, tempIndex);
            removeSpace(movieTitle);
            tempStr.erase(0, tempIndex + 1);

            removeSpace(tempStr);
            tempIndex = tempStr.find(',');
            releasedYear = std::stoi(tempStr.substr(0, tempIndex));
            tempStr.erase(0, tempIndex + 1);

            removeSpace(tempStr);
            removeSpace(tempStr);
            movieDes = tempStr;
        }

	}
    std::ostream& operator<<(std::ostream& os, const Movie& src)
    {
        os << setw(40) << right << src.movieTitle << " | ";
        os << left << setw(4) << src.releasedYear << " | ";
        os << src.movieDes << endl;

        return os;
    }
}