#pragma once
#include <string>

class BaseFigure
{
public:
	BaseFigure();
	virtual ~BaseFigure();

	void setName(const std::string);
	void setColor(const size_t);
	
	virtual double getSquare() = 0;
	virtual void printFigure() = 0;

	std::string mName;	
	size_t mColor;
	double mCenter; // x,y
};