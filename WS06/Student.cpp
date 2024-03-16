#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <cctype> 

#include "Student.h"

using namespace std;

namespace seneca
{
    Student::Student(std::istream& istr)
    {
        istr.ignore(5, ' ');

        std::getline(istr, m_name, ',');
        m_name.erase(0, m_name.find_first_not_of(" \t\n\r\f\v"));
        m_name.erase(m_name.find_last_not_of(" \t\n\r\f\v") + 1);

        istr >> m_age;
        istr.ignore(10000, ',');
        if (istr.fail())
        {
            throw std::runtime_error(m_name + "++Invalid record!");
        }

        std::getline(istr, m_id, ',');
        m_id.erase(0, m_id.find_first_not_of(" \t\n\r\f\v"));
        m_id.erase(m_id.find_last_not_of(" \t\n\r\f\v") + 1);


        if (m_id.empty() || m_id.front() != 'S') {
            throw std::runtime_error(m_name + "++Invalid record!");
        }

        istr >> m_count;
        istr.ignore();
        if (istr.fail())
        {
            throw std::runtime_error(m_name + "++Invalid record!");
        }

        m_course = new std::string[m_count];
        for (int i = 0; i < m_count; ++i)
        {
            std::getline(istr, m_course[i], (i < m_count - 1) ? ',' : '\n');
            m_course[i].erase(0, m_course[i].find_first_not_of(" \t\n\r\f\v"));
        }
    }

    std::string Student::status() const
    {
        return "Student";
    }

    std::string Student::name() const
    {
        return m_name;
    }

    std::string Student::id() const
    {
        return m_id;
    }

    std::string Student::age() const
    {
        return std::to_string(m_age);
    }

    Person* Student::duplicate() const
    {
        return new Student(*this);
    }

    void Student::display(std::ostream& out) const
    {
        out << "| " << std::left << std::setw(10) << "Student"
            << "| " << std::left << std::setw(10) << m_id
            << "| " << std::left << std::setw(21) << m_name
            << "| " << std::left << std::setw(3) << m_age << " |";

        for (int i = 0; i < m_count; i++)
        {
            out << m_course[i];
            if (i != m_count - 1)
            {
                out << ", ";
            }
        }
    }

    Student::~Student()
    {
        delete[] m_course;
    }
}