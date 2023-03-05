#pragma once
#include <string>

class Person
{
public:
	Person(std::string);
	virtual ~Person();

	std::string getPersonName();

protected:	
	std::string mName;
};