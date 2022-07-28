#pragma once
#include <string>

class Phone
{
public:
	Phone();

	void set();
	void call(std::string) const;
	void sms(std::string) const;

private:	
	std::string m_data;
};

