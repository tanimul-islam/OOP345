#include <iostream>
#include <iomanip>
#include "Professor.h"

namespace seneca
{
    Professor::Professor(std::istream& in) : Employee(in)
    {
        std::string temp;
        std::getline(in, temp, ',');
        m_department = temp.substr(temp.find_last_of(',') + 1); 
        m_department.erase(0, m_department.find_first_not_of(" \t\n\r\f\v")); 
    }

    void Professor::display(std::ostream& out) const
    {
        Employee::display(out);
        out << std::left << std::setw(10) << m_department << "| Professor";
    }

    std::string Professor::status() const
    {
        return "Professor";
    }

    std::string Professor::department() const
    {
        return m_department;
    } 

    Person* Professor::duplicate() const
    {
        return new Professor(*this);
    }
}