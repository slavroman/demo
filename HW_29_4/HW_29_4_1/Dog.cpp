#include "Dog.h"
#include <iostream>

Dog::Dog(std::string name)
	: mName(name)
{
}

Dog::~Dog()
{
}

void Dog::showTalent()
{
}

void Dog::addTalent(std::shared_ptr<Talent> obj)
{
	mTalents.push_back(obj);
}

std::string Dog::getName()
{
	return mName;
}

void Dog::showTalents()
{
	if (mTalents.size() > 0)
	{
		std::cout << "This is " << mName << " and it has some talents:\n";

		for (auto& var : mTalents)
		{
			std::cout << "\tIt can ";
			var->showTalent();
		}

		std::cout << "\n";
	}	
}