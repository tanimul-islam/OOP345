/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 27/01/2024
Module Name: TimedEvents
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#pragma once
#ifndef SENECA_TIMEDEVENTS_H
#define SENECA_TIMEDEVENTS_H


#include <chrono>
#include <string>

namespace seneca {
	class TimedEvents
	{
		static const int maxEvents{ 10 }; //Maximum Number of events
		int numOfRecords{};
		//start and end time for event
		std::chrono::steady_clock::time_point t_startTime;
		std::chrono::steady_clock::time_point t_endTime;

		struct Event {
			std::string eventName;
			std::string eventTime;
			std::chrono::steady_clock::duration eventDuration;

			Event() : eventName(""), eventTime(""){}
		}events [maxEvents];

	public:
		TimedEvents() {};

		void startClock();
		void stopClock();
		void addEvent(const char* name);

		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& src);
	};

}
#endif // !SENECA_TIMEDEVENTS_H

