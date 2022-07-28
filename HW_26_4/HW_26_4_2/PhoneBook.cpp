#include <iostream>
#include <string>
#include <map>
#include "PhoneBook.h"

PhoneBook::PhoneBook()
	: m_userName(""), m_userPhoneNumber(""), m_foundContact(""), m_phoneBook()
{	
}

void PhoneBook::addToPhonebook(const std::string name, const std::string phone)
{
	if (searchInPhonebook(name))
	{
		std::cout << "This name already exists!\n";
	}
	else if (searchInPhonebook(phone))
	{
		std::cout << "This phone number already exists!\n";
	}
	else
	{
		m_userName = name;
		m_userPhoneNumber = phone;
		m_phoneBook.insert(std::pair<std::string, std::string>(m_userName, m_userPhoneNumber));

		std::cout << "Phone book entry added successfully!\n";
	}	
}

std::string PhoneBook::getContact()
{
	std::string userInput = "";

	std::cout << "Please input name or phone number (+7**********):\n";
	std::cin >> userInput;

	while (userInput.empty())
	{
		std::cout << "Empty input please try again:\n";
		std::cin >> userInput;
	}

	if (searchInPhonebook(userInput))
	{
		userInput = m_foundContact;		
	}
	else
	{		
		std::cout << "No such name or phone number found!\n";
		userInput = m_foundContact;
	}

	return userInput;
}

bool PhoneBook::searchInPhonebook(const std::string str)
{	
	for (auto it = m_phoneBook.begin(); it != m_phoneBook.end(); ++it)
	{
		if (it->first == str || it->second == str)
		{
			m_foundContact = it->first + " (" + it->second + ")";
			return true;
		}
	}

	m_foundContact = "";
	return false;
}

void PhoneBook::printPhonebook() const
{
	std::cout << "Phone Book:\n";
	for (const auto& v : m_phoneBook)
	{
		std::cout << v.first << ": " << v.second << "\n";
	}
	std::cout << "\n";
}
