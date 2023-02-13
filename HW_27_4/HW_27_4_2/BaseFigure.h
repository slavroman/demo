#pragma once
#include <string>
#include <vector>

class BaseFigure
{
public:
	BaseFigure();
	virtual ~BaseFigure();

	void setName(const std::string);
	void setColor(const size_t);
	void printFigure();	
	
	virtual void getSquare() = 0;
	

	std::string mType;	
	size_t mColor;
	double mSquare;
	//double mCenter; // x,y
};