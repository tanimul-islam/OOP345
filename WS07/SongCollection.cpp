#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <list>
#include <iterator>
#include "SongCollection.h"

namespace seneca {

	SongCollection::SongCollection(const char* src) {
		std::ifstream readFile(src);
		Song newSong;
		std::string line;

		//lamda function for extractig token
		auto extractData = [](std::string& src, int index) {
			std::string token = src.substr(0, index);
			src = src.substr(index);
			token.erase(0, token.find_first_not_of(' '));
			token.erase(token.find_last_not_of(' ') + 1);

			return token;
		};

		if (!readFile) {
			throw std::invalid_argument("Error: Bad file name!");
		}
		else {
			while (getline(readFile, line)) {
				newSong.m_title = extractData(line, 25) ;
				newSong.m_artist = extractData(line, 25);
				newSong.m_album = extractData(line, 25);
				newSong.m_releaseYear = (extractData(line, 5));
				newSong.m_length = std::stoi(extractData(line, 5));
				newSong.m_price = std::stod(extractData(line, 5));

				m_total += newSong.m_length;

				m_song.push_back(newSong);
			}
		}
	}
	void SongCollection::display(std::ostream& out) const
	{
		size_t hour = m_total / 3600;
		size_t minute = (m_total % 3600) / 60;
		size_t second = (m_total % 3600) % 60;

		for_each(m_song.begin(), m_song.end(), [&out](const Song& theSong) {
			out << theSong << std::endl;
		});

		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "|" << std::right << std::setw(78) << std::setfill(' ') << "Total Listening Time: ";
		out << hour << ":" << minute << ":" << second << " |" << std::endl;

	}

	void SongCollection::sort(std::string src)
	{
		if (src == "title") {
			std::sort(m_song.begin(), m_song.end(), [](Song& theSong, Song& otherSong) { //using sort from algorithm library with a boolean lambda function
				return theSong.m_title < otherSong.m_title;
				});
		}
		else if (src == "album")
			std::sort(m_song.begin(), m_song.end(), [](Song& theSong, Song& anotherSong) {
			return theSong.m_album < anotherSong.m_album;
				});

		else if (src == "length")
			std::sort(m_song.begin(), m_song.end(), [](Song& theSong, Song& anotherSong) {
			return theSong.m_length < anotherSong.m_length;
				});

		else
			std::cout << "Error: Invalid input!" << std::endl;
	}

	void SongCollection::cleanAlbum()
	{
		for_each(m_song.begin(), m_song.end(), [&](Song& theSong) {
			theSong.m_album = theSong.m_album == "[None]" ? "" : theSong.m_album;
		});
	}

	bool SongCollection::inCollection(std::string src) const
	{
		return std::find_if(m_song.begin(), m_song.end(), [&](const Song& song) {
			return song.m_artist == src;
			}) != m_song.end();
	}

	std::list<Song> SongCollection::getSongsForArtist(std::string src) const
	{
		std::list<Song> result;
		std::copy_if(m_song.begin(), m_song.end(), std::back_inserter(result), [&](const Song& song) {
			return song.m_artist == src;
		});

		return result;
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		out << "| " << std::left << std::setw(20) << std::setfill(' ') << theSong.m_title;
		out << " | " << std::setw(15) << std::setfill(' ') << theSong.m_artist;;
		out << " | " << std::setw(20) << std::setfill(' ') << theSong.m_album;
		out << " | " << std::right << std::setw(6) << theSong.m_releaseYear;
		out << " | " << theSong.m_length / 60 << ':';
		out << std::setw(2) << std::setfill('0') << theSong.m_length % 60;
		out << " | " << std::fixed << std::setprecision(2) << theSong.m_price << " |";

		return out;
	}
}