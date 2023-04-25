#include <iostream>
#include <string>
#include <map>
#include <list>
#include <cpr/cpr.h>

int main()
{
	std::cout << "Task 3.\n";

	std::string key{}, value{}, request{ "?" };
	std::map<std::string, std::string> arguments{};	

	do
	{		
		std::cout << "Type key:\n";
		std::cin >> key;

		if (key != "post" && key != "get")
		{
			std::cout << "Type value:\n";
			std::cin >> value;

			arguments.insert({ key, value });
		}

		if (!arguments.empty())
		{
			if (key == "post")
			{
				std::list<cpr::Pair> argList{};

				for (auto it = arguments.begin(); it != arguments.end(); it++)
				{
					cpr::Pair pair(it->first, it->second);
					argList.push_back(pair);
				}
				
				auto r = cpr::Post(cpr::Url{ "http://www.httpbin.org/post" },					
						 cpr::Payload{ argList.begin(), argList.end() });

				std::cout << "Returned Text:" << r.text << std::endl;
			}

			if (key == "get")
			{
				for (auto it = arguments.begin(); it != arguments.end(); it++)
				{
					request += it->first + '=' + it->second + '&';
				}

				request.pop_back(); // Remove last character '&' from string

				//std::cout << "\t\t\tREQUEST STRING: " << request << std::endl; // Uncomment for debug

				auto r = cpr::Get(cpr::Url{ "http://www.httpbin.org/get", request.c_str() });

				std::cout << "\nReturned Text:" << r.text << std::endl;
			}
		}
		else
		{
			std::cout << "\nKey and value are empty!!!\n";
		}		

	} while (key != "post" && key != "get");

	std::cout << "\n\t\t\t-= END OF PROGRAM =-\n";

	return 0;
}