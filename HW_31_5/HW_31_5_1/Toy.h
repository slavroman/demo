#pragma once
#include <string>

class Toy
{
public:
	Toy(std::string);

	std::string getToyName();

private:
	std::string m_name;
};

