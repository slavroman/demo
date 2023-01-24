#include "Node.h"
#include <iostream>
#include <ctime>

size_t randomInit(const size_t, const size_t);

int main()
{
	

	std::srand((size_t)std::time(nullptr));

	std::shared_ptr<Node> tree = std::make_shared<Node>();

	std::shared_ptr<Node> bigBranche = std::make_shared<Node>();

	std::shared_ptr<Node> middleBranche = std::make_shared<Node>();

	tree->addNode(bigBranche);
	tree->addNode(bigBranche);
	tree->addNode(bigBranche);
	tree->addNode(bigBranche);

	bigBranche->addNode(middleBranche);
	bigBranche->addNode(middleBranche);
	bigBranche->addNode(middleBranche);

	tree->printTree();
	
	

	return 0;
}

size_t randomInit(const size_t min, const size_t max)
{
	return (min + (rand() % static_cast<int>(max - min + 1)));
}