#include "Node.h"
#include <iostream>
#include <ctime>

size_t randomInit(const size_t, const size_t);

int main()
{
	std::srand((size_t)std::time(nullptr));

	std::shared_ptr<Node> tree = std::make_shared<Node>();

	for (size_t i = 0; i < 2; ++i)
	{
		std::shared_ptr<Node> bigBranche = std::make_shared<Node>();
		bigBranche->setName();
		/*bigBranche->setParent(tree);*/

		for (size_t j = 0; j < 2; ++j)
		{
			std::shared_ptr<Node> middleBranche = std::make_shared<Node>();
			middleBranche->setName();
			/*middleBranche->setParent(bigBranche);*/
			bigBranche->addNode(middleBranche);
		}

		tree->addNode(bigBranche);
	}

	tree->printTree();

	std::cout << "\t\t-=Start find=-\n";

	tree->findInTree();

	return 0;
}

size_t randomInit(const size_t min, const size_t max)
{
	return (min + (rand() % static_cast<int>(max - min + 1)));
}