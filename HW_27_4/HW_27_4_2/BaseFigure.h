#pragma once
#include <string>
#include <vector>

class BaseFigure
{
public:	
	BaseFigure(std::string, std::string);
	virtual ~BaseFigure();
				
	virtual void getSquare() = 0;
	virtual void getBoundaryBox(const double) = 0;
	void printFigure();
	void printBoundaryFigure();

	std::string mType;	
	std::string mColor;
	double mSquare;
	double mBoundaryHeight;
	double mBoundaryWidth;
	//double mCenter; // x,y
};