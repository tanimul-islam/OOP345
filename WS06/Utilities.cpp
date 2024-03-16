#include <iostream>
#include <sstream>
#include <string>

#include "Utilities.h"
#include "Employee.h"
#include "Student.h"
#include "Professor.h"

using namespace std;

namespace seneca
{

    Person* buildInstance(std::istream& in)
    {
        string str = "";
        char type = '\0';
        char comma = '\0';

        getline(in, str);
        str.erase(0, str.find_first_not_of(' '));
        stringstream sstr(str);
        sstr >> type >> comma;

        if (sstr) {
            switch (type)
            {
            case 'E':
            case 'e':
                return new Employee(sstr);
                break;
            case 'P':
            case 'p':
                return new Professor(sstr);
                break;
            case 'S':
            case 's':
                return new Student(sstr);
                break;
            default:
                break;
            }
        }
        return nullptr;
    }
}
