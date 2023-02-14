#include "BaseFigure.h"
#include <iostream>

BaseFigure::BaseFigure(std::string name, std::string color)
	: mType(name), mColor(color), mSquare(0.0)/*, mCenter(0.0)*/
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