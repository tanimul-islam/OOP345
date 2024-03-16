/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 17/01/2024
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H



namespace seneca {
	extern size_t g_sysClock;
	class Event {
		size_t startTime{ 0 };
		char* eventDescription{ nullptr };
	public:
		Event() {};
		Event(const Event& src);
		Event& operator = (const Event& src);
		void display() const;
		void set(const char* description = nullptr);
		~Event();
	};

}
#endif // SENECA_EVENT_H
