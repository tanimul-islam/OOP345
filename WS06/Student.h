#ifndef SENECA_STUDENT_H
#define SENECA_STUDENT_H

#include "Person.h"

namespace seneca {
	class Student : public Person {
		std::string m_name{};
		std::string m_id{};
		std::string* m_course{};
		int m_age = 0;
		int m_count = 0;
	public:
		Student() = default;
		~Student();

		Student(std::istream& in);
		std::string status() const;
		std::string name() const;
		std::string id() const;
		std::string age() const;

		Person* duplicate() const;
		void display(std::ostream& out) const;
	};
}

#endif // !SENECA_STUDENT_H
