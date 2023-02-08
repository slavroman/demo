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

	if (input == "None" || input == "none")
	{
		return;
	}	
	
	m_name = input;
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

size_t Node::getNeighboursCount()
{
	size_t idx = 0;

	for (std::vector<std::shared_ptr<Node>>::iterator it = m_childNodes.begin(); it != m_childNodes.end(); ++it)
	{
		if ((*it)->getName() != "None")
		{
			idx++;
		}		
	}	
	
	m_neighboursCount = idx;

	return m_neighboursCount;
}

void Node::findInTree(bool& found, const std::string& current)
{
	if (m_childNodes.empty() && m_name == current)
	{
		std::cout << "Elf " << m_name << " found and have " << m_neighboursCount << " neighbours.\n";
		found = true;
		return;
	}
	else
	{
		for (size_t i = 0; i < m_childNodes.size(); ++i)
		{
			std::shared_ptr<Node> target = m_childNodes[i];

			if (target->m_name == current)
			{
				std::cout << "Elf " << target->getName() << " found and have " << target->getNeighboursCount() << " neighbours.\n";
				found = true;
				return;
			}
			else
			{
				target->findInTree(found, current);
			}
		}
	}
}

void Node::printTree()
{
	std::cout << /*"Root"*/m_name << "\n";
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
		obj->getNeighboursCount();

		if (i < childrensCount - 1)
		{
			if (i > 0)
			{
				std::cout << prefix << "|-----> ";
			}

			bool printStrand = childrensCount > 1 && !obj->m_childNodes.empty();
			std::string newPrefix = prefix + (printStrand ? "|\t" : "\t");
			std::cout << obj->m_name << "(" << obj->m_neighboursCount << ")\n";
			obj->printSubtree(newPrefix);
		}
		else
		{
			std::cout << (childrensCount > 1 ? prefix : "") << "------> ";
			std::cout << obj->m_name << "(" << obj->m_neighboursCount << ")\n";
			obj->printSubtree(prefix + "\t");
		}
	}
}