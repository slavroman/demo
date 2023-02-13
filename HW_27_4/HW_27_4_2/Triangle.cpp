#include "Triangle.h"
#include <cmath>

Triangle::Triangle(double side)
	: mSideLength(side), mBisectrix(std::sqrt(3.0 * side) / 2.0)
{	
}

Triangle::~Triangle()
{
}

void Triangle::getSquare()
{
	mSquare = mSideLength * mSideLength * std::sqrt(3.0) / 4.0;
}
