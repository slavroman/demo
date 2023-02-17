#include "Circle.h"
#include <iostream>

Circle::Circle(std::string name, std::string color, double radius)
    : BaseFigure(name, color), mRadius(radius)
{
}

Circle::~Circle()
{
}

void Circle::getSquare()
{
    mSquare = mRadius * mRadius * 3.14;
}

void Circle::getBoundaryBox(const double factor)
{
    mBoundaryHeight = mRadius + factor;
    mBoundaryWidth = mRadius + factor;
}