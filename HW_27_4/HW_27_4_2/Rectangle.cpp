#include "Rectangle.h"

Rectangle::Rectangle(double height, double width)
	: mHeight(height), mWidth(width)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::getSquare()
{
	mSquare = mHeight * mWidth;
}
