#include "Node.h"
#include <iostream>

Node::Node()
	:m_name("None"), m_parrent(nullptr)
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
	}
}

void Node::addNode(std::shared_ptr<Node> object)
{
	m_childNodes.push_back(object);
}

std::string Node::getName()
{
	return m_name;
}

std::shared_ptr<Node> Node::getParrent()
{
	return m_parrent;
}

size_t Node::getChildNodesCount()
{
	return m_childNodes.size();
}
