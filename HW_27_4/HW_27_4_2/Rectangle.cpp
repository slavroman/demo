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

void Rectangle::getBoundaryBox(const double factor)
{
	mBoundaryHeight = mHeight + factor;
	mBoundaryWidth = mWidth + factor;
}