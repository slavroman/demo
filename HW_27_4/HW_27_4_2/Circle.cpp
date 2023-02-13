#include "Circle.h"
#include <iostream>

Circle::Circle(double radius)
    : mRadius(radius)
{
}

Circle::~Circle()
{
}

void Circle::getSquare()
{
    mSquare = mRadius * mRadius * 3.14;
}