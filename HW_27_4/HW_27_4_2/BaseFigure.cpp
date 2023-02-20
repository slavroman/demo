#include "BaseFigure.h"
#include <iostream>

BaseFigure::BaseFigure(std::string name, std::string color, double height, double width)
	: mType(name), mColor(color), mSquare(0.0), mHeight(height), mWidth(width)
{
}

BaseFigure::~BaseFigure()
{
}

void BaseFigure::printFigure()
{
	std::cout << "\n  Name: " << mType
		      << "\n Color: " << mColor
		      << "\nSquare: " << mSquare
		      << std::endl;
}