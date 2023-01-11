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

	std::string getName();
	std::shared_ptr<Node> getParrent();
	size_t getChildNodesCount();

private:
	std::string m_name;
	std::shared_ptr<Node> m_parrent;
	std::vector<std::shared_ptr<Node>> m_childNodes;
};

