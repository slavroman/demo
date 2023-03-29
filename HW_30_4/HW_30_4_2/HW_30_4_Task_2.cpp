#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main()
{
	std::cout << "Task 2.\n";

	cpr::Response r = cpr::Get(cpr::Url{ "http://www.httpbin.org/html" },
							   cpr::Header{ {"accept", "text/html"} });	
	
	std::string openHeader{ "<h1>" }, closeHeader{ "</h1>" };	

	auto posBegin = r.text.find(openHeader);
	auto posEnd   = r.text.find(closeHeader);	 
	
	if (posBegin != r.text.npos && posEnd != r.text.npos)
	{
		auto it = posBegin + openHeader.size();

		std::string res = r.text.substr(it, posEnd - it);

		std::cout << std::endl << res << std::endl;
	}	

	return 0;
}