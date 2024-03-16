/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 17/01/2024
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include<iomanip>
#include "event.h"

using namespace std;


namespace seneca {
	size_t g_sysClock = 0;
	Event::Event(const Event& src) {
		*this = src; //calling copy const
	}

	Event& Event::operator = (const Event& src) {
		if (this != &src) {
			this->startTime = src.startTime;

			if (this->eventDescription != nullptr) {
				delete[] this->eventDescription;
				this->eventDescription = nullptr;
			}

			if (src.eventDescription != nullptr && src.eventDescription[0] != '\0') {
				this->eventDescription = new char[strlen(src.eventDescription) + 1];
				strcpy(this->eventDescription, src.eventDescription);
			}
		}
		return *this;
	}

	void Event::display() const {
		static size_t counter = 1;

		unsigned int hh = 0u, mm = 0u, ss = 0u;

		hh = startTime / 3600;
		mm = startTime / 60 % 60;
		ss = startTime % 60;

		cout << setw(2) << setfill(' ') << counter++ << ". ";
		if (eventDescription != nullptr && eventDescription[0] != '\0') {
			cout << setw(2) << setfill('0') << hh << ":" << setw(2) << mm << ":" << setw(2) << ss << " => " << eventDescription << endl;
		}
		else {
			cout << "| No Event |" << endl;
		}
	}

	void Event::set(const char* description ) {

		if (eventDescription != nullptr) {
			delete[] eventDescription;
			eventDescription = nullptr;
		}

		if (description != nullptr && description[0] != '\0') {
			eventDescription = new char[strlen(description) + 1];
			strcpy(eventDescription, description);
			startTime = g_sysClock;
		}
		else {
			startTime = 0;
		}
	}

	Event::~Event()
	{
		if (eventDescription != nullptr) {
			delete[] eventDescription;
			eventDescription = nullptr;
		}
	}
}