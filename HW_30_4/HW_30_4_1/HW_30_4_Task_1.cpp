#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main()
{
	std::cout << "Task 1.\n";

	std::string input{};

	do
	{
		std::cout << "Please input a command (get, post, put, delete, patch or exit):\n";
		std::cin >> input;

		if (input == "get")
		{
			cpr::Response r = cpr::Get(cpr::Url{ "http://www.httpbin.org/get" });

			std::cout << "Returned Text:" << r.text << std::endl;
		}

		if (input == "post")
		{
			auto r = cpr::Post(cpr::Url{ "http://www.httpbin.org/post" },
							  cpr::Payload{ {"key", "value"} });

			std::cout << "Returned Text:" << r.text << std::endl;
		}

		if (input == "put")
		{
			auto r = cpr::Put(cpr::Url{ "http://www.httpbin.org/put" },
							  cpr::Payload{ {"key", "value"} });

			std::cout << "Returned Text:" << r.text << std::endl;
		}

		if (input == "delete")
		{
			auto r = cpr::Delete(cpr::Url{ "http://www.httpbin.org/delete" });

			std::cout << "Returned Status:" << r.status_code << std::endl;
			
		}

		if (input == "patch")
		{
			auto r = cpr::Patch(cpr::Url{ "http://www.httpbin.org/patch" },
							  cpr::Payload{ {"key", "value"} });

			std::cout << "Returned Text:" << r.text << std::endl;
		}		

	} while (input != "exit");

	return 0;
}