#pragma once
#include <string>
#include <vector>

class BaseFigure
{
public:	
	BaseFigure(std::string, std::string);
	virtual ~BaseFigure();
				
	virtual void getSquare() = 0;
	virtual void printFigure();	

	std::string mType;	
	std::string mColor;
	double mSquare;
	//double mCenter; // x,y
};