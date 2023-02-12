#include "Circle.h"
#include <iostream>

Circle::Circle(double radius)
    : mRadius(radius)
{
}

Circle::~Circle()
{
}

double Circle::getSquare()
{
    return mRadius * mRadius * 3.14;
}

void Circle::printFigure()
{
    std::cout << "Class name: " << mName << std::endl;
    std::cout << "Class color: " << mColor << std::endl;
    std::cout << "Class center: " << mCenter << std::endl;
}
