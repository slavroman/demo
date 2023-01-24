#pragma once

#include <string>
#include <vector>
#include <memory>

class Node
{
public:
	Node();

	void setName();
	void addNode(std::shared_ptr<Node>);
	void findInNode(std::string);

	std::string getName();
	std::shared_ptr<Node> getParrent();
	size_t getNeighboursCount();

	void printSubtree(const std::string&);
	void printTree();

private:
	std::string m_name;
	std::shared_ptr<Node> m_parrent;
	size_t m_neighboursCount;
	std::vector<std::shared_ptr<Node>> m_childNodes;
};

