#include "Swimmer.h"
#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <chrono>
#include <thread>
#include <ctime>

bool isAllSwam(std::vector<Swimmer>&);
void showRandomInfo(std::vector<Swimmer>&);
void printResult(std::vector<Swimmer>&);

int main()
{
	std::cout << "Task 1.\n";

	const auto swimmersCount{ 6 };

	std::srand((size_t)std::time(nullptr));	

	std::vector<Swimmer> swimmers;	

	for (size_t i = 0; i < swimmersCount; ++i)
	{
		std::string swimmerName{ "" };

		std::cout << "Please input swimmer #" << i + 1 << " name:\n";
		getline(std::cin, swimmerName);		

		double swimmerSpeed{ 0.0 };

		std::cout << "Please input swimmer #" << i + 1 << " speed:\n";
		std::cin >> swimmerSpeed;
		std::cin.clear();
		std::cin.ignore();

		Swimmer swimmer(swimmerName, swimmerSpeed);

		swimmers.push_back(swimmer);
	}
	
	std::vector<std::thread> threads;

	for (size_t i = 0; i < swimmersCount; ++i)
	{
		threads.push_back(std::thread(&Swimmer::setDistance, std::ref(swimmers[i])));
	}

	std::thread info(showRandomInfo, std::ref(swimmers));	

	for (auto& t : threads)
	{
		t.join();
	}

	
	info.join();

	printResult(swimmers);

	return 0;
}

bool isAllSwam(std::vector<Swimmer>& vec)
{
	for (auto& it : vec)
	{
		if (it.getDistance() < it.getTotalDistance())
		{
			return false;
		}
	}

	return true;
}

void showRandomInfo(std::vector<Swimmer>& infoVec)
{	
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	size_t min{ 0 }, max{ 5 };

	while (!isAllSwam(infoVec))
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		size_t idx = min + (rand() % static_cast<size_t>(max - min + 1));

		infoVec[idx].printSwimmerStatus();
	}
}

void printResult(std::vector<Swimmer>& sw)
{
	std::sort(sw.begin(), sw.end(), [](Swimmer& a, Swimmer& b)
	{
		return a.getTime() < b.getTime(); 
	});

	std::cout << "\n\t=== RESULTS table ===\n";	

	for (size_t i = 0; i < sw.size(); i++)
	{
		std::cout << "\t" << i + 1 << ". " << sw[i].getName() << "\tTime: ";
		std::cout.setf(std::ios::fixed);
		std::cout.precision(2);
		std::cout << sw[i].getTime() << std::endl;
	}
}