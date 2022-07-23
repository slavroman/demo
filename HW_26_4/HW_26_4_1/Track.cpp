#include <iostream>
#include <string>
#include "Track.h"

Track::Track(std::string name	= "",
			 int day			= 0,
			 int month			= 0,
			 int year			= 0,
			 int lenght			= 0)
{
	m_name = name;
	m_date.tm_mday = day;
	m_date.tm_mon  = month;
	m_date.tm_year = year;
	m_lenght = lenght;
}

std::string Track::getTrackName()
{
	return m_name;
}

void Track::showTrack() const
{
	std::cout << "\nName  : " << m_name 
			  << "\nDate  : " << m_date.tm_mday << "/" << m_date.tm_mon << "/" << m_date.tm_year 
			  << "\nLenght: " << m_lenght << " sec.\n";
}