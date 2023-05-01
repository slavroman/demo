#include "Toy.h"

Toy::Toy(std::string name = "Unknown")
	: m_name(name)
{
}

std::string Toy::getToyName()
{
	return m_name;
}
