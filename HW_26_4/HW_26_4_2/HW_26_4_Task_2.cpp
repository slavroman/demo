#include <iostream>
#include <string>
#include <regex>
#include "PhoneBook.h"
#include "Phone.h"

bool isPhoneNumberValid(const std::string&);

int main()
{
	std::cout << "Task 2.\n";

	PhoneBook phoneBook;
	Phone myPhone;

	std::string input = "";
	
	do
	{
		std::cout << "Please input a command:\n";
		std::cin >> input;

		while (input != "add" && input != "call" &&
			   input != "sms" && input != "exit")
		{
			std::cout << "The command is incorrect! Please try again:\n";
			std::cin >> input;
		}
		
		if (input == "add")
		{
			std::string name = "", number = "";

			std::cout << "Please input name:\n";
			std::cin >> name;

			std::cout << "Please input phone number (+7**********):\n";
			std::cin >> number;

			while (!isPhoneNumberValid(number))
			{
				std::cout << "Incorrect phone number, try again:\n";
				std::cin >> number;
			}

			phoneBook.addToPhonebook(name, number);
			//phoneBook.printPhonebook();
		}
		
		if (input == "call")
		{			
			input = phoneBook.getContact();

			if (!input.empty())
			{
				myPhone.call(input);
			}			
		}

		if (input == "sms")
		{
			input = phoneBook.getContact();
			
			if (!input.empty())
			{
				myPhone.set();
				myPhone.sms(input);
			}
		}

	} while (input != "exit");

	return 0;
}

bool isPhoneNumberValid(const std::string& number)
{
	// +7 <code> (3 digits) <number> (7 digits) like +7**********
	return std::regex_match(number, std::regex("^\\+7\\d{10}$"));
}