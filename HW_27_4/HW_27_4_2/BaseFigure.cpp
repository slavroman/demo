#include "BaseFigure.h"
#include <iostream>

BaseFigure::BaseFigure()
	:mType("Unknown"), mColor(0), mSquare(0.0)/*, mCenter(0.0)*/
{
}

BaseFigure::~BaseFigure()
{
}

void BaseFigure::setName(const std::string name)
{
	mType = name;
}

void BaseFigure::setColor(const size_t color)
{
	mColor = color;
}

void BaseFigure::printFigure()
{
    std::cout << "Name: " << mType << std::endl;
    if (mColor != 0)
    {
        std::cout << "Color: " << mColor << std::endl;
    }
    std::cout << "Square: " << mSquare << std::endl;
}
