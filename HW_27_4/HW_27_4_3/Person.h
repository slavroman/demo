#pragma once
#include <string>

class Person
{
public:
	Person(std::string);
	virtual ~Person();

protected:
	
	std::string mName;
	size_t mTask;
};