#include "Triangle.h"
#include <cmath>

Triangle::Triangle(std::string name, std::string color, double side)
	: BaseFigure(name, color), mSideLength(side), mBisectrix(std::sqrt(3.0 * side) / 2.0)
{	
}

Triangle::~Triangle()
{
}

void Triangle::getSquare()
{
	mSquare = mSideLength * mSideLength * std::sqrt(3.0) / 4.0;
}

void Triangle::getBoundaryBox(const double factor)
{	
	mBoundaryHeight = mBisectrix + factor;
	mBoundaryWidth = mSideLength + factor;
}