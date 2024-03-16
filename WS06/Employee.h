#ifndef SENECA_EMPLOYEE_H
#define SENECA_EMPLOYEE_H

#include"Person.h"

namespace seneca {

	class Employee: public Person {
		std::string m_name{};
		int m_age = 0;
		std::string m_id{};
	public:
		Employee() {};
		Employee(std::istream& is);
		std::string status() const;
		std::string name() const;
		std::string id() const;
		std::string age() const;
		Person* duplicate() const;
		void display(std::ostream& out) const;
	};

}

#endif // !SENECA_EMPLOYEE_H
