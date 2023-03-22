#pragma once
#include <string>

class Dog
{
public:
	Dog(std::string);
	~Dog();

	std::string getName();

private:
	std::string mName;
};

