#include "Dog.h"
#include <iostream>
#include <memory>

int main()
{
	std::cout << "Task 1.\n";

	std::shared_ptr<Talent> swim { std::make_shared<Swimming>() };
	std::shared_ptr<Talent> dance{ std::make_shared<Dancing>()  };
	std::shared_ptr<Talent> count{ std::make_shared<Counting>() };

	Dog dog("Steve");

	dog.addTalent(swim);
	dog.addTalent(dance);
	dog.addTalent(count);

	dog.showTalents();

	return 0;
}