#pragma once
#include "BaseFigure.h"

class Rectangle :
    public BaseFigure
{
public:
    Rectangle(std::string, std::string, double, double);
    ~Rectangle();

    void getSquare() override;
    void printFigure() override;

private:
    double mHeight;
    double mWidth;
};

