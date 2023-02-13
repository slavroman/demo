#pragma once
#include "BaseFigure.h"

class Rectangle :
    public BaseFigure
{
public:
    Rectangle(double, double);
    ~Rectangle();

    void getSquare() override;

private:
    double mHeight;
    double mWidth;
};

