#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(std::string name, std::string color, double height, double width)
	: BaseFigure(name, color), mHeight(height), mWidth(width)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::getSquare()
{
	mSquare = mHeight * mWidth;
}

void Rectangle::printFigure()
{
	if (mColor.empty())
	{
		std::cout << "\n  Name: " << mType
			      << "\nHeight: " << mHeight
			      << "\n Width: " << mWidth
			      << std::endl;
	}
	else
	{
		std::cout << "\n  Name: " << mType
			<< "\n Color: " << mColor
			<< "\nSquare: " << mSquare
			<< std::endl;

	}	
}