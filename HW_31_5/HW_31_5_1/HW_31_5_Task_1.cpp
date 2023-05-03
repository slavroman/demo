#include "Shared_ptr_toy.h"
//#include "Shared_ptr_toy_v2.h"
#include <iostream>
#include <string>

class Toy
{
public:
	Toy()
		: m_name("Unknown")
	{
	}

	Toy(std::string name)
		: m_name(name)
	{
	}

	void setName(std::string name)
	{
		m_name = name;
	}

	std::string getName()
	{
		return m_name;
	}

private:
	std::string m_name;
};

Shared_ptr_toy<Toy> make_shared_toy(std::string name)
{	
	Shared_ptr_toy<Toy> ptr(new Toy(name));	
	return ptr;
};

Shared_ptr_toy<Toy> make_shared_toy(Toy& toy)
{	
	Shared_ptr_toy<Toy> ptr(&toy);	
	return ptr;
};

int main()
{
	std::cout << "Task 1.\n";

	Toy bear("Bear");
		
	auto obj = make_shared_toy("Bone");
	std::cout << "Count of Shared_ptr_toy(" << obj->getName() << ")" << obj.getCount() << std::endl;

	auto obj2 = make_shared_toy(bear);
	std::cout << "Count of Shared_ptr_toy(" << obj2->getName() << ")" << obj2.getCount() << std::endl;
	
	auto obj3(obj2);
	std::cout << "Count of Shared_ptr_toy(" << obj2->getName() << ")" << obj2.getCount() << std::endl;
	std::cout << "Count of Shared_ptr_toy(" << obj3->getName() << ")" << obj3.getCount() << std::endl;


	return 0;
}