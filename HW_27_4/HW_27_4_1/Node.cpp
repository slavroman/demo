#include "Node.h"
#include <iostream>

Node::Node()
	:m_name("None"), /*m_parent(nullptr),*/ m_neighboursCount(0)
{
}

Node::~Node()
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

//void Node::setParent(std::shared_ptr<Node> parrent)
//{
//	m_parent = parrent;
//}

void Node::addNode(std::shared_ptr<Node> object)
{
	m_childNodes.push_back(object);
}

std::string Node::getName()
{
	return m_name;
}

//std::shared_ptr<Node> Node::getParent()
//{
//	return m_parent;
//}

//size_t Node::getNeighboursCount()
//{
//	return m_neighboursCount;
//}

void Node::findInTree()
{
	std::string stringToFind = "";
	std::cout << "Please input elf name:\n";
	std::cin >> stringToFind;

	while (stringToFind.empty() && stringToFind == "None" && stringToFind == "none")
	{
		std::cout << "Incorrect input, please try again.\n";
		std::cin >> stringToFind;
	}

	findInSubtree(stringToFind);
	std::cout << "\n";
}

void Node::printTree()
{
	std::cout << m_name << "\n";
	printSubtree("");
	std::cout << "\n";
}

void Node::findInSubtree(const std::string& current)
{
	// TODO: need fix this function!!!

	if (m_childNodes.empty())
	{
		return;
	}

	size_t childrensCount = m_childNodes.size();

	for (size_t i = 0; i < childrensCount; ++i)
	{
		std::shared_ptr<Node> obj = m_childNodes[i];

		if (obj->m_name == current)
		{
			std::cout << "Elf " << current << " found and have " << obj->m_neighboursCount - 1 << " nieghbors\n";
			return;
		}
		else
		{
			if (obj->m_neighboursCount == 0)
			{
				std::cout << "Elf not found!\n";
				return;
			}

			obj->findInSubtree(current);
		}
	}
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