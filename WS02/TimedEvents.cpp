/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 27/01/2024
Module Name: TimedEvents
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#include<iostream>
#include<iomanip>
#include "TimedEvents.h"

using namespace std;

namespace seneca {




	void TimedEvents::startClock() {
		t_startTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		t_endTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* name)
	{
		if (numOfRecords < maxEvents) {
			if (name != nullptr || name[0] != '\0') {
				events[numOfRecords].eventName = name;
				events[numOfRecords].eventTime = "nanoseconds";//unit of time

				//calculate the duration
				events[numOfRecords].eventDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(t_endTime - t_startTime);
				++numOfRecords;
			}
			else {
				events[numOfRecords].eventName = "";
				events[numOfRecords].eventTime = "";
			}
		}
	}


	ostream& operator<<(ostream& os, const TimedEvents& src) {
		os << "--------------------------\nExecution Times:\n--------------------------\n";
		for (int i = 0; i < src.numOfRecords; ++i) {
			os << setw(21) << left << src.events[i].eventName;
			os << setw(13) << right << src.events[i].eventDuration.count();
			os << " " << src.events[i].eventTime << endl;
		}
		os << "--------------------------" << endl;

		return os;
	}

}