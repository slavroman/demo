#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(std::string name, std::string color, double height, double width)
	: BaseFigure(name, color, height, width)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::getSquare()
{
	mSquare = mHeight * mWidth;
}

std::unique_ptr<Rectangle> Rectangle::getBoundaryBox()
{
	return std::make_unique<Rectangle>("", "", mHeight, mWidth);
}

void Rectangle::printBoundaryFigure()
{
	std::cout << "\n  Name: outer rectangle"
		      << "\nHeight: " << mHeight
		      << "\n Width: " << mWidth
		      << std::endl;
}