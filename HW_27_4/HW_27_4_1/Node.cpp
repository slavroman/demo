#include "Node.h"
#include <iostream>

Node::Node()
	:m_name("None"), m_parrent(nullptr), m_neighboursCount(0)
{
}

void Node::setName()
{
	std::string input = "";

	std::cout << "Please input elf name:\n";
	std::cin >> input;

	while (input.empty())
	{
		std::cout << "The name couldn't be empty! Please try again.\n";
		std::cin >> input;
	}

	if (input != "None" && input != "none")
	{
		m_name = input;
		m_neighboursCount++;
	}
}

void Node::addNode(std::shared_ptr<Node> object)
{
	m_childNodes.push_back(object);
}

void Node::findInNode(std::string name)
{
	if (m_name == name)
	{
		std::cout << "Elf " << m_name << " found and have " << m_neighboursCount << " neighbours.\n";
	}
}

std::string Node::getName()
{
	return m_name;
}

std::shared_ptr<Node> Node::getParrent()
{
	return m_parrent;
}

size_t Node::getNeighboursCount()
{
	return m_neighboursCount;
}

void Node::printTree()
{
	std::cout << m_name << "\n";
	printSubtree("");
	std::cout << "\n";
}

void Node::printSubtree(const std::string& prefix)
{
	if (m_childNodes.empty())
	{
		return;
	}

	std::cout << prefix;
	size_t childrensCount = m_childNodes.size();
	std::cout << ((childrensCount > 1) ? "|-----> " : "");

	for (size_t i = 0; i < childrensCount; ++i)
	{
		std::shared_ptr<Node> obj = m_childNodes[i];

		if (i < childrensCount - 1)
		{
			if (i > 0)
			{
				std::cout << prefix << "|-----> ";
			}

			bool printStrand = childrensCount > 1 && !obj->m_childNodes.empty();
			std::string newPrefix = prefix + (printStrand ? "|\t" : "\t");
			std::cout << obj->m_name << "\n";
			obj->printSubtree(newPrefix);
		}
		else
		{
			std::cout << (childrensCount > 1 ? prefix : "") << "------> ";
			std::cout << obj->m_name << "\n";
			obj->printSubtree(prefix + "\t");
		}
	}
}