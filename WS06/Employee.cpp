#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <cctype> 

#include "Person.h"
#include "Employee.h"

using namespace std;

namespace seneca
{
    Employee::Employee(std::istream& istr)
    {
        istr.ignore(5, ' ');

        std::getline(istr, m_name, ',');
        m_name.erase(0, m_name.find_first_not_of(" \t\n\r\f\v"));
        m_name.erase(m_name.find_last_not_of(" \t\n\r\f\v") + 1);

        istr >> m_age;

        if (!istr)
        {
            throw std::runtime_error(m_name + "++Invalid record!");
        }

        istr.ignore(10000, ',');

        std::getline(istr, m_id, ',');
        m_id.erase(0, m_id.find_first_not_of(" \t\n\r\f\v"));
        m_id.erase(m_id.find_last_not_of(" \t\n\r\f\v") + 1);

        if (m_id.empty() || m_id.front() != 'E')
        {
            throw std::runtime_error(m_name + "++Invalid record!");
        }
    }

    std::string Employee::status() const
    {
        return "Employee";
    }

    std::string Employee::name() const
    {
        return m_name;
    }

    std::string Employee::id() const
    {
        return m_id;
    }

    std::string Employee::age() const
    {
        return std::to_string(m_age);
    }

    Person* Employee::duplicate() const
    {
        return new Employee(*this);
    }

    void Employee::display(std::ostream& ostr) const
    {
        ostr << "| " << std::left << std::setw(10) << "Employee"
            << "| " << std::left << std::setw(10) << m_id
            << "| " << std::left << std::setw(21) << m_name
            << "| " << std::left << std::setw(3) << m_age << " |";
    }
}