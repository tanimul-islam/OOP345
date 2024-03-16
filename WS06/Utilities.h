#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H
#include<iostream>
#include"Person.h"

namespace seneca {
	Person* buildInstance(std::istream& in);
}

#endif // !SENECA_UTILITIES_H
