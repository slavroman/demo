#include "Rectangle.h"
#include "Triangle.h"
#include <cmath>

Triangle::Triangle(std::string name, std::string color, double side)
	: BaseFigure(name, color, 0.0, 0.0), mSideLength(side), mBisectrix(std::sqrt(3.0 * side) / 2.0)
{	
}

Triangle::~Triangle()
{
}

void Triangle::getSquare()
{
	mSquare = mSideLength * mSideLength * std::sqrt(3.0) / 4.0;
}

std::unique_ptr<Rectangle> Triangle::getBoundaryBox()
{
	return std::make_unique<Rectangle>("", "", mBisectrix, mSideLength);
}