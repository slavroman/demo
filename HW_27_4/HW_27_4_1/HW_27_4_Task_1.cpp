#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <memory>
#include "branch.h"

size_t randomInit(const size_t, const size_t);

int main()
{
	std::srand((size_t)std::time(nullptr));

	const size_t treesCount = 1; // do not forget to correct by 5
	Branch tree[treesCount];

	for (size_t itTree = 0; itTree < treesCount; itTree++)
	{
		for (size_t itBigBranch = 0; itBigBranch < randomInit(3, 5); itBigBranch++)
		{
			auto bigBranch = new Branch;
			bigBranch->setName();
			bigBranch->setParrent(&tree[itTree]);
			tree[itTree].addChild(bigBranch);

			for (size_t itMiddleBranch = 0; itMiddleBranch < randomInit(2, 3); itMiddleBranch++)
			{
				auto middleBranch = new Branch;
				middleBranch->setName();
				middleBranch->setParrent(bigBranch);
				bigBranch->addChild(middleBranch);
			}			
		}		
	}

	std::string elfNameToFind = "";
	std::cout << "Please input elf name to find:\n";
	std::cin >> elfNameToFind;
	size_t neighbours = 0;
	bool found = false;

	for (size_t itTree = 0; itTree < treesCount && !found; itTree++)
	{
		while (tree[itTree].getTopBranch())
		{
			neighbours += tree[itTree].getCountOfNonEmptyHousesOnBranch();

			if (tree[itTree].getName() == elfNameToFind)
			{
				found = true;
			}
			
		}

		if (found)
		{
			break;
		}
		
		neighbours = 0;
	}

	if (found)
	{
		std::cout << elfNameToFind << " has " << neighbours - 1 << " nieghbors.\n";
	}
	else
	{
		std::cout << "Elf not found.\n";
	}

	return 0;
}

size_t randomInit(const size_t min, const size_t max)
{
    return (min + (rand() % static_cast<int>(max - min + 1)));
}