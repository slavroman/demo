#include "Node.h"
#include <iostream>
#include <ctime>

size_t randomInit(const size_t, const size_t);

int main()
{
	std::cout << "Task 1.\n";

	std::srand((size_t)std::time(nullptr));

	std::vector<Node> trees(5);
	
	for (size_t i = 0; i < 5; ++i)
	{
		for (size_t j = 0; j < randomInit(3, 5); ++j)
		{
			std::shared_ptr<Node> bigBranche = std::make_shared<Node>();
			bigBranche->setName();
			/*bigBranche->setParent(tree);*/		

			for (size_t k = 0; k < randomInit(2, 3); ++k)
			{
				std::shared_ptr<Node> middleBranche = std::make_shared<Node>();
				middleBranche->setName();
				/*middleBranche->setParent(bigBranche);*/
				bigBranche->addNode(middleBranche);
			}

			trees[i].addNode(bigBranche);
		}
	}	

	// uncomment code below for DEBUG!!!

	/*for (size_t i = 0; i < trees.size(); ++i)
	{
		std::cout << "\nTree (" << i << ")\n";
		trees[i].printTree();
	}*/	

	std::cout << "\t\t-=Start find=-\n";
	
	std::string stringToFind = "";
	std::cout << "\nPlease input elf name to find:\n";
	std::cin >> stringToFind;

	while (stringToFind.empty())
	{
		std::cout << "The input couldn't be empty! Please try again.\n";
		std::cin >> stringToFind;
	}

	while (stringToFind == "None" || stringToFind == "none")
	{
		std::cout << "Incorrect input, please try again.\n";
		std::cin >> stringToFind;
	}

	bool found = false;

	for (size_t i = 0; i < trees.size(); ++i)
	{
		trees[i].findInTree(found, stringToFind);
	}	

	if (!found)
	{
		std::cout << "Elf not found!\n";
	}

	return 0;
}

size_t randomInit(const size_t min, const size_t max)
{
	return (min + (rand() % static_cast<int>(max - min + 1)));
}