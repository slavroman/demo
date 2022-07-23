#pragma once
#include <iostream>
#include <string>

class Track
{
public:

	Track(std::string name, int day, int month, int year, int lenght);

	std::string getTrackName();
	void showTrack() const;

private:
	std::string m_name;
	tm m_date;
	int m_lenght;
};