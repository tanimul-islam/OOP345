#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H

#include "Employee.h"

namespace seneca {
	class Professor : public Employee {
		std::string m_department;
	public:
		Professor(std::istream& in);
		void display(std::ostream& out) const override;
		std::string status() const override;
		std::string department() const;
		Person* duplicate() const;	
	};
}

#endif // !SENECA_PROFESSOR_H
