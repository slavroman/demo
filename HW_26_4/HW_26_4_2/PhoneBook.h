#pragma once
#include <string>
#include <map>

class PhoneBook
{
public:
	PhoneBook();

	void addToPhonebook(const std::string, const std::string);
	std::string getContact();
	bool searchInPhonebook(const std::string);
	void printPhonebook() const;

private:
	std::string m_userName;
	std::string m_userPhoneNumber;
	std::string m_foundContact;
	std::map<std::string, std::string> m_phoneBook;
};

