//#include"Toy.h"
#include "Shared_ptr_toy.h"
#include <iostream>

class Box
{
public:	
	Box()
		: length(0), width(0), height(0)
	{
	}

	int length, width, height;
};

int main()
{
	std::cout << "Task 1.\n";
		
	Shared_ptr_toy<Box> obj;
	std::cout << obj.getCount() << std::endl; // prints 0

	Shared_ptr_toy<Box> box1(new Box());
	std::cout << box1.getCount() << std::endl; // prints 1

	Shared_ptr_toy<Box> box2(box1); // calls copy constructor
	std::cout << box1.getCount() << std::endl; // prints 2
	std::cout << box2.getCount() << std::endl; // also prints 2

	return 0;
}