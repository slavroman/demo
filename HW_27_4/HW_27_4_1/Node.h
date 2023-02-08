#pragma once

#include <string>
#include <vector>
#include <memory>

class Node
{
public:
	Node();
	virtual ~Node();

	void setName();
	/*void setParent(std::shared_ptr<Node>);*/
	void addNode(std::shared_ptr<Node>);	

	std::string getName();
	/*std::shared_ptr<Node> getParent();*/
	size_t getNeighboursCount();
	void findInTree(bool&, const std::string&);
	void printTree();

private:
	std::string m_name;
	/*std::shared_ptr<Node> m_parent;*/
	size_t m_neighboursCount;
	std::vector<std::shared_ptr<Node>> m_childNodes;
	
	void printSubtree(const std::string&);
};