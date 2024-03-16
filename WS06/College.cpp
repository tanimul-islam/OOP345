#include <iostream>
#include <iomanip>
#include "College.h"
#include "Person.h"

using namespace std;
namespace seneca {
    College:: ~College() {
        // Clean up dynamically allocated Person objects
        for (Person* temp: m_persons) {
            delete temp;
        }
    }

    College& College::operator+=(Person* thePerson)
    {
        m_persons.push_back(thePerson);
        return *this;
    }

    void College::display(std::ostream& ostr) const
    {
        ostr << "------------------------------------------------------------------------------------------------------------------------" << endl;
        ostr << "|                                        Test #1 Persons in the college!                                               |" << endl;
        ostr << "------------------------------------------------------------------------------------------------------------------------" << endl;
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
        {
            (*it)->display(ostr);
            ostr << endl; // Use ostr for newlines
        }

        ostr << "------------------------------------------------------------------------------------------------------------------------" << endl;
        ostr << "|                                        Test #2 Persons in the college!                                               |" << endl;
        ostr << "------------------------------------------------------------------------------------------------------------------------" << endl;
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
        {
            ostr << "| " << setw(10) << (*it)->status() << "| " << setw(10) << (*it)->id() << "| " << setw(20) << (*it)->name()
                << " | " << setw(3) << (*it)->age() << " |\n";
        }

        ostr << "------------------------------------------------------------------------------------------------------------------------" << endl;
    }
}