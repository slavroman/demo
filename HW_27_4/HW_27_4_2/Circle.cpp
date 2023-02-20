#include "Rectangle.h"
#include "Circle.h"
#include <iostream>

Circle::Circle(std::string name, std::string color, double radius)
    : BaseFigure(name, color, 0.0, 0.0), mRadius(radius)
{
}

Circle::~Circle()
{
}

void Circle::getSquare()
{
    mSquare = mRadius * mRadius * 3.14;
}

std::unique_ptr<Rectangle> Circle::getBoundaryBox()
{
    return std::make_unique<Rectangle>("", "", mRadius + mRadius, mRadius + mRadius);
}