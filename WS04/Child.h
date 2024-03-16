#ifndef SENECA_CHILD_H
#define SENECA_CHILD_H
#include<string>
#include"Toy.h"
namespace seneca {

	class Child {
		std::string childName;
		int childAge;
		const Toy** toyObject;
		size_t mCount;              // Number of toys stored
		
		//private method to copy toys
		void copyToy(const Toy* toys[], size_t numofToys);

	public:
		Child(std::string name, int age, const Toy* toys[], size_t count);
		~Child();
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Child& child);
	};
}
#endif // !SENECA_CHILD_H
