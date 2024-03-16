#ifndef SENECA_COLLEGE_H
#define SENECA_COLLEGE_H

#include<vector>
#include<list>
#include"Person.h"

namespace seneca {
	class College {
		std::vector<Person*> m_persons;

	public:
		College() = default;
		~College();

		College(const College&) = delete;
		College& operator=(const College&) = delete;

		College& operator+=(Person* thePerson);
		void display(std::ostream& out) const;


		template<typename T>
		void select(const T& test, std::list<const Person*>& persons)
		{
			for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
			{
				if (test(*it))
				{
					persons.push_back(*it);
				}
			}
		}
	};
}

#endif // !SENECA_COLLEGE_H
