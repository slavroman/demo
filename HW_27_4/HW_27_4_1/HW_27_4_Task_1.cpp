#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include "branch.h"

size_t randomInit(size_t, size_t);

int main()
{
	std::srand((size_t)std::time(nullptr));

	const int treesCount = 5;

	Branch Tree[treesCount];

	for (size_t treeNumber = 0; treeNumber < treesCount; ++treeNumber)
	{
		Tree[treeNumber].setChildrensCount(randomInit(3, 5));
		
		for (size_t level1 = 0; level1 < Tree[treeNumber].getChildrensCount(); ++level1)
		{
			Branch* BigBranch = new Branch;

			BigBranch->setElfName();
			BigBranch->setParent(&Tree[treeNumber]);
			BigBranch->setChildrensCount(randomInit(2, 3));

			for (size_t level2 = 0; level2 < BigBranch->getChildrensCount(); ++level2)
			{
				Branch* MiddleBranch = new Branch;

				MiddleBranch->setElfName();
				MiddleBranch->setParent(BigBranch);
				BigBranch->addChild(MiddleBranch);
				BigBranch->setNeighbours(BigBranch->getNeighbours() + MiddleBranch->getNeighbours());
			}
			
			Tree[treeNumber].addChild(BigBranch);
		}		
	}

	return 0;
}

size_t randomInit(size_t min, size_t max)
{
    return (min + (rand() % static_cast<int>(max - min + 1)));
}