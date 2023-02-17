#include "BaseFigure.h"
#include <iostream>

BaseFigure::BaseFigure(std::string name, std::string color)
	: mType(name), mColor(color), mSquare(0.0), mBoundaryHeight(0.0), mBoundaryWidth(0.0)/*, mCenter(0.0)*/
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

void BaseFigure::printBoundaryFigure()
{
	std::cout << "\n  Name: outer rectangle"
		      << "\nHeight: " << mBoundaryHeight
		      << "\n Width: " << mBoundaryWidth
		      << std::endl;
}