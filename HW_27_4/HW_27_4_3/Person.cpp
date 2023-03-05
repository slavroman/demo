#include "Person.h"

Person::Person(std::string name)
	:mName(name)
{
}

Person::~Person()
{
}

std::string Person::getPersonName()
{
	return mName;
}
