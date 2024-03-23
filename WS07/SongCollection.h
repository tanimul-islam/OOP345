//==============================================
// Name:           Tanimul Islam
// Student Number: 129414223
// Email:          tislam38@myseneca.ca
// Section:        ZAA
// Date:           March 16, 2024
// I have completed all the coding by myself and
// copied only the code provided by the professor to submit my assignment.
//==============================================
// SongCollection.h
#ifndef SENECA_SONGCOLLECTION_H
#define SENECA_SONGCOLLECTION_H


#include <iostream>
#include <string>
#include <vector>
#include <list>

namespace seneca {
	struct Song {
		std::string m_artist{};
		std::string m_title{};
		std::string m_album{};
		double m_price{};
		std::string m_releaseYear{};
		size_t m_length{};
	};

	class SongCollection {
		std::vector<Song> m_song;
		size_t m_total{ 0u };
	public:
		SongCollection(const char* src);
		void display(std::ostream& out) const;
		//sort the collection of songs in ascending order
		void sort(std::string src);
		// removes the token [None] from the album field of the songs that do not have a valid album.
		void cleanAlbum();
		// returns true if the collection contains any song by that artist
		bool inCollection(std::string src) const;
		//returns the list of songs of that artist available in the collection
		std::list<Song> getSongsForArtist(std::string src) const;
	};

	//Free Helper 
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}

#endif // !SENECA_SONGCOLLECTION_H
