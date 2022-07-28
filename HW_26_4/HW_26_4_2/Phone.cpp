#include <iostream>
#include <sstream>
#include <string>
#include "Phone.h"

Phone::Phone()
	: m_data("")
{
}

void Phone::set()
{
	std::cin.ignore();
	std::string text;
	std::cout << "Please enter SMS text:\n";
	std::getline(std::cin, text);
	m_data = text;
}

void Phone::call(std::string str) const
{
	std::cout << "CALL to " << str << std::endl;
}

void Phone::sms(std::string str) const
{
	if (m_data.empty())
	{
		std::cout << "There is no text in the message!\n";
	}
	else
	{
		std::cout << "Sending SMS to " << str << std::endl;

		std::stringstream ss(m_data);
		std::string word;
		int wordCount = 0;

		while (ss >> word)
		{
			if (wordCount == 3)
			{
				std::cout << "\n";
				wordCount = 0;
			}

			std::cout << word << " ";
			wordCount++;
		}
		std::cout << "\n";
	}
}
