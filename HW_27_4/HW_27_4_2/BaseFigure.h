#pragma once
#include <string>
#include <vector>
#include <memory>

class Rectangle;

class BaseFigure
{
public:	
	BaseFigure(std::string, std::string, double, double);
	virtual ~BaseFigure();
				
	virtual void getSquare() = 0;
	virtual std::unique_ptr<Rectangle> getBoundaryBox() = 0;
	void printFigure();

	std::string mType;	
	std::string mColor;
	double mSquare;
	double mHeight;
	double mWidth;
};