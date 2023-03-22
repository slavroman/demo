#include "Dog.h"

Dog::Dog(std::string name)
	: mName(name)
{
}

Dog::~Dog()
{
}

std::string Dog::getName()
{
	return mName;
}